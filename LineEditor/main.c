#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define EXTENDED -32
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}


int main()
{
    char arr[30];
    int flag = 10;
    char ch;

    char *pf,*pl,*pc;
    pf=pl=pc = arr;

    int first,last,current;
    first=last=current=20;


    do
    {
        gotoxy(current,20);
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
                //gotoxy(last, 20);
                break;

            case RIGHT:
                if(pc<pl)
                {
                    pc++;
                    current++;
                    //gotoxy(current, 20);
                }

                break;

            case LEFT:
                if(pc>pf)
                {
                    pc--;
                    current--;
                    //gotoxy(current, 20);
                }
                break;

            case HOME:
                pc = arr;
                current = 20;
                //gotoxy(current, 20);
                break;

            }
            break;

        case ENTER:
        case ESC:
            *pl = '\0';
            flag = 1;
            break;

        default:
            if(isprint(ch))
            {
                if(pc == pl)
                {
                    if(pc < pf+29)
                    {
                        *pc = ch;
                        //gotoxy(current, 20);
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
                    //gotoxy(current, 20);
                    printf("%c",ch);
                    pc++;
                    current++;
                }

            }

        }
    }
    while(flag==10);
    system("cls");
    puts(arr);


    return 0;
}
