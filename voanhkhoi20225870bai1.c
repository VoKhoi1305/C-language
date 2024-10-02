#include<stdio.h>
struct check {
char character;
int times;};


int main(){
    char b = 'a';
    struct check A[27];
    char s[1001];
    gets(s);
    for (int k=0; k<27;k++)
    {
        A[k].times=0;
        A[k].character  = b;
        b = b+1;
    }
    for (int i=0; s[i] != '\0';i++){
        for (int j=0; j<27; j++ )
        {
            if (s[i] == A[j].character) {
                A[j].times++;
            }
        }
    }
    for(int i=0;i<27; i++){
        if( A[i].times !=0)
        {
        printf("the letter '%c' appears %d time(s)\n",A[i].character,A[i].times);
        }
    }
}
