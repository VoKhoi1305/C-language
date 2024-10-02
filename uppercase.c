#include <stdio.h>
#include <string.h>
#define MAX 10000
int main() {
    char T[MAX+1], s[MAX+1];
    int count = 0;
    int check = 0;
    fgets(T,MAX,stdin);
    fgets(s,MAX,stdin);
    char kq[3][MAX + 1];
    char *dst;
    char *p;
    int k = 0;
    int n = 10;
    int i;
    for (k = 0, p = s, dst = kq[0]; k < n; k++, p = p + i, dst = kq[k]) {
        for (; *p != '\0' && *p == ' '; p++)
      ;
    for (i = 0; p[i] != '\0' && p[i] != ' '; i++)
      dst[i] = p[i];
    dst[i] = '\0';
    for (int j=0;T[j]!='\0';j++)
    {
        if(T[j]== dst[j])
        {check++;}
  if(check==strlen(T))
    {count++; check=0;}
    if(check==(strlen(T)-1))
    {count++; check=0;}
    }
  }printf("%d\n",count);

  return 0;
}

