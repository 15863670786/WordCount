#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int countCharacters(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        count += strlen(buffer);
    }
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    char *token;
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        token = strtok(buffer, " ,\t\n");
        while (token != NULL) {
            count++;
            token = strtok(NULL, " ,\t\n");
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    if (strcmp(option, "-c") == 0) {
        count = countCharacters(file);
        printf("Character count : %d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = countWords(file);
        printf("Word count : %d\n", count);
    } else {
        printf("Invalid option. Please use -c or -w.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
