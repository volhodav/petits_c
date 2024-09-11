# Identiques

## Description

A small c program that reads the file that is given to it like `$ identiques ./files/words` and looks for identical words in the file. It then prints out the words that are identical and the number of times they appear in the file. The program uses system calls [`open`], [`read`],[`close`] instead of standard library functions.

## Features

1. **Reads the file given as a command-line argument**:
   - The program checks if the correct number of arguments is provided.
   - It opens the file using `open()`.

2. **Looks for identical words**:
   - The program reads the file content using `read()`.
   - It tokenizes the content into words and counts their occurrences using a linked list.

3. **Prints out the words that are identical and the number of times they appear**:
   - The [`print_word_counts`] function prints words that appear more than once along with their counts.

4. **Uses system calls**:
   - The program uses `open()`, `read()`, and `close()` system calls instead of standard library functions like `fopen()`, `fread()`, and `fclose()`.

## How to compile

You can compile the program using `gcc`:

```sh
make
```

## How to run

You can run the program with a file as an argument:

```sh
./identiques /path/to/your/file
```

