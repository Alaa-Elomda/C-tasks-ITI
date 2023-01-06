#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 4
#define Up 72
#define Down 80
#define Home 71
#define End 79
#define Enter 13
#define Esc 27
#define Tab 9
#define Extended -32


void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}



int main()
{
    char menu[ROW][10] = {"New","File","Display","Exit"};
    int cursor =0;
    int flag =10;
    char ch;

    do
    {
        system("cls");
        for(int i=0;i<ROW;i++)
            {
                if(cursor==i)
                {textattr(5);}
                else
                {textattr(7);}
                gotoxy(20,20+i*3);
                _cprintf("%s",menu[i]);
            }

            //read character from user
            ch = getch();
            switch(ch)
            {
            case Extended:
                ch=getch();
                switch(ch)
                {
                case Up:
                    cursor --;
                    if(cursor<0){cursor=ROW-1;}
                break;
                case Down:
                    cursor ++;
                    if(cursor==ROW){cursor=0;}
                break;
                case Home:
                    cursor = 0;
                break;
                case End:
                    cursor = ROW-1;
                break;
                }
            break;

            case Enter:
                switch(cursor)
                {
                    case 0:
                        system("cls");
                        textattr(7);
                        _cprintf("New Page\n");
                        getch();
                    break;
                    case 1:
                        system("cls");
                        textattr(7);
                        _cprintf("File Page\n");
                        getch();
                    break;
                    case 2:
                        system("cls");
                        textattr(7);
                        _cprintf("Display Page\n");
                        getch();
                    break;
                    case 3:
                        flag=4;
                    break;

                }
            break;

            case Esc:
                flag=0;
            break;

            case Tab:
                cursor++;
                    if(cursor==ROW) {cursor=0;}
            break;

            }
    }while(flag==10);


    return 0;
}


