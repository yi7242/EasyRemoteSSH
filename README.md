# EasyRemoteSSH
[日本語README](README.ja.md)


## Overview
This is a tool to make SSH connections easier with VSCode. When you run the `c` command in a remote SSH environment, the VSCode (or Cursor, etc.) connection command is automatically copied to your clipboard. This makes connecting from your local machine to the remote environment simple.

## Prerequisites
- VSCode (or a VSCode fork) installed on your local machine
- Path to the `code` command (or `cursor`, etc.) is properly set
- [Remote SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh) plugin is installed
- SSH connection to a remote server is available
  - Properly configured `~/.ssh/config` file on your local machine to establish the SSH connection
  
## Setup Instructions

### 1. Clone the Repository
Connect to your remote server via SSH and run the following commands:

```bash
git clone https://github.com/yi7242/EasyRemoteSSH.git
cd EasyRemoteSSH
```

### 2. Configure Variables
Edit the configuration file to match your environment:

```bash
# Open the config file
nano config.sh

# Change the following variables
remote_host="" # Host name in .ssh/config 
editor="code" # Local editor command (code, cursor, etc.)
```

### 3. Add to PATH
Add the script to your PATH using one of these methods:

#### Temporary Use
```bash
export PATH=$PATH:$(pwd)
```

#### Permanent Use
```bash
echo 'export PATH=$PATH:'"$(pwd)" >> ~/.bashrc
source ~/.bashrc
```

## Usage

### Basic Usage
To open the current directory on the remote server:

```bash
user@userserver:~/project$ c
code --remote ssh-remote+userserver /home/user/project
Copied to Clipboard!
```

The displayed command is copied to your clipboard, so you only need to paste and execute it on your local machine.

### Specifying Another Directory
To specify a different directory:

```bash
user@userserver:~/project$ c ../
code --remote ssh-remote+userserver /home/user
Copied to Clipboard!
``` 