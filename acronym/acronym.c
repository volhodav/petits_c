/*
 * AUTHOR : pmnv
 * date :  31/10/2023
 *
 * nom : acronym
 * Description : ce program peut ouvrir un fichier et lire son contenu et cree les acronymes de chaque phrase
 * pour exemple : Hello World! => HW! ou Hello World. => HW.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// ici on definit la taille de la chaine de caractere pour le buffer
#define BUFFER_SIZE 1024

// struct pour les acronymes
typedef struct {
    char acronym[BUFFER_SIZE];
    int accros_trouve;
} Acronym;

// fonction pour lire le fichier
char *read_file(char *filename) {
    // on ouvre le fichier en mode lecture
    FILE *file = fopen(filename, "r");
    // si le fichier n'existe pas on affiche un message d'erreur
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    // on cree un buffer pour stocker le contenu du fichier
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    size_t num_read = fread(buffer, sizeof(char), BUFFER_SIZE - 1, file);

    buffer[num_read] = '\0'; //

    // on ferme le fichier
    fclose(file);
    // on retourne le buffer
    return buffer;
}

// fonction pour afficher les contenus du buffer
void print_buffer(char *buffer) {
    // on affiche le contenu du buffer
    printf("Buffer:\n");
    printf("-------\n");
    printf("%s\n", buffer);
}

// on traverse le buffer et on cree les acronymes
Acronym *cree_acronym(char *buffer) {
    Acronym *acronym = malloc(sizeof(Acronym));

    if (acronym == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    acronym->accros_trouve = 0;

    int i = 0, j = 0;

    acronym->acronym[j++] = toupper(buffer[i++]); // on prend la premiere lettre de la phrase et on la met en majuscule



    // nous allons parcourir le strucutre et cree les acronymes en prenant la premiere lettre de chaque mot
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ' && isalpha(buffer[i+1])) {
            acronym->acronym[j++] = toupper(buffer[i+1]);
        } else if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?') {
            acronym->acronym[j++] = buffer[i];
            acronym->acronym[j++] = ' ';
            acronym->accros_trouve++;
        }
        i++;
    }

    acronym->acronym[j] = '\0'; // on met le caractere de fin de chaineÒ
    return acronym;
}

// fonction pour afficher les acronymes
void print_acronym(Acronym *acronym) {
    // on affiche les acronymes
    printf("Acronym:\n");
    printf("-------\n");
    printf("%s\n", acronym->acronym);
}

// fonction principale
int main(int argc, char *argv[]) {
    char *buffer = read_file(argv[1]); // on lit le fichier
    print_buffer(buffer); // on affiche le contenu du fichier
    Acronym *acronym = cree_acronym(buffer); // on cree les acronymes
    print_acronym(acronym); // on affiche les acronymes
    free(buffer); // on libere le buffer
    free(acronym); // on libere le strucutre
    return 0;
}
