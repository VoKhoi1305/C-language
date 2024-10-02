#include <stdio.h>
#define MAX 10
typedef struct {
int bien_tren;
int bien_duoi;
int gia;} bieugia;

int tinhtien(int a,bieugia bg[],int n)
{
    int tong=0;
    for (int i=0;i<n;i++)
    {
        if(a > bg[i].bien_tren)
        {
            tong += ((bg[i].bien_tren-bg[i].bien_duoi)*bg[i].gia);
        }
        else {tong += ((a-bg[i].bien_duoi+1)*bg[i].gia);break;}
    }
    return tong;
}


int main()
{
    bieugia hh[]={{0,50,1728},
              {51,100,1786},
              {101,200,2074},
              {201,300,2612},
              {301,400,2919},
              {401,1000,3015}};
    bieugia dx[]={{
              {101,200,2074},
              {201,400,2612},
              {401,700,3111},
              {701,1000,3457}};
    int so_kwh;
    scanf("%d",&so_kwh);
   // printf("%.2lf",tinhtien((so_kwh,dx[],sizeof(dx)/sizeof(dx[0]))-tinhtien(so_kwh,hh[],sizeof(hh)/sizeof(hh[0])))/10);
   printf("%d",tinhtien(so_kwh,hh,6));
    return 0;
}
