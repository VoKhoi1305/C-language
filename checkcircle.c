#include<stdio.h>
#include<math.h>
typedef struct point
{
    double x; double y;
} point_t;
typedef struct circle
{
    point_t center;
    double radius;
} circle_t;
int in_circle(circle_t c, point_t p)
{
    double check = sqrt((c.center.x-p.x)*(c.center.x-p.x)+(c.center.y-p.y)*(c.center.y-p.y));
    if (check <= c.radius)
        return 1;
     return 0;

    }

int main()
{
    point_t p;
    circle_t c;
    scanf("%lf %lf %lf %lf %lf", &c.center.x, &c.center.y, &c.radius, &p.x, &p.y);
    int flag = in_circle(c,p);
    if(flag == 1)
        printf("in circle");
    else printf("not in circle");
    return 0;
}
