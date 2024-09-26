# **get_next_line** - Reading a Line from a File Descriptor

## Overview

**get_next_line** is a project in the [42 Network](https://www.42.fr/) curriculum that challenges students to create a function capable of reading one line at a time from a file descriptor, regardless of the buffer size. This project is key in mastering file input handling and dynamic memory allocation in C.

## Table of Contents

- [Overview](#overview)
- [Function Prototype](#function-prototype)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)

## Function Prototype

```c
char *get_next_line(int fd);
```


- **Parameters**:
  - `fd`: The file descriptor from which to read.
  
- **Return**:
  - Returns a line read from the file descriptor, including the newline (`\n`) character if it exists.
  - Returns `NULL` when there's nothing more to read or in case of an error.

## Project Structure

get_next_line/
│
├── Makefile
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
└── README.md

- **get_next_line.c**: The main function that handles reading and returning lines.
- **get_next_line_utils.c**: Utility functions needed for `get_next_line` to work.
- **get_next_line.h**: The header file that contains function prototypes and necessary definitions.
- **Makefile**: Used for compiling the project.

## How It Works

The **get_next_line** function reads a file descriptor one line at a time, handling:
- Reading the file chunk by chunk (using a user-defined buffer size).
- Storing and managing any leftover data between calls.
- Returning each complete line as it's read, including the newline character (`\n`).
- Freeing memory and returning `NULL` when no more lines are available.

Key points:
- **BUFFER_SIZE**: This is defined when compiling the project and determines how many bytes to read at a time.
- **Static variables**: Used to retain the leftover part of the read buffer between function calls.
