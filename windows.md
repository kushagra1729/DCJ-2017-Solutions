# Setup for windows
Follow these instructions to use distributed code jam tool on windows.
## Setting up Ubuntu WSL (Windows Subsystem for Linux)
* Open `powershell` as **Administrator** and run the following command:
```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```
* Restart your computer if prompted
* Install [Ubuntu WSL](https://www.microsoft.com/store/productId/9N9TNGVNDL3Q) from Microsoft Store

## Installing DCJ Tools and dependencies
* Open `Ubuntu 18.04` Application and run the following commands: (Use Right-Click to paste into ubuntu cmdline)
* Set the username and password if prompted
```bash
sudo apt-get update
sudo apt-get install python2.7 g++
cd $HOME
wget "https://code.google.com/codejam/contest/static/dcj_linux.tar.bz" -O dcj_linux.tar.bz
bzip2 -d dcj_linux.tar.bz
(mkdir -p dcj && cd dcj && tar -xvf ../dcj_linux.tar)
echo "alias dcj=\"$HOME/dcj/dcj.sh\"" > $HOME/.bash_aliases
source $HOME/.bash_aliases
```

## Workshop files

[Clone](https://github.com/kushagra1729/DCJ-2017-Solutions) or [download](https://github.com/kushagra1729/DCJ-2017-Solutions/archive/master.zip) workshop files from windows.

## Building and Running DCJ C++ Programs
The build and run commands are the same as that of linux in the guide.

**Note**:
* In WSL, drive `X:\` is accessbile at `/mnt/x`
* Build sources, run programs and generate header datasets using Ubuntu WSL
* Edit your C++ code using an editor on Windows