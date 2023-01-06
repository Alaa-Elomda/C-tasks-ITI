#include <stdio.h>
#include <stdlib.h>

//avg col in 2D Array

#define row 3
#define col 4

int main()
{
    int arr[row][col];
    int sum[col] = {0};
    float avg;
    int ssum =0;

    //get the values from the user
     for(int i=0; i<row; i++)
     {
         for(int j=0; j<col; j++)
         {
             printf("Type the value at index %i,%i: ",i,j);
             scanf("\n%i",&arr[i][j]);
         }
     }

     //calculate the sum of each column //first loop on col, second on row
     for(int i=0; i<col; i++)
     {
         for(int j=0; j<row; j++)
         {
             sum[i] += arr[j][i];      //row here is j, col is i
         }
     }

     //calculate the sum of sums
     for(int i=0; i<col; i++)
     {
        printf("Sum of colmuns at index %d is %d\n",i,sum[i]);
        ssum += sum[i];
     }

     printf("The sum of all columns = %i \n",ssum);

     //calculate the avg
     avg = (float)ssum / col;
     printf("The average of sum of columns = %0.2f \n", avg);



    return 0;
}
