#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int main() {
    int T, N, i, j, k, l, flag;
    int A[MAX_N][MAX_N];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        flag = 1;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if (A[i][j]) {
                    for (k = 0; k < N; ++k) {
                        if (A[i][k] && k != j) {
                            flag = 0;
                            break;
                        }
                        if (A[k][j] && k != i) {
                            flag = 0;
                            break;
                        }
                    }
                    for (k = i + 1, l = j + 1; k < N && l < N; ++k, ++l) {
                        if (A[k][l]) {
                            flag = 0;
                            break;
                        }
                    }
                    for (k = i + 1, l = j - 1; k < N && l >= 0; ++k, --l) {
                        if (A[k][l]) {
                            flag = 0;
                            break;
                        }
                    }
                    for (k = i - 1, l = j + 1; k >= 0 && l < N; --k, ++l) {
                        if (A[k][l]) {
                            flag = 0;
                            break;
                        }
                    }
                    for (k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l) {
                        if (A[k][l]) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        printf("%d\n", flag);
    }
    return 0;
}
