[Retour à la Liste des Projets](../README.md)

# Deleter

## Description

`Deleter` is a small C program that reads the output from the `identiques` program and removes all duplicate words from the specified file, leaving only one instance of each word. The program processes the output by storing the list of words in an array and then goes through each word in the array, looking for it in the file and deleting all duplicates.

## Features

1. **Reads the output from `identiques`**:
    - The program launches `identiques` and works through its output.
    - It stores the list of unique words in an array.

2. **Removes duplicate words**:
    - The program goes through each word in the array and looks for it in the file.
    - It deletes all duplicates of that word, leaving only one instance.
    - It assures that at least one instance of each duplicate word is retained.

3. **Writes the updated content back to the file**:
    - The program writes the updated content to output file specified by the user as an argument in the command line

## Example of the run command :

there are 3 arguments to pass to the program:
- `-iden` : the path to `identiques` program.
- `-dup` : the path to the file containing the duplicates.
- `-o` : the path to the output file.

```sh 
./deleter --iden /path/to/identiques --dup /path/to/duplicates/file -o /path/to/output/file
```

## How to compile

You can compile the program using `gcc`:

```sh
make
```

[Retour à la Liste des Projets](../README.md)