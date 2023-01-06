#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define EXTENDED -32
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define backSpace 8

struct Employee
{
    int id, age;
    char name[30];
    float sal, com, ded;
};

void form()
{
    system("cls");

    gotoxy(10, 5);
    printf("ID:");

    gotoxy(40, 5);
    printf("name:");

    gotoxy(10, 10);
    printf("age:");

    gotoxy(40, 10);
    printf("salary:");

    gotoxy(10, 15);
    printf("commision:");

    gotoxy(40,15);
    printf("deduction:");
}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

char* LineEditor(int size, int col, int row, int strkey, int endkey)
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
            if(isprint(ch)&&ch>=strkey&&ch<=endkey)
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
    }
    while(flag==10);
    return arr;
}


int main()
{
   struct Employee e;
    form();

    e.id = atoi(LineEditor(1,13,5,48,57));

    char * arr = LineEditor(20,45,5,97,122);
    strcpy(e.name, arr);

    e.age = atoi(LineEditor(2,15,10,48,57));

    e.sal = atof(LineEditor(5,48,10,48,57));

    e.com = atoi(LineEditor(5,20,15,48,57));

    e.ded = atoi(LineEditor(5,50,15,48,57));

    system("cls");
    printf("name:    \t");

    puts(e.name);
    printf("net sal: \t%0.2f\n",(e.sal+e.com)-e.ded);


    return 0;
}
