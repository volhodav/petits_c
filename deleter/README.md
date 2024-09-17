[Retour à la Liste des Projets](../README.md)

# Deleter

## Description

`Deleter` is a small C program that reads the output from the `identiques` program and removes all duplicate words from the specified file, leaving only one instance of each word. The program processes the output by storing the list of words in an array and then goes through each word in the array, looking for it in the file and deleting all duplicates.

## Features

1. **Reads the output from `identiques`**:
    - The program launches `identiques` and reads its output.
    - It stores the list of words in an array.

2. **Removes duplicate words**:
    - The program goes through each word in the array and looks for it in the file.
    - It deletes all duplicates of that word, leaving only one instance.
    - It ensures that at least one instance of each duplicate word is retained.

3. **Writes the updated content back to the file**:
    - The program writes the file back to the original file path after removing duplicates.

## How to compile

You can compile the program using `gcc`:

```sh
make
```

## How to run

You can run the program with the output file from `identiques` as an argument:

```sh 
./deleter ./identiques /path/to/your/file
```

[Retour à la Liste des Projets](../README.md)