#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//STATIC MAGIC BOX

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    int col, row;
    int size = 3;
    row = 1;
    col = size/2+1;

    for (int i = 1;i<=size*size ;i++)
    {
        gotoxy(col*3,row*3);
        printf("%i",i);
        if(i%size != 0)
        {
            row--;
            col--;
            if(col < 1){col = size;}
            if(row < 1){row = size;}
        }
        else
        {
            row ++;
        }
    }
    return 0;
}
