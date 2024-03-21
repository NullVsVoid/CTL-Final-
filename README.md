# CTL - C++ Template Library

CTL (C++ Template Library) is a collection of fundamental data structures and algorithms implemented
in C++ for educational and reference purposes.

## Table of Contents

- [Introduction](#introduction)
- [Directory Structure](#directory-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository contains a set of commonly used data structures and algorithms implemented in C++.
It serves as a resource for learning and understanding fundamental concepts in computer science and
software development.

## Directory Structure

The repository is structured as follows:

- **include**: Contains header files (.hpp) corresponding to the implementation files in the `src`
  directory.
- **src**: Contains the source files (.cpp) implementing various data structures and algorithms.

Within the `src` directory, the contents are further organized into subdirectories based on the
category of data structure or algorithm:

- **algorithms**: Implements common algorithms such as searching and sorting.
  - `search.cpp`
  - `sort.cpp`
- **binary_search_tree**: Implements a binary search tree and AVL tree.
  - `binary_search_tree.cpp`
  - `avl_tree.cpp`
- **graphs**: Implements graph data structures and algorithms.
  - `breadth_first_search.cpp`
  - `depth_first_search.cpp`
- **hashtable**: Implements a hashtable data structure.
  - `hashtable.cpp`
- **linked_list**: Implements various types of linked lists.
  - `single_linked_list.cpp`
  - `double_linked_list.cpp`
- **queue**: Implements a queue data structure.
  - `queue.cpp`
- **stack**: Implements a stack data structure.
  - `stack.cpp`

## Usage

To use this library, simply include the necessary header files from the `include` directory in your
C++ project. You can then instantiate and utilize the provided data structures and algorithms as
needed.

## Contributing

Contributions to this repository are welcome! If you have suggestions for improvements, bug fixes,
or new features, please feel free to open an issue or submit a pull request.

## License

This repository is licensed under the [MIT License](LICENSE).
