#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int hash_code(const char *str, int m) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 256 + str[i]) % m;
    }
    return hash;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int hash_table[10000];
    memset(hash_table, -1, sizeof(hash_table));
     for (int i = 0; i < n; i++) {
        char str[200];
        scanf("%s", str);
    int hash = hash_code(str, m);
        printf("%d\n", hash);
           }

    return 0;
}
