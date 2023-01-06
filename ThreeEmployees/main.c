#include <stdio.h>
#include <stdlib.h>

#define n 3

struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
    float commission;
    float deduction;
};

void PrintEmployee(struct Employee param)
{
    printf("Data of Employee: \n");
    printf("ID: %d\n",param.id);
    printf("Name: ");
    puts(param.name);
    printf("Age: %d\n",param.age);
    printf("Salary: %0.2f\n",param.salary);
    printf("Commission: %0.2f\n",param.commission);
    printf("Deduction: %0.2f\n",param.deduction);
    printf("Net salary: %0.2f\n\n",param.salary+param.commission-param.deduction);
}

int main()
{
    struct Employee employees[n];
    int tmp;

    for(int i=0; i<n; i++)
    {
         printf("Enter id: ");
    scanf("\n%d",&employees[i].id);
    printf("Enter name: ");
    _flushall();
    gets(employees[i].name);
    do{
            printf("Enter Age: ");
            _flushall();
            scanf("\n%i",&tmp);
        }while(tmp<=18 || tmp>=60);
    employees[i].age=tmp;
    printf("Enter salary: ");
    _flushall();
    scanf("\n%f",&employees[i].salary);
    printf("Enter commission: ");
    scanf("\n%f",&employees[i].commission);
    printf("Enter deduction: ");
    scanf("\n%f",&employees[i].deduction);
    }

    for(int i=0; i<n; i++)
    {
        PrintEmployee(employees[i]);
    }


    return 0;
}
