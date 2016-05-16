# Introduction

This document describes the dependencies required to build this repository.
Instructions are given for __Ubuntu 14.04 LTS__ and dependencies for other distributions may vary.

# Building Codes

You can build all C programs by issuing `make` (or `make code`) in the top-level directory.
The package(s) needed for building java codes are listed below.

```
sudo apt-get install automake
sudo apt-get install gcc
```

# Building Documents

You can build all documents (as well as all C programs) by issuing `make docs` in the top-level directory.
The following packages are needed to successfully build all documents.

```
sudo apt-get install ghostscript
sudo apt-get install latex-beamer
sudo apt-get install pgf
sudo apt-get install python-pygments
sudo apt-get install texlive-latex-base
sudo apt-get install texlive-latex-extra
```

Please send [me](mailto:mail@ghorbanzade.com) a note in case you found a dependency not listed here.
