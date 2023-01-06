#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

//ASCI TO EXTENDED

int main()
{
    char ch;
    printf("Enter Character: \n");
    ch = getch();

    switch(ch)
    {
    case -32:
        ch = getch();
        printf("Extended Key with ASCII %i\n",ch);
        break;
    default:
        printf("Normal Key with ASCII %i\n",ch);
        break;
    }


    return 0;
}
