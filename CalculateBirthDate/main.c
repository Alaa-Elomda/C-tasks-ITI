#include<stdio.h>
#include <stdlib.h>

//Calculate Birth Date

int main()
{
    int day, month, year;
    int cur_day = 26, cur_month = 10, cur_year = 2022;

    do{
    printf("enter ur year of birth \n");
    _flushall();
    scanf("%i", &year);
    }while(2023<year || year<1980);

    do{
    printf("enter ur month of birth \n");
    _flushall();
    scanf("%i", &month);
    }while(month>12 || month<1);

    int x;
    do{
    printf("enter ur day of birth \n");
    _flushall();
    scanf("%i", &day);

    switch(month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        x=31;
        break;
    case 4:
    case 6:
    case 11:
    case 9:
        x=30;
        break;
    case 2:
        if(year%4==0){
            x=29;
        }else{
            x=28;
        }
        break;
     }
    }while(day<1 || day>x);

    if (day > cur_day) {
      cur_day = cur_day + x;
      cur_month = cur_month - 1;
   }
   if (month > cur_month) {
      cur_year = cur_year - 1;
      cur_month = cur_month + 12;
   }
   int finalDay = cur_day - day;
   int finalMonth = cur_month - month;
   int finalYear = cur_year - year;
   printf("ur age equal %d years, %d months, %d days", finalYear, finalMonth, finalDay);

    return 0;
}
