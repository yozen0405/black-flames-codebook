# Black flames codebook

forked from [https://github.com/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook.git]()

## For Mac

```bash
docker build -t latex-build .
docker run --rm -v "$(pwd)":/usr/src/app latex-build
```

## For Windows

```bash
docker build -t latex-build .
docker run --rm -v %cd%:/usr/src/app latex-build
```