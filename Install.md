### Introduction

This document describes the dependencies required to build this repository.
Instructions are given for __Ubuntu 14.04 LTS__ and dependencies for other distributions may vary.

### Dependencies

The package(s) needed for building source code are as follows.

```
sudo apt-get install automake
sudo apt-get install gcc
```

And the following is the list of packages required to build all documents.

```
sudo apt-get install ghostscript
sudo apt-get install latex-beamer
sudo apt-get install pgf
sudo apt-get install python-pygments
sudo apt-get install texlive-latex-base
sudo apt-get install texlive-latex-extra
```

### Build Instructions

All source code and documents can be build by issuing `make` in the top-level directory.
If you wish to build source code only, issue `make code`.
Similarly, if you intend to build only the documents, you can run `make docs`.

Please send [me](mailto:mail@ghorbanzade.com) a note in case you found a dependency not listed here.
