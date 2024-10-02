#include<stdio.h>
#include<string.h>
#define MAX1 100
#define MAX2 20
typedef struct
{
    char makien[MAX2+1];
    int dai;
    int rong;
    int cao;
    int nang;
    int kieu;

}MH
int main()
{
     int n,i,j,choice1,choice2;
    while(choice1!=5){
	printf("\n\n         MENU\n");
	printf("  1.Nhap thong tin kien hang\n");
	printf("  2.In thong tin.\n");
	printf("  3.Thi dau.\n");
	printf("  4.Tim kiem.\n");
	printf("  5.In ket qua.\n");
	printf("  6.Ket thuc.\n");
	printf("\nMoi ban chon: ");
	scanf("%d",&choice1);
	//-----------------------------------------------
	switch(choice1){
	//=========================================================================================================================================
    case 1:
    char s[MAX1];
    char n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        gets(s[i]);
    }



}
