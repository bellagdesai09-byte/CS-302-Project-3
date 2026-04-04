# CS 302 - Project 3: Music Library

## Overview
Hey! This is my submission for Project 3. It's a custom-built, templated Binary Search Tree (BST) that I'm using to manage a library of `Song` objects. The project covers dynamic memory management, recursive traversals (Inorder, Preorder, and Postorder), and a pretty heavy `remove` algorithm that handles all three edge cases (leaves, one child, and two children).

## File Setup
* `include/` - This has all my header files (`.h`), including the class definitions and the template logic.
* `src/` - This has all the actual C++ implementation files, plus my `driver.cpp` test file.
* `build/` - You don't need to touch this; the Makefile will create it automatically to hold the compiled stuff.

## How to Run It
I included a `Makefile` so you don't have to type out the massive `g++` commands. Just make sure your terminal is in the main project folder and run:

1. `make clean` (Just to clear out any old compiled files).
2. `make run` (This compiles the whole project and immediately runs the executable).