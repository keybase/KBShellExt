// Copyright 2015 Keybase, Inc. All rights reserved. Use of
// this source code is governed by the included BSD license.

// +build windows

package main

import (
	"os"
    "io/ioutil"
	"syscall"
	"unsafe"    
    "fmt"
    
	"golang.org/x/sys/windows"
)

var (
	shell32DLL         = windows.NewLazySystemDLL("shell32.dll")
	shChangeNotifyProc = shell32DLL.NewProc("SHChangeNotify")
)

// Notify the shell that the thing located at path has changed
func notifyShell(path string) {
	shChangeNotifyProc.Call(
		uintptr(0x00002000), // SHCNE_UPDATEITEM
		uintptr(0x0005),     // SHCNF_PATHW
		uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr(path))),
		0)
}

func main() {
    if len(os.Args) < 3 {
        fmt.Print("Usage: demo target [public|private|none synced|syncing]")
    }

    status := os.Args[2]
    if len(os.Args) > 3 {
        status = status +  " " + os.Args[3] + "\n"
    }

    ioutil.WriteFile(os.Args[1] + ".kbfs_status", []byte(status), 0644)
    
    notifyShell(os.Args[1])
}