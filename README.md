# Black flames codebook

forked from [https://github.com/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook.git]()

## Setup

首先，先把專案 clone 下來。

```terminal
git clone https://github.com/yozen0405/black-flames-codebook.git
```

接著進去該資料夾

```
cd black-flames-codebook
```

然後開啟 docker 這個 app，再根據你電腦的類型，執行以下動作：

### For Mac

```bash
docker build -t latex-build .
docker run --rm -v "$(pwd)":/usr/src/app latex-build
```

### For Windows

先 build docker images

```bash
docker build -t latex-build .
```

之後要執行時，跑以下指令（此後每次更改後也只要執行這個指令即可）：

```bash
docker run --rm -v %cd%:/usr/src/app latex-build
```

## How to edit

編輯或新增 code 的話，進去 codes 這個資料夾編輯就好了。