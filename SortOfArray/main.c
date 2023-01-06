#include <stdio.h>
#include <stdlib.h>

//SORT ARRAY

int main()
{
    int arr[15];
    int tmp,n;

    for(int i=0; i < 15; i++)
    {
        printf("plz enter the %i index of the array: ",i);
        scanf("%i",&arr[i]);
    }

    //Sort of The array
    for(int i=0; i<15-1; i++)
    {
        for(int j=0; j<15-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }

    printf("The sorted Array is: \n");
    for(int i=0; i<15; i++)
    {
        printf("%i \n",arr[i]);
    }



    return 0;
}
