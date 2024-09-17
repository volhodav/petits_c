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
} InputArray;

void add_word(InputArray *input_array, const char *word) {
    if (input_array->count < MAX_ARRAY_SIZE) {
        strncpy(input_array->words[input_array->count], word, WORD_SIZE);
        input_array->count++;
    } else {
        fprintf(stderr, "Deleter's word array is full\n");
        exit(1);
    }
}

void read_output_from_identiques(const char *command, InputArray *input_array) {
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to launch identiques");
        exit(EXIT_FAILURE);
    }

    char line[WORD_SIZE];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *colon_pos = strchr(line, ':');
        if (colon_pos != NULL) {
            *colon_pos = '\0';
            add_word(input_array, line);
        }
    }

    pclose(fp);
}

void remove_duplicates(const char *file_path, const InputArray *input_array, const char *output_file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    InputArray unique_words = { .count = 0 };
    char buffer[WORD_SIZE];
    int is_duplicate;

    while (fscanf(file, "%99s", buffer) == 1) {
        is_duplicate = 0;
        for (int i = 0; i < input_array->count; i++) {
            if (strcmp(buffer, input_array->words[i]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            add_word(&unique_words, buffer);
        } else {
            // Ensure at least one instance of each duplicate word is retained
            int already_added = 0;
            for (int j = 0; j < unique_words.count; j++) {
                if (strcmp(unique_words.words[j], buffer) == 0) {
                    already_added = 1;
                    break;
                }
            }
            if (!already_added) {
                add_word(&unique_words, buffer);
            }
        }
    }

    fclose(file);

    file = fopen(output_file_path, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < unique_words.count; i++) {
        fprintf(file, "%s", unique_words.words[i]);
        if (i < unique_words.count - 1) {
            fprintf(file, " ");
        }
    }

    fclose(file);
}

void print_help(const char *program_name) {
    printf("Usage: %s -iden /path/to/identiques -dup /path/to/duplicates -o /path/to/output\n", program_name);
    printf("Options:\n");
    printf("  -iden : the path to `identiques` program.\n");
    printf("  -dup  : the path to the file containing the duplicates.\n");
    printf("  -o    : the path to the output file.\n");
    printf("  -h    : display this help message.\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help(argv[0]);
        exit(0);
    }

    if (argc != 7) {
        fprintf(stderr, "Usage: %s -iden /path/to/identiques -dup /path/to/duplicates -o /path/to/output\n", argv[0]);
        exit(1);
    }

    const char *identiques_path = NULL;
    const char *duplicates_file_path = NULL;
    const char *output_file_path = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-iden") == 0) {
            identiques_path = argv[++i];
        } else if (strcmp(argv[i], "-dup") == 0) {
            duplicates_file_path = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file_path = argv[++i];
        }
    }

    if (!identiques_path || !duplicates_file_path || !output_file_path) {
        fprintf(stderr, "Invalid arguments! Use -h to reference help information\n");
        exit(1);
    }

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "%s %s", identiques_path, duplicates_file_path);

    InputArray input_array = { .count = 0 };
    read_output_from_identiques(command, &input_array);
    remove_duplicates(duplicates_file_path, &input_array, output_file_path);

    return 0;
}