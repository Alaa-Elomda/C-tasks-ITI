#include <stdio.h>
#include <stdlib.h>

//MIN & MAX of array

int main()
{
    int arr[15];
    int min,max;

    for(int i=0; i < 15; i++)
    {
        printf("plz enter the %i index of the array: ",i);
        scanf("%i",&arr[i]);
    }

    min = max = arr[0];
    for(int i =0; i<15; i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }

    printf("The min value of the array is %i\n",min);
    printf("The max value of the array is %i\n",max);



    return 0;
}
