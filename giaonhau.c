#include <stdio.h>
#include <math.h>

int is_intersecting(int x1, int y1, int x2, int y2, int x, int y, int r) {
    int closest_x = fmax(x1, fmin(x, x2));
    int closest_y = fmax(y1, fmin(y, y2));
    double distance = sqrt((closest_x - x) * (closest_x - x) + (closest_y - y) * (closest_y - y));


    if (distance > r) {
        return 0;
    }

     //   for (int i=0;i<=y1;i++)

   if (x < x1 && x > x2 && abs(y - y1) > r) {
        return 0;
    }
   // for (int i=0;i<=y2;i++)
    if (x < x1 && x > x2 && abs(y - y2 ) > r) {
        return 0;
    }
  //  for (int i=0;i<=x1;i++)
    if (y < y1 && y > y2 && abs(x - x1) > r) {
        return 0;
    }
    if (y < y1 && y > y2 && abs(x - x2 ) > r) {
        return 0;
    }


    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x1,x2,y1,y2,x,y,r;
        scanf("%d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x,&y,&r);
        printf("%d\n",is_intersecting(x1,y1,x2,y2,x,y,r));

    }
    return 0;
}

