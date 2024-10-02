#include<stdio.h>
enum ClassID {Child,Adult,Senior_Citizen};
int main()
{
    int age;
    scanf("%d",&age);
    if (age<18) age=Child;
    else if(age<65) age=Adult;
    else age=Senior_Citizen;
    switch(age)
    {
        case 0: printf("Child");
        break;
        case 1: printf("Adult");
        break;
        case 2: printf("Senior Citizen");
        break;
    }
    return 0;
}
