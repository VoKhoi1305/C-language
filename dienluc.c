#include<stdio.h>
double cp[]={1728, 1786, 2074, 2612, 2919, 3015};
double np[]={1728,2074,2612,3111,3457};
double dien_cu(double a)
{
    double so_tien=0;
    if (a<=50)
        so_tien = cp[0]*a;
    else if (a<=100)
    so_tien = cp[0]*50 + cp[1]*(a-50);
    else if (a<=200)
    so_tien = cp[0]*50 + cp[1]*50 + cp[2]*(a-100);
    else if (a<=300)
        so_tien = cp[0]*50 + cp[1]*50 + cp[2]*100 + cp[3]*(a-200);
    else if (a<=400)
        so_tien = cp[0]*50 + cp[1]*50 + cp[2]*100 + cp[3]*100 + cp[4]*(a-300);
    else so_tien =  cp[0]*50 + cp[1]*50 + cp[2]*100 + cp[3]*100 + cp[4]*100 + cp[5]*(a-400);
    so_tien = so_tien*1.1;
    return so_tien;
}
double dien_moi(double a){
     double so_tien=0;
    if (a<=100)
    so_tien = np[0]*(a);
    else if (a<=200)
    so_tien = np[0]*100 + np[1]*(a-100);
    else if (a<=400)
    so_tien = np[0]*100 + np[1]*100 + np[2]*(a-200);
    else if (a<=700)
    so_tien = np[0]*100 + np[1]*100 + np[2]*200+np[3]*(a-400);
    else so_tien =  np[0]*100 + np[1]*100 + np[2]*200+np[3]*300 + np[4]*(a-700);
    so_tien = so_tien*1.1;
    return so_tien;
}
int main()
{
    double dien;
    scanf("%lf",&dien);
    printf ("%.2lf",dien_moi(dien)-dien_cu(dien));
    return 0;
}
