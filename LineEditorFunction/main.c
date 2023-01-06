#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//LINE EDITOR FUNCTION

#define EXTENDED -32
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define backSpace 8



void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
char* LineEditor(int size, int col, int row)
{

    char* arr= malloc(size*sizeof(char));
    int flag = 10;
    char ch;

    char *pf,*pl,*pc,*ptr;
    pf=pl=pc = arr;

    int first,last,current;
    first = last = current = col;


    do
    {
        gotoxy(current,row);
        ch = getch();
        switch(ch)
        {
        case EXTENDED:
            ch=getch();
            switch(ch)
            {

            case END:
                pc = pl;
                current = last;
                //gotoxy(current, row);
                break;

            case RIGHT:
                if(pc<pl)
                {
                    pc++;
                    current++;
                    //gotoxy(current, row);
                }

                break;

            case LEFT:
                if(pc>pf)
                {
                    pc--;
                    current--;
                    //gotoxy(current, row);
                }
                break;

            case HOME:
                pc = arr;
                current = col;
                //gotoxy(current, low);
                break;

            }
            break;

        case ENTER:
        case ESC:
            *pl = '\0';
            flag = 1;
            break;

        case backSpace:
            if (current > col)
            {
                current--;
                ptr=pc;
                int j=0;

                for (ptr=pc ; ptr<pl ; ptr++)
                {
                    *(ptr-1)=*ptr;
                    gotoxy(current+j,row);
                    printf("%c",*(ptr-1));
                    j++;
                }
                gotoxy (current+j, row);
                printf (" ");
                last--;
                pl--;
                pc--;
            }
            break;



        default:
            if(isprint(ch))
            {
                if(pc == pl)
                {
                    if(pc < pf+size-1)
                    {
                        *pc = ch;
                        //gotoxy(current, row);
                        printf("%c",ch);
                        pc++;
                        pl++;
                        current++;
                        last++;
                    }

                }
                else
                    {
                        *pc=ch;
                        //gotoxy(current, strkey);
                        printf("%c",ch);
                        pc++;
                        current++;
                    }

            }

        }
    }
    while(flag==10);
    return arr;

}


int main()
{
    int size,col,row;
    printf("Plz enter size: ");
    scanf("%i",&size);
    printf("Plz enter col: ");
    scanf("%i",&col);
    printf("Plz enter row: ");
    scanf("%i",&row);

    char* ch = LineEditor(size,col,row);
    system("cls");
    puts(ch);


    return 0;
}
