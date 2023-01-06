#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REVERSED NAME

int main()
{
    char arr[50];
    char ch;
    int x=0;



    //take array from the user character by character
    printf("Enter you name plz: \n");
    while((ch=getche())!=13)
    {
        arr[x] = ch;
        x++;
    }
    arr[x] = '\0';
    puts(arr);

     //print it reversely first solution
     printf("The reversed name is: \n");
    for(int i=x-1; i>=0; i--)
     {
         printf("%c", arr[i]);
     }
     printf("\n");

     //print it reversely second solution
     int n = strlen(arr);
     printf("The reversed name is: \n");
     for(int i=0; i<n/2; i++)
     {
         char tmp = arr[i];
         arr[i] = arr[n-i-1];
         arr[n-i-1] = tmp;

     }
     printf("%s",arr);

    return 0;
}
