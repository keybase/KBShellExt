# KBShellExt
Windows explorer extension for overlaying sync status icons

![Alt text](/KBShellExt.png?raw=true)

Once built and registered, for each file shown in explorer, this extension will look for a file of the same name ending in ".kbfs_status" and look for a keyword inside it, at the top. If "syncing" or "synced" is found, the respective icon will be indicated to Explorer, which will overlay it on the regular icon for that file. (The icons used here are placeholders, borrowed from TortoiseGit.)

The COM server has to be registered like any other COM component (e.g. `regsvr32 KBShellExt.dll`, plus additionally a registry key has to be added under the following location for each icon:
```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers\   KeybaseSyncing
{81482F8D-ACFD-4719-92CF-0C27F10F0644}

HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers\   KeybaseSynced
{33576D3F-02E8-401C-8C0B-CE525E60C5D9}
```
The default value under each new key must represent the CLSID of its matching COM server.

Note that only 11 of these will be visible systemwide, so if you have tortoise GIT and one other product, for example, the slots will be full. They are chosen alphabetically, and the actual names don't matter, so you can add spaces to the start of each key until yours wins.

Testing shows that modifying the target file (not the status file) will cause Explorer to query the plugun for the overlay icon again and update it - hopefully this will be enough for production.
