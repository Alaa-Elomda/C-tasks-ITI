#include <stdio.h>
#include <stdlib.h>
//Struct Employee
//id
//name
//age
//salary
//commission
//deduction

//netsalary

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
    printf("Net salary: %0.2f\n",param.salary+param.commission-param.deduction);
}

int main()
{
    struct Employee e1;
    int tmp;

    printf("Enter id: ");
    scanf("\n%d",&e1.id);
    printf("Enter name: ");
    _flushall();
    gets(e1.name);
    do{
        printf("Enter Age: ");
        _flushall();
        scanf("\n%i",&tmp);
    }while(tmp<=18 || tmp>=60);
    e1.age=tmp;
    printf("Enter salary: ");
    scanf("\n%f",&e1.salary);
    printf("Enter commission: ");
    scanf("\n%f",&e1.commission);
    printf("Enter deduction: ");
    scanf("\n%f",&e1.deduction);

    PrintEmployee(e1);

    return 0;
}
