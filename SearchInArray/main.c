#include <stdio.h>
#include <stdlib.h>

//sEARCH IN ARRAY

int main()
{
    int arr[15];
    int n, Found;
    int index =0;

    printf("Plz enter the Array: \n");
    for(int i=0; i<15; i++)
    {
        printf("the %i index: ",i);
        scanf("%i",&arr[i]);
    }

    printf("Enter the Num you want to search for: ");
    _flushall();
    scanf("%i",&n);


    //search for the number
    for(int i=0; i<15; i++)
    {
        if(n == arr[i])
        {
            Found = arr[i];
            index = i;
            break;
        }
    }

    if(Found == n)
    {
        printf("The Num is Found in index %i\n", index);
    }
    else{
        printf("Not Found\n");
    }


    return 0;
}
