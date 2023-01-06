#include <stdio.h>
#include <stdlib.h>

//Bouns Multiply 2 2D Array

#define row1 3
#define col1 3

#define row2 3
#define col2 2

int main()
{
    int arr1[row1][col1];
    int arr2[row2][col2];
    int arr3[row1][col2] = {0};

    //prompt the user for the 1st array
    printf("Enter the vales of First Array: \n");
    for(int i=0; i<row1; i++)
    {
        for(int j =0; j<col1; j++)
        {
            printf("index %d,%d is: ", i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    //prompt the user for the 2nd array
    printf("Enter the vales of Second Array: \n");
    for(int i=0; i<row2; i++)
    {
        for(int j =0; j<col2; j++)
        {
            printf("index %d,%d is: ", i,j);
            scanf("%d",&arr2[i][j]);
        }
    }

    //calculate the multiplication result array
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            for(int k=0; k<col2; k++)
            {
                arr3[i][k] += arr1[i][j] * arr2[j][k];
            }
        }
    }

    //print the result
    printf("The Result Array: \n");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            printf("index %i,%i is: %i \n", i,j,arr3[i][j]);
        }
    }
    return 0;
}

