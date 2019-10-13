#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void printHelp() {
    printf("\n\t./rot13 [fileName]\n\n");
}

int isHelp(char *option) {
    return (option == "-h" || option == "--help");
}

char *readFile(char *fileName) {
    FILE *fptr = fopen(fileName, "r");
    char *fileContent;
    int c;
    int size = 0;

    if (fptr == NULL)
        return "Problem reading file\n";

    while ((c = getc(fptr)) != EOF) {
        fileContent[size] = c;
        size++;
        fileContent = realloc(fileContent, size + 1);
    }

    fileContent[size] = '\0';
    printf("%s", fileContent);
    fclose(fptr);
    return fileContent;
}

char *encrypt(char *fileContent) {
    for (int index = 0; index < strlen(fileContent); index++) {
        if (islower(fileContent[index])) {
            if (fileContent[index] >= 'a' && fileContent[index] <= 'm')
                fileContent[index] += 13;
            else
                fileContent[index] -= 13;
        } else if (isupper(fileContent[index])) {
            if (fileContent[index] >= 'A' && fileContent[index] <= 'M')
                fileContent[index] += 13;
            else
                fileContent[index] -= 13;
        }
    }
    return fileContent;
}

void writeToFile(char *encryptedText) {
    char *outputFileName = "output";
    FILE *fptr = fopen(outputFileName, "w");
    if (fptr == NULL) {
        fclose(fptr);
        return;
    }
    fputs(encryptedText, fptr);
    fclose(fptr);
}

void process(char *fileName) {
    char *fileContent = readFile(fileName);
    if (fileContent != "Problem reading file\n") {
        writeToFile(encrypt(fileContent));
        free(fileContent);
    } else
        printf("%s",fileContent);
}

int main(int argc, char **argv) {
    switch (argc) {
        case 1:
            printHelp();
            break;
        case 2:
            if (isHelp(argv[1]))
                printHelp();
            else
                process(argv[1]);
            break;
        default:
            printf("\nInvalid Prameters\n");
            break;
    }
}