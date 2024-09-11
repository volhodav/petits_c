# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<unistd.h>
# include<fcntl.h>
# include<sys/stat.h>
# include<sys/types.h>
# include<string.h>


# define FILE_BUFFER 124 * 1024 // 124kb buffer should be enough for most text files
# define WORD_SIZE 100 // 100 characters should be enough for most words


typedef struct WordCount {
    char word[WORD_SIZE];
    int count;
    struct WordCount *next;
} WordCount;

WordCount* add_word(WordCount *head, const char *word) {
    WordCount *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
        {
            current->count++;
            return head;
        }
        current = current->next;
    }

    WordCount *new_word = (WordCount *)malloc(sizeof(WordCount));
    if (new_word == NULL)
    {
        perror("malloc");
        exit(1);
    }
    strcpy(new_word->word, word);
    new_word->count = 1;
    new_word->next = head;
    return new_word;
}

void print_word_counts(WordCount *head) {
    WordCount *current = head;
    while (current != NULL)
    {
        if (current->count > 1)
        {
            printf("%s: %d\n", current->word, current->count);
        }
        // printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}
void free_word_counts(WordCount *head) {
    WordCount *current = head;
    while (current != NULL)
    {
        WordCount *next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        write(STDERR_FILENO, "Usage : identiques <filename>\n", 29);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[FILE_BUFFER];
    ssize_t bytesRead;
    WordCount *word_counts = NULL;
    char word[WORD_SIZE];
    int word_index = 0;

    while ((bytesRead = read(fd, buffer, FILE_BUFFER)) > 0)
    {
        for (size_t i = 0; i < bytesRead; i++)
        {
            if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
            {
                if (word_index > 0)
                {
                    word[word_index] = '\0';
                    word_counts = add_word(word_counts, word);
                    word_index = 0;
                }
            } else {
                if (word_index < WORD_SIZE - 1) {
                    word[word_index++] = buffer[i];
                }
            }
        }
    }


    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    if (word_index > 0) {
        word[word_index] = '\0';
        word_counts = add_word(word_counts, word);
    }

    print_word_counts(word_counts);
    free_word_counts(word_counts);

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}