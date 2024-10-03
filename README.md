# Get Next Line - 42 Project

[![Get Next Line - 42 Project](https://img.shields.io/badge/Get%20Next%20Line-42Project-blue)](https://www.42.fr/)

## Table of Contents

- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Features](#features)
- [Function Prototype](#function-prototype)
- [Important Notes](#important-notes)

## Introduction

**Get Next Line (GNL)** is a project from the 42 school curriculum designed to develop a deeper understanding of file reading in C. The goal is to create a function that reads a line from a file descriptor, handling both memory management and edge cases effectively.

## Project Overview

The **Get Next Line** project focuses on reading content from a file or input stream, one line at a time. This function will serve as a foundation for more complex input handling in future projects. You are tasked with writing a function that returns the next line from a file descriptor each time it is called.

## Features

- Read from any file descriptor, including standard input (stdin).
- Handles multiple file descriptors simultaneously.
- Efficient memory usage with buffers.
- Customizable buffer size.
- Handles different line-ending conventions.

## Function Prototype

The core of the project is the `get_next_line` function:

```c
char *get_next_line(int fd);
```

Parameters:

int fd: The file descriptor to read from.
 ### Return Value:
 
char *: The function returns a line read from the file descriptor. The line includes the terminating newline character, except for the last line if it doesn’t end with a newline.
Returns NULL if there are no more lines to read, or in case of an error.
