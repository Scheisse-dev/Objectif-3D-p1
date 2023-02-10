Param(
    [parameter()]
    [String]$path
)

powershell.exe -ExecutionPolicy Bypass -File RegisterProperty.ps1 -path $path
powershell.exe -ExecutionPolicy Bypass -File RegisterMethod.ps1 -path $path
powershell.exe -ExecutionPolicy Bypass -File Assemblie.ps1 -path $path