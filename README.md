# KBShellExt
Windows explorer extension for overlaying sync status icons

![Alt text](/KBShellExt.png?raw=true)

Once built and registered, for each file shown in explorer, this extension will look for a file of the same name ending in ".kbfs_status" and look for keywords at the top. If "public" or "private" followed by "syncing" or "synced" is found, the respective icon will be indicated to Explorer, which will overlay it on the regular icon for that file.

The COM server has to be registered like any other COM component, plus additionally a registry key has to be added under the following location for each icon (see kbshellext.rgs):
```
[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers\   KeybasePrivateSynced]
@="{[CLSID of COM server]]}"

```
The default value under each new key must represent the CLSID of its matching COM server.

Note that only 11 of these will be visible systemwide, so if you have tortoise GIT and one other product, for example, the slots will be full. They are chosen alphabetically, so you can add spaces to the start of each key until yours wins.

As demonstrated in demo\main.go, the shell can be notified to switch icons by calling `SHChangeNotify()`.