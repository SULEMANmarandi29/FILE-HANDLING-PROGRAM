#include <stdio.h>
#include <stdlib.h>

void create_file(const char *filename) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error! Could not create file '%s'\n", filename);
        return;
    }
    fclose(fptr);
    printf("Successfully created file '%s'\n", filename);
}

void write_to_file(const char *filename, const char *content) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error! Could not write to file '%s'\n", filename);
        return;
    }
    fprintf(fptr, "%s", content);
    fclose(fptr);
    printf("Successfully written content to file '%s'\n", filename);
}

void append_to_file(const char *filename, const char *content) {
    FILE *fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Error! Could not append to file '%s'\n", filename);
        return;
    }
    fprintf(fptr, "%s", content);
    fclose(fptr);
    printf("Successfully appended content to file '%s'\n", filename);
}

void read_file(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error! Could not read file '%s'\n", filename);
        return;
    }
    printf("\nContents of file '%s':\n", filename);
    printf("----------------------------------------\n");
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    printf("\n----------------------------------------\n");
    fclose(fptr);
}

int main() {
    int choice;
    char filename[100];
    char content[1024];
    while (1) {
        printf("\nFile Operations Menu:\n");
        printf("1. Create file\n");
        printf("2. Write to file\n");
        printf("3. Append to file\n");
        printf("4. Read file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        if (choice == 5) break;
        printf("Enter file name: ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;
        switch (choice) {
            case 1:
                create_file(filename);
                break;
            case 2:
                printf("Enter content to write: ");
                fgets(content, sizeof(content), stdin);
                write_to_file(filename, content);
                break;
            case 3:
                printf("Enter content to append: ");
                fgets(content, sizeof(content), stdin);
                append_to_file(filename, content);
                break;
            case 4:
                read_file(filename);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
