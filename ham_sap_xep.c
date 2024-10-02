#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void sort(int n, int a[]){
    int i, j, last;
    for (i=1; i < n; i++) {
        last = a[i];
        j = i;
    while ((j > 0) && (a[j-1] > last)) {
        a[j] = a[j-1];
        j = j - 1; }
        a[j] = last;
    }
}
int main()
{
    int n;
    //int* ptr = (int*) malloc(n * sizeof(int));
    int ptr[MAX];
    scanf("%d\n",&n);
    int i;
    for(i=0; i<n; i++)
       {scanf("%d ",&ptr[i]);}
    sort(n,ptr);
    for (i=0; i<n; i++)
       {
           printf("%d ",ptr[i]);
        }
  // free(ptr);
}

