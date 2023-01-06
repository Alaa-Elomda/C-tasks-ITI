#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define TAB 9

struct Employee
{
    int id;
    char name[20];
    int age;
    float salary;
    float commission;
    float deduction;
};

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

//struct Employee employees[SIZE]= {{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1}};

int main()
{
    char menu[8][20]= {"New","DisplayAll","DisplayByID","DisplayByName","DeleteAll","DeleteByID","DeleteByName","Exit"};
    int cursor=0;
    char ch;
    char n[20];
    int flag=0;
    int size;
    printf("Enter Array Size\n");
    scanf("%i",&size);
    struct Employee *empPtr;
    empPtr=malloc(size  *  sizeof(struct Employee));
    for (int i=0; i<size; i++)
                {
                    empPtr[i].id=-1;
                }

    void InsertEmpolyee(int i)
    {
        printf("Enter Employee id: \n");
        scanf("%i",&empPtr[i].id);
        _flushall();
        printf("Enter Employee name: \n");
        gets(empPtr[i].name);
        _flushall();
        printf("Enter Employee age: \n");
        scanf("%i",&empPtr[i].age);
        _flushall();
        printf("Enter Employee salary: \n");
        scanf("%f",&empPtr[i].salary);
        _flushall();
        printf("Enter Employee commission: \n");
        scanf("%f",&empPtr[i].commission);
        _flushall();
        printf("Enter Employee deduction: \n");
        scanf("%f",&empPtr[i].deduction);
        _flushall();

    }
    void DisplayAll()
    {
        int x=0;
        for (int i=0; i< size; i++)
        {
            if(empPtr[i].id != -1)
            {
                gotoxy(2,2+x*10);
                printf("Employee at index %i",i);
                gotoxy(2,4+x*10);
                printf("id: %i\n",empPtr[i].id);
                gotoxy(40,4+x*10);
                printf("name: %s\n",empPtr[i].name);
                gotoxy(2,6+x*10);
                printf("age: %i\n",empPtr[i].age);
                gotoxy(40,6+x*10);
                printf("salary: %0.2f \n",empPtr[i].salary);
                gotoxy(2,8+x*10);
                printf("commission: %0.2f\n",empPtr[i].commission);
                gotoxy(40,8+x*10);
                printf("deduction: %0.2f\n",empPtr[i].deduction);
                gotoxy(2,10+x*10);
                printf("Net Salary: %0.2f\n",(empPtr[i].salary)+(empPtr[i].commission)-(empPtr[i].deduction));
                printf("\n");
                printf("\n");
                x++;
            }

        }

    }
    void DisplayByIndex(int index, int x)
    {
        gotoxy(2,2+x*10);
        printf("Employee at index %i",index);
        gotoxy(2,4+x*10);
        printf("id: %i\n",empPtr[index].id);
        gotoxy(40,4+x*10);
        printf("name: %s\n",empPtr[index].name);
        gotoxy(2,6+x*10);
        printf("age: %i\n",empPtr[index].age);
        gotoxy(40,6+x*10);
        printf("salary: %0.2f \n",empPtr[index].salary);
        gotoxy(2,8+x*10);
        printf("commission: %0.2f\n",empPtr[index].commission);
        gotoxy(40,8+x*10);
        printf("deduction: %0.2f\n",empPtr[index].deduction);
        gotoxy(2,10+x*10);
        printf("Net Salary: %0.2f\n",(empPtr[index].salary)+(empPtr[index].commission)-(empPtr[index].deduction));
        printf("\n");
        printf("\n");
    }




    do
    {
        int flagID=0;
        int flagName=0;
        int index=0;
        int cid;
        system("cls");
        for(int i=0; i<8; i++)
        {
            if(i==cursor)
            {
                textattr(5);
            }
            else
            {
                textattr(7);
            }
            gotoxy(10,8+i*2);
            _cprintf("%s",menu[i]);
        }
        ch=getch();
        switch (ch)
        {
        case -32:
            ch=getch();
            switch(ch)
            {
            case UP:
                cursor-=1;
                if (cursor<0)
                {
                    cursor=7;
                }
                break;
            case DOWN:
                cursor++;
                if (cursor==8)
                {
                    cursor=0;
                }
                break;
            case HOME:
                cursor=0;
                break;
            case END:
                cursor=8;
                break;
            }
            break;
        case ESC:
            flag=1;
            break;
        case TAB:
            cursor++;
            if (cursor==8)
            {
                cursor=0;
            }
            break;
        case ENTER:
            switch(cursor)
            {
            case 0:
                system("cls");
                do
                {
                    printf("Choose index from 0 to %i: ",size);
                    scanf("%i",&index);
                    _flushall();
                }
                while(index<0 || index>size);
                InsertEmpolyee(index);
                break;
            case 1:
                system("cls");
                DisplayAll();
                getch();
                break;
            case 2:
                system("cls");
                do
                {
                    printf("Choose ID >0 : ");
                    scanf("%i",&cid);
                    _flushall();
                }
                while(cid<0);
                int x =0;
                for (int i=0; i<size; i++)
                {
                    if (empPtr[i].id==cid)
                    {
                        flagID=1;
                        DisplayByIndex(i,x);
                        x++;
                    }

                }
                if (flagID==0)
                {
                    printf("No Employee with this ID");
                }
                getch();
                break;
            case 3:
                system("cls");
                printf("Choose Name: ");
                gets(n);
                _flushall();
                int y =0;
                for (int i=0; i<size; i++)
                {
                    if (!strcmp(empPtr[i].name,n))
                    {
                        flagName=1;
                        DisplayByIndex(i,y);
                        y++;
                    }
                }
                if (flagName==0)
                {
                    printf("No Employee with this Name");
                }
                getch();
                break;
            case 4:
                system("cls");
                printf("Delete All Records? Press y for yes and n for no\n");
                switch (getch())
                {
                case 'y':
                    for (int i=0; i<size; i++)
                    {
                        empPtr[i].id=-1;
                    }
                    break;
                default:
                    break;
                }

                break;
            case 5:
                system("cls");
                do
                {
                    printf("Choose ID >0 : ");
                    scanf("%i",&cid);
                    _flushall();
                }
                while(cid<0);
                for (int i=0; i<size; i++)
                {
                    if (empPtr[i].id==cid)
                    {
                        flagID=1;
                        empPtr[i].id=-1;
                    }

                }
                if (flagID==0)
                {
                    printf("No Employee with this ID");
                }
                getch();
                break;
            case 6:
                system("cls");
                printf("Choose Name: ");
                gets(n);
                _flushall();
                int z =0;
                for (int i=0; i<size; i++)
                {
                    if (!strcmp(empPtr[i].name,n))
                    {
                        flagName=1;
                        DisplayByIndex(i,y);
                        z++;
                    }
                }
                if (flagName != 0)
                {
                    printf("Which employee you want to delete? enter index\n");
                    scanf("%i",&index);
                    _flushall();
                    empPtr[index].id=-1;
                }

                else if (flagName==0)
                {
                    printf("No Employee with this Name");
                }
                getch();
                break;
            case 7:
                flag=1;
                break;
            }

        }
    }
    while(flag != 1);
    free(empPtr);
    return 0;
}
