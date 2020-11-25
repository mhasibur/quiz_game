#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    int id;
} quizGame;

int main()
{
    quizGame c1,c2;

    strcpy(c1.firstName, "Md.Hasibur Rahman");
    strcpy(c1.lastName, "hasib");
    c1.id = 3047;
     printf("Fast Name: %s\n",c1.firstName);
     printf("Last Name: %s\n",c1.lastName);
     printf("ID: %d\n",c1.id);
    return 0;
}
