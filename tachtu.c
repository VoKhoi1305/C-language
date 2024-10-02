#include <stdio.h>
#define MAX 100
int main() {
  char s[MAX+1] = " cho mot doan dai khoang 500 tu";
  char kq[3][MAX + 1];
  char *dst = NULL;
  char *p= NULL;

  int k = 0;
  int n=0;
  for (int j=0;s[j]!='\0';j++)
  {
      if(s[j]== ' ' && s[j+1]!=' ' && s[j+1]!='\0' )
       //if(s[j+1]!=' ')
       //if(s[j+1]!='\0')
        n++;
  }
  int i;
  for (k = 0, p=s , dst = kq[0]; k < n; k++, p = p + i, dst = kq[k]) {
    for (; *p != '\0' && *p == ' '; p++)
      ;
    for (i = 0; p[i] != '\0' && p[i] != ' '; i++)
      dst[i] = p[i];
    dst[i] = '\0';

    printf("tu thu %d: %s\n", k + 1, dst);
  }
  return 0;
}
