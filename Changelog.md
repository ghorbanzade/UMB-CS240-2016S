# Change Log

* Client-side view of course website is available at `gh-pages` branch.
* Successful build to master branch automatically deploys all generated
  documents to target website

## Version 1.2

Release Date: February 18, 2019

[GitHub Diff](https://github.com/ghorbanzade/umb-cs240-2016s/compare/v1.1...v1.1.1)

* Added support for building teaching materials via Docker.
  Since this repository is **not** under active development, the development
  environment is getting outdated.
  Providing Docker build support helps ensure continuous successful build
  of the materials.
* Updated author contact information and fixed outdated links.
* Added `Changelog.md`.

## Version 1.1

Release Date: June 16, 2016

[GitHub Diff](https://github.com/ghorbanzade/umb-cs240-2016s/compare/v1.0...v1.1)

* Directory structure is significantly improved and simplified.
* Simple top-level `make` command compiles all C codes, generates compressed
  files and creates all documents, making them ready to be deployed to course
  website.
* Assignments and their solutions are loaded from separate files which leads
  to better code organization and removes redundant codes.
* Section titles are added to lecture slides for easier lookup of a desired
  section.
* Instructions to build the documents from source code are documented.

## Version 1.0

Release Date: May 16, 2016
