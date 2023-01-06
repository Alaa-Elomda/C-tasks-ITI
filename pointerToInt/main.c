#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int* ptr;
    ptr=&x;

    //get the value from the user by pointer
    printf("Plz Enter the value: ");
    scanf("%d", ptr);

    //print the value by pointer
    printf("The value by pointer is: %d",*ptr);




    return 0;
}
