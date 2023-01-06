#include <stdio.h>
#include <stdlib.h>

//SIMPLE CALCULATOR

int main()
{
    int x,y,z;
    float h;
    char c, ch;
  do{
    printf("plz enter first Num: \n");
    _flushall();
    scanf("%i",&x);

    printf("plz enter second Num: \n");
    _flushall();
    scanf("%i",&y);

    printf("plz enter operator: \n");
    _flushall();
    scanf("%c",&c);

    switch(c)
    {
    case '+':
        z = x+y;
        printf("%i + %i = %i \n",x,y,z);
        break;

    case '-':
        z = x-y;
        printf("%i - %i = %i \n",x,y,z);
        break;

    case '*':
        z = x*y;
        printf("%i * %i = %i \n",x,y,z);
        break;

    case '/':
        h = x/(float)y;
        printf("%i / %0.2f = %0.2f \n", x,(float)y,h);
        break;

    case '%':
        z = x%y;
        printf("%i %% %i = %i \n",x,y,z);
        break;

    default:
        printf("plz enter an arithmatic operator (+,-,*,/,%)!\n");


    }

    printf("Do you want to continue?(y/n) \n");
    _flushall();
    scanf("%c",&ch);
    if(ch == 'n')
    {
        printf("Bye.");
    }

  } while(ch == 'y');


    return 0;
}
