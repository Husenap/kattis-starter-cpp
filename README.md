# Kattis Starter C++

## Quick and easy setup for solving kattis problems using C++

This is a template that can be used to setup a private repository where you can start solving [kattis](https://open.kattis.com/) problems using C++. The setup includes:

* A script that downloads a problem's input files and prepares a C++ file for you based on the problem name.
* A script that tests your code locally against the test input.
* A script that automatically gathers and builds the files needed for submission using kattis' official python script.
* Support for sharing files between problems for common things such as types, utilities and data structures.
* GitHub Actions that test all your code and formats everything using clang-format on every push.
* Contains a few shared files for typenames, string splitting and math contants.

# Prerequisites

Before you start installing things, check what you have:
```sh
> gcc --version
> cmake --version
> python --version
> python3 --version
```
For the project to function, you need a few dependencies:
* A bash shell to run the scripts in
* A C++ compiler: GCC/MSVC/Clang
  * Ubuntu/WSL: Run `sudo apt update && sudo apt install build-essential`
  * Windows: [Install Visual Studio Community](https://visualstudio.microsoft.com/free-developer-offers/)
* [Install CMake](https://cmake.org/install/)
* You need to have Python or Python3
* Make sure you have the `.kattisrc` file in the `scripts/` directory, once you've signed in to kattis you can [get your personal file here](https://open.kattis.com/download/kattisrc). Read more [here](https://open.kattis.com/help/submit).

# Getting Started

### Generate the project
You only have to do this once.
It will take a minute to download the dependencies.
```sh
project_root> scripts/gen
```
### Run all tests
This will run all tests including unit tests for the shared files.
```sh
scripts/test
```

# Solving Kattis Problems

The name of a problem can be found in the URL of the problem (eg. `open.kattis.com/problems/[problem_name]`).

## Command Line

### Prepare a new problem
```sh
scripts/prepare [problem_name]
```
### Test a specific problem
```sh
scripts/test -R [problem_name]
```
### Submit a problem
```sh
scripts/submit [problem_name]
```

## VSCode Tasks

There are custom tasks in the repository that you can run in VSCode.
Open the Command Palette using <kbd>Ctrl+Shift+P</kbd> and choose `Tasks: Run Task`.
From there you will get 3 options:
* **Prepare Problem**: takes one input which is the problem name.
* **Test Problem**: runs the test script for the file that's currently opened in the editor.
* **Submit Problem**: runs the submit script for the file that's currently opened in the editor.

# Project Structure
```sh
├───.build                # CMake will generate and build the project here
├───.github
│   └───workflows         # Contains the Github Actions
├───.vscode               # Contains tasks and recommended extensions
├───cmake                 # Contains some files used by CMake
├───kattis
│   └───src
│       └───kattis
│           ├───problems  # This is where all your solutions will be
│           └───shared    # This is where you can place shared code
├───kattis_test
│   ├───input             # All downloaded test data will be here
│   └───src
│       └───shared        # Here you can write unit tests for the shared files
├───scripts               # Contains all the scripts
└───thirdparty            # Contains CMake code for getting dependencies
```

# Adding Shared Files
Here are the steps to adding a shared file and writing unit tests for it.
You can search for `shared_string` to get an idea of how everything works.

1. Create a new file in `kattis/src/kattis/shared/`, eg. `shared_tree.hpp`.
2. Add a path to your `.hpp` file in `kattis/CMakeLists.txt`.
3. Create a new file in `kattis_test/src/shared/`, eg. `shared_tree.cpp`.
4. Add a path to your `.cpp` file in `kattis_test/CMakeLists.txt`.
5. Run `scripts/gen` to regenerate the project.
6. Now you can start writing code.

# Known Issues

* It's currently not possible to read/write I/O using C-style `scanf/printf` because the local testing uses C++ streams.
