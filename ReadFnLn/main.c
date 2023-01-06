#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//READ FN & LN

int main()
{
    char fn[10];
    char ln[10];
    char fulln[20];

    //get first name from the user
    printf("Plz enter your first name: ");
    gets(fn);

    //get last name from the user
    printf("Plz enter your last name: ");
    gets(ln);

    //concat fn + ln and print them as full name
    printf("Your Full Name is: ");
    strcpy(fulln,fn);
    strcat(fulln," ");
    strcat(fulln,ln);
    puts(fulln);

    return 0;
}
