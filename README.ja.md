# EasyRemoteSSH

## 概要
VSCodeでのSSHを楽にするツールです。SSH先のリモート環境で`c`コマンドを実行すると、VSCode（またはCursorなど）の接続コマンドが自動的にクリップボードにコピーされます。これによりローカルマシンからリモート環境への接続が簡単に行えます。

## 前提条件
- ローカルマシンにVSCode（またはVSCodeのフォーク）がインストールされていること
- `code`コマンド（または`cursor`など）へのパスが通っていること
- [Remote SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)プラグインが導入されていること
- SSHでリモートサーバーに接続できる環境があること
  - .ssh/configの設定推奨

## セットアップ手順

### 1. リポジトリのクローン
リモートサーバーにSSH接続し、以下のコマンドを実行します：

```bash
git clone https://github.com/yi7242/EasyRemoteSSH.git
cd EasyRemoteSSH
```

### 2. 変数の設定
設定ファイルを自分の環境に合わせて編集してください：

```bash
# 設定ファイルを開く
nano config.sh

# 以下の変数を編集
remote_host="" # .ssh/configのHost
editor="code" # ローカルで使用するエディタコマンド（code, cursorなど）
```

### 3. パスを通す
以下のいずれかの方法でパスを通します：

#### 一時的に使用する場合
```bash
export PATH=$PATH:$(pwd)
```

#### 永続的に使用する場合
```bash
echo 'export PATH=$PATH:'"$(pwd)" >> ~/.bashrc
source ~/.bashrc
```


## 使用方法

### 基本的な使い方
リモートサーバー上で現在のディレクトリを開くには：

```bash
user@userserver:~/project$ c
code --remote ssh-remote+userserver /home/user/project
Copied to Clipboard!
```

この出力されたコマンドがクリップボードにコピーされるので、ローカルマシンで貼り付けて実行するだけです。

### 他のディレクトリを指定する場合
特定のディレクトリを指定するには：

```bash
user@userserver:~/project$ c ../
code --remote ssh-remote+userserver /home/user
Copied to Clipboard!
```