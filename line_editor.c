#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200
#define INITIAL_CAPACITY 10

typedef struct
{
    char **lines;
    int count;
    int capacity;
} Document;


/* Initialize document */
void initDocument(Document *doc)
{
    doc->count = 0;
    doc->capacity = INITIAL_CAPACITY;

    doc->lines = malloc(doc->capacity * sizeof(char *));

    if (doc->lines == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}


/* Insert a line */
void insertLine(Document *doc, int lineNumber, char text[])
{
    if (lineNumber < 1 || lineNumber > doc->count + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    if (doc->count == doc->capacity)
    {
        doc->capacity *= 2;

        doc->lines = realloc(
            doc->lines,
            doc->capacity * sizeof(char *)
        );
    }

    int index = lineNumber - 1;

    /* Shift lines right */
    for (int i = doc->count; i > index; i--)
    {
        doc->lines[i] = doc->lines[i - 1];
    }

    doc->lines[index] = malloc(strlen(text) + 1);
    strcpy(doc->lines[index], text);

    doc->count++;

    printf("Line inserted.\n");
}


/* Delete a line */
void deleteLine(Document *doc, int lineNumber)
{
    if (doc->count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > doc->count)
    {
        printf("Invalid line number.\n");
        return;
    }

    int index = lineNumber - 1;

    free(doc->lines[index]);

    /* Shift lines left */
    for (int i = index; i < doc->count - 1; i++)
    {
        doc->lines[i] = doc->lines[i + 1];
    }

    doc->count--;

    printf("Line deleted.\n");
}


/* Display document */
void displayDocument(Document *doc)
{
    if (doc->count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    for (int i = 0; i < doc->count; i++)
    {
        printf("%d. %s\n", i + 1, doc->lines[i]);
    }
}


/* Save document */
void saveDocument(Document *doc, char filename[])
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }

    for (int i = 0; i < doc->count; i++)
    {
        fprintf(fp, "%s\n", doc->lines[i]);
    }

    fclose(fp);

    printf("Document saved.\n");
}


/* Load document */
void loadDocument(Document *doc, char filename[])
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }

    /* Clear old lines */
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    doc->count = 0;

    char text[MAX_LINE];

    while (fgets(text, MAX_LINE, fp) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';

        if (doc->count == doc->capacity)
        {
            doc->capacity *= 2;

            doc->lines = realloc(
                doc->lines,
                doc->capacity * sizeof(char *)
            );
        }

        doc->lines[doc->count] = malloc(strlen(text) + 1);
        strcpy(doc->lines[doc->count], text);

        doc->count++;
    }

    fclose(fp);

    printf("Document loaded.\n");
}


/* Free memory */
void freeDocument(Document *doc)
{
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    free(doc->lines);
}


/* Main */
int main()
{
    Document doc;

    initDocument(&doc);

    int choice;
    int lineNumber;
    char text[MAX_LINE];
    char filename[100];

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Save\n");
        printf("5. Load\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Enter line number: ");
                scanf("%d", &lineNumber);
                getchar();

                printf("Enter text: ");
                fgets(text, MAX_LINE, stdin);

                text[strcspn(text, "\n")] = '\0';

                insertLine(&doc, lineNumber, text);
                break;

            case 2:
                printf("Enter line number: ");
                scanf("%d", &lineNumber);
                getchar();

                deleteLine(&doc, lineNumber);
                break;

            case 3:
                displayDocument(&doc);
                break;

            case 4:
                printf("Enter filename: ");
                scanf("%99s", filename);

                saveDocument(&doc, filename);
                break;

            case 5:
                printf("Enter filename: ");
                scanf("%99s", filename);

                loadDocument(&doc, filename);
                break;

            case 6:
                freeDocument(&doc);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}