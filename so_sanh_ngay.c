#include<stdio.h>
typedef struct
{
    int day;
    int month;
    int year;
}date;
int nhap(date* pd)
{   printf("Nhap ngay");
    scanf("%d %d %d",&pd->day,&pd->month,&pd->year);
    return 0;
}
int datecmp(date d1,date d2)
{
    if(d1.year == d1)
}
int main()
{
    date ngay1;
    date ngay2;
    nhap(&ngay1);
    nhap(&ngay2);

    return 0;
}

