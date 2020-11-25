#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_SIZE 100

Contact phonebook[MAX_SIZE];

int currentSize = 0;

void addEntry()
{
    if(currentSize == MAX_SIZE) {
        puts("Error: phonebook is fulL!");
        return 0;
    }

    Contact c;
    printf("Enter First Name: ");
    gets(c.firstName);
    printf("Enter Last Name: ");
    gets(c.lastName);
    printf("Enter Mobile Number: ");
    gets(c.mobileNumber);

    phonebook[currentSize] = c;
    ++currentSize;

    printf("\nContact added.\n");
}

void display(int index)
{
    if(index < 0 || index >= currentSize) {
        puts("Error: invalid index!");
        return;
    }

    Contact c = phonebook[index];
    printf("First Name: %s\n", c.firstName);
    printf("Last Name : %s\n", c.lastName);
    printf("Mobile No : %s\n", c.mobileNumber);


}

void displayAll()
{
    if(currentSize == 0) {
        puts("Phonebook is empty!");
        return;
    }
    int i;
    for(i=0; i<currentSize; i++) {
        display(i);
        puts(""); // extra new line
    }
}

void search(char *key, search_t type)
{
    int found = 0;
    int i;

    strtolower(key);
    char content[41];

    if(type == FIRST_NAME) { // search by first name
        for(i=0; i<currentSize; i++) {

            strcpy(content, phonebook[i].firstName);
            strtolower(content);

            if(strcmp(content, key) == 0) {
                display(i);
                found = 1;
            }
        }
    }
    else if(type == LAST_NAME) { // search by last name
        for(i=0; i<currentSize; i++) {
            strcpy(content, phonebook[i].lastName);
            strtolower(content);

            if(strcmp(content, key) == 0) {
                display(i);
                found = 1;
            }
        }
    }
    else if(type  == MOBILE_NUMBER) {
        for(i=0; i<currentSize; i++) {
            strcpy(content, phonebook[i].mobileNumber);
            strtolower(content);

            if(strcmp(content, key) == 0) {
                display(i);
                found = 1;
            }
        }
    }

    else {
        puts("Error: invalid search type!");
        return;
    }

    if(!found) {
        puts("Not found in the phone book");
    }
