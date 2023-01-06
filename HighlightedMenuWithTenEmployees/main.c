#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 8
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79
#define ENTER 13
#define ESC 27
#define TAB 9
#define SIZE 10

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

struct Employee employees[SIZE]= {{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1},{-1}};

void InsertEmpolyee(int i)
{
    int tmp;
    printf("Plz enter Employee id: ");
    scanf("%i",&employees[i].id);
    _flushall();
    printf("Plz enter Employee name: ");
    gets(employees[i].name);
    _flushall();
    do{
            printf("Plz enter Employee age: ");
            _flushall();
            scanf("\n%i",&tmp);
        }while(tmp<=18 || tmp>=60);
    employees[i].age=tmp;
    _flushall();
    printf("Plz enter Employee salary: ");
    scanf("%f",&employees[i].salary);
    _flushall();
    printf("Plz enter Employee commission: ");
    scanf("%f",&employees[i].commission);
    _flushall();
    printf("Plz nter Employee deduction: ");
    scanf("%f",&employees[i].deduction);
    _flushall();

}
void DisplayAll()
{
    int x=0;
    for (int i=0; i< SIZE; i++)
    {
        if(employees[i].id != -1)
        {
            gotoxy(2,2+x*10);
            printf("Employee at index %i",i);
            gotoxy(2,4+x*10);
            printf("id: %i\n",employees[i].id);
            gotoxy(10,4+x*10);
            printf("name: %s\n",employees[i].name);
            gotoxy(2,6+x*10);
            printf("age: %i\n",employees[i].age);
            gotoxy(10,6+x*10);
            printf("salary: %0.2f \n",employees[i].salary);
            gotoxy(2,8+x*10);
            printf("commission: %0.2f\n",employees[i].commission);
            gotoxy(10,8+x*10);
            printf("deduction: %0.2f\n",employees[i].deduction);
            gotoxy(2,10+x*10);
            printf("Net Salary: %0.2f\n",(employees[i].salary)+(employees[i].commission)-(employees[i].deduction));
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
            printf("id: %i\n",employees[index].id);
            gotoxy(10,4+x*10);
            printf("name: %s\n",employees[index].name);
            gotoxy(2,6+x*10);
            printf("age: %i\n",employees[index].age);
            gotoxy(10,6+x*10);
            printf("salary: %0.2f \n",employees[index].salary);
            gotoxy(2,8+x*10);
            printf("commission: %0.2f\n",employees[index].commission);
            gotoxy(10,8+x*10);
            printf("deduction: %0.2f\n",employees[index].deduction);
            gotoxy(2,10+x*10);
            printf("Net Salary: %0.2f\n",(employees[index].salary)+(employees[index].commission)-(employees[index].deduction));
            printf("\n");
            printf("\n");
}

int main()
{
    char menu[ROW][20]= {"New","DisplayAll","DisplayByID","DisplayByName","DeleteAll","DeleteByID","DeleteByName","Exit"};
    int cursor=0;
    char ch;
    char n[20];
    int flag=0;
    do
    {
        int flagID=0;
        int flagName=0;
        int index=0;
        int cid;
        system("cls");
        for(int i=0; i<ROW; i++)
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
                if (cursor==ROW)
                {
                    cursor=0;
                }
                break;
            case HOME:
                cursor=0;
                break;
            case END:
                cursor=ROW;
                break;
            }
            break;
        case ESC:
            flag=1;
            break;
        case TAB:
            cursor++;
            if (cursor==ROW)
            {
                cursor=0;
            }
            break;
        case ENTER:
            switch(cursor)
            {
            case 0:
                system("cls");
                do{
                printf("Choose index from 0 to 9: ");
                scanf("%i",&index);
                _flushall();}
                while(index<0 || index>9);
                InsertEmpolyee(index);
                break;
            case 1:
                system("cls");
                DisplayAll();
                getch();
                break;
            case 2:
                system("cls");
                do{printf("Choose ID >0 : ");
                scanf("%i",&cid);
                _flushall();
                }while(cid<0);
                int x =0;
                for (int i=0; i<SIZE;i++){
                    if (employees[i].id==cid){
                        flagID=1;
                        DisplayByIndex(i,x);
                         x++;
                    }

                }
                if (flagID==0) {
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
                for (int i=0; i<SIZE;i++){
                    if (!strcmp(employees[i].name,n)){
                        flagName=1;
                        DisplayByIndex(i,y);
                        y++;
                    }
                }
                if (flagName==0) {
                        printf("No Employee with this Name");
                    }
                getch();
                break;
            case 4:
                system("cls");
                printf("Delete All Records? (y/n)\n");
                switch (getch()){
                case 'y':
                    for (int i=0; i<SIZE;i++){
                    employees[i].id=-1;
                }
                    break;
                default:
                    break;
                }

                break;
            case 5:
                system("cls");
                do{printf("Choose ID >0 : ");
                scanf("%i",&cid);
                _flushall();
                }while(cid<0);
                for (int i=0; i<SIZE;i++){
                    if (employees[i].id==cid){
                        flagID=1;
                        employees[i].id=-1;
                    }

                }
                if (flagID==0) {
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
                for (int i=0; i<SIZE;i++){
                    if (!strcmp(employees[i].name,n)){
                        flagName=1;
                        DisplayByIndex(i,y);
                        z++;
                    }
                }
                if (flagName != 0){
                printf("Which employee you want to delete? enter index\n");
                scanf("%i",&index);
                _flushall();
                employees[index].id=-1;
                }

                else if (flagName==0) {
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
    return 0;
}
