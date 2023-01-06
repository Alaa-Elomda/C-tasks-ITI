#include <stdio.h>
#include <stdlib.h>

//SIMPLE MENUE

int main()
{
    char c,ch;
  do{
    printf("A-Good Morning\n");
    printf("B-Good Afternoon\n");
    printf("C-Exit\n");

    printf("Plz enter character:\n");
    _flushall();
    scanf("%c",&c);

    switch(c)
    {
    case 'A':
    case 'a':
        printf("Good Morning\n");
        break;

    case 'B':
    case 'b':
        printf("Good Afternoon\n");
        break;

    case 'C':
    case 'c':
        printf("Bye\n");
        return 0;
        break;


    default:
        printf("Choose a char plz!\n");
    }

    printf("Do you want to continue? (y/n) \n");
    _flushall();
    scanf("%c",&ch);
    if(ch == 'n'){
         printf("ok bye bye \n");

     }
  }

    while(ch == 'y' );




    return 0;
}
