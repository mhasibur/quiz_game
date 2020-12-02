#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

/* Structure to hold the information of a contact*/
typedef struct
{
    char firstName[40];
    char lastName[40];
    char mobileNumber[20];
} Contact;

typedef enum
{
    FAST_NAME,
    LAST_NAME,
    MOBILE_NUMBER
} search_t;

/**Array to hold the Contacts*/
Contact Book[MAX_SIZE];

/**Current Size of the book Array */
int currentSize = 0;

/**Function Prototypes */
void newContact();
void display(int index);
void search(char *key, search_t type);
void saveToFile();
void readFromFile();

void strtolower(char *str);

int main()
{
    newContact();

    saveToFile();

    printf("%d\n", currentSize);

    display(0);

    return 0;
}

void newContact()
{
    if (currentSize == MAX_SIZE)
    {
        puts("Error: Book is Full!");
        return;
    }

    Contact c;
    printf("Enter First Name:- ");
    gets(c.firstName);
    printf("Enter Last Name:- ");
    gets(c.lastName);
    printf("Enter Number:- ");
    gets(c.mobileNumber);

    Book[currentSize] = c;
    ++currentSize;
}

void display(int index)
{
    if (index < 0 || index >= currentSize)
    {
        puts("Error: Invalid Index!");
        return;
    }

    Contact c = Book[index];

    printf("Name\t: %s (%s)\n", c.firstName, c.lastName);
    printf("Number\t: %s\n", c.mobileNumber);
}

void strtolower(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void search(char *key, search_t type)
{
    int found = 0;
    int i;

    strtolower(key);
    char content[41];
    if (type == FAST_NAME)
    { /* Search by First name */
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, Book[i].firstName);
            strtolower(content);

            if (strcmp(content, key) == 0)
            {
                display(i);
                found = 1;
            }
        }
    }
    else if (type == LAST_NAME)
    { /* Search by last name */
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, Book[i].lastName);
            strtolower(content);

            if (strcmp(content, key) == 0)
            {
                display(i);
                found = 1;
            }
        }
    }
    else if (type == MOBILE_NUMBER)
    { /* Search by number */
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, Book[i].mobileNumber);
            strtolower(content);

            if (strcmp(content, key) == 0)
            {
                display(i);
                found = 1;
            }
        }
    }
    else
    {
        puts("Error: Invalid Search Type!");
        return;
    }

    if (!found)
    {
        puts("Not found in the phone book!");
    }
}

void readFromFile()
{
    FILE *fp;
    if ((fp = fopen("phonebook.txt", "r")) == NULL)
    {
        puts("Error: Can't load the database file");
        return;
    }

    if (fread(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("Error: Can't read data");
        return;
    }

    if (fread(Book, sizeof(Book), 1, fp) != 1)
    {
        puts("Error: Can't save data");
        return;
    }
}

void saveToFile()
{
    FILE *fp;
    if ((fp = fopen("phonebook.txt", "w")) == NULL)
    {
        puts("Error: can't create a database file!");
        return;
    }

    /* Save the current size of the phonebook */
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("Error: can't save data!");
        return;
    }
    /* save the phonebook contents */
    if (fwrite(Book, sizeof(Book), 1, fp) != 1)
    {
        puts("Error: can't save data!");
        return;
    }

    puts("Phonebook saved to file successfully!");
}
