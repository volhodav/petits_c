[Back to the Project List](../README.md)

# empty_line_remover

## Description

`empty_line_remover` is a small C program that removes empty lines from a given file. It reads the content of the file, processes it to remove any empty lines, and then writes the cleaned content back to the file.

## Features

1. **Reads the file given as a command-line argument**:
    - The program checks if the correct number of arguments is provided.
    - It opens the file using `fopen()`.

2. **Removes empty lines**:
    - The program reads the file content using `fread()`.
    - It processes the content to remove any empty lines.
    - It writes the cleaned content back to the file using `fwrite()`.

3. **Error handling**:
    - The program handles errors related to file operations and memory allocation.

## How to compile

You can compile the program using `gcc`:

```sh
gcc -o empty_line_remover main.c
```

## How to run

You can run the program with a file as an argument:

```sh
./empty_line_remover /path/to/your/file
```

## Example

To remove empty lines from a file named example.txt, you would run:

```sh
./empty_line_remover example.txt
```

[Back to the Project List](../README.md)