/*
* Name       : deleter
* Version    : 0.0.1
* this app will be reading the output that identiques provides and then going to the same file that identiqes has read and removing all the duplicate words that identiqus has found
*
* so for instance we are running the command as such
*
* $ ./deleter `./identiques ~/.tt/words/fr`
*
* deleter will launch identiques and will receive the output from identiques
* deleter will process the output by storing the list of words in an array that it has received from identiques
* deleter will then go through each word in the array, look for it in the file and delete all duplicates of that word leaving only one instance of the word
* deleter will then again go through all the words in the file making sure no duplicates are left
* deleter will then write the file back to the original file path
*
*
* @param file_path
* @return char*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

#define BUFFER_SIZE 124 * 1024 // 124 KB
#define MAX_ARRAY_SIZE 1024 // max size of the array that will store the words
#define WORD_SIZE 100 // max size of each word in an array

typedef struct {
    char words[MAX_ARRAY_SIZE][WORD_SIZE];
    struct Input *next;
    int count;
}InputArray;

void add_word(InputArray *input_array, const char *word) {
    if (input_array->count < MAX_ARRAY_SIZE)
    {
        strncpy(input_array->words[input_array->count], word, WORD_SIZE);
        input_array->count++;
    } else {
        fprintf(stderr, "Deleter's word array is full\n");
        exit(1);
    }
}

void read_output_from_identiques(const char *command, InputArray *input_array) {
    FILE *fp = fopen(command, "r");
    if (fp == NULL)
    {
        perror("Failed to launch identiques");
        exit(EXIT_FAILURE);
    }

    char line[WORD_SIZE];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *colon_pos = strchr(line, ':');
        if (colon_pos != NULL)
        {
            colon_pos = '\0';
            add_word(input_array, line);
        }
    }

    fclose(fp);

}

void remove_duplicates(const char *file_path, const InputArray *input_array) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    InputArray unique_words = { .count = 0 };
    char buffer[WORD_SIZE];
    int is_duplicate;

    while (fscanf(file, "%1023s", buffer) == 1)
    {
        is_duplicate = 0;
        for (int i = 0; i < input_array->count; i++)
        {
            if (strcmp(buffer, input_array->words[i]) == 0)
            {
                is_duplicate = 1;
                break;
            }
            
        }
        if (!is_duplicate)
        {
            add_word(&unique_words, buffer);
        } else {
            // Ensure at least one instance of each duplicate word is retained
            int already_added = 0;
            for (int j = 0; j < unique_words.count; j++)
            {
                if (strcmp(unique_words.words[j], buffer) == 0)
                {
                    already_added = 1;
                    break;
                }
            }
            if (!already_added)
            {
                add_word(&unique_words, buffer);
            }
        }
    }

    fclose(file);

    file = fopen(file_path, "w");
    if (file == NULL)
    {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < unique_words.count; i++)
    {
        fprintf(file, "%s\n", unique_words.words[i]);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    InputArray input_array = { .count = 0 };
    read_output_from_identiques(argv[1], &input_array);
    remove_duplicates("./identiques ~/.tt/words/fr2", &input_array);
    return 0;
}
