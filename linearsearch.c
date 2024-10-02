#include<stdio.h>
#include<string.h>
#define MAX 102

typedef struct {
    char name[50];
    char tel[12];
    char email[100];
} phoneAddr_t;

int search(phoneAddr_t str[], int t, char key[]){
    int k=0;
    for (strcpy(str[t].name,key); strcmp(str[k].name,key) != 0; k++);
    if (k==t) return -1;
    return k;
}

int main() {
  char key[10];
  scanf("%s",key);


  phoneAddr_t a[MAX] = {{"A", "1", "1@"},
                        {"B", "2", "2@"},
                        {"C", "3", "3@"},
                        {"D", "4", "4@"},
                        {"E", "5", "5@"}};



  printf("%d", search(a, 5, key));



  return 0;
}
