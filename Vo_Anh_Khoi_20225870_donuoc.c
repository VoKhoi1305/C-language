#include <stdio.h>

int check[9000] = {0};
int arr[11][11][11] = {0};
void tim_kiem( int a, int b,  int c)
{
     if (a < 0 || b < 0 || c < 0 || a > 10 || b > 7 || c > 4)

        return;

    int h = 100 * a + 10 * b + c;
    if (check[h] != 0)
    {
        return;
    }
    check[h] = 1;

    if (b == 2 || c == 2)
        return;

    int a_n, b_n, c_n;
    if (c < 4)
        {
            if(a + c <= 4)
                {
                    a_n = 0;
                    c_n = a + c;
                }
            else
                {
                    a_n =  a - (4 - c);
                    c_n = 4;
                }
            b_n = b;
            if (a != a_n || b != b_n || c != c_n)
                {
                    if (arr[a_n][b_n][c_n] != 1)
                    {
                        printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                        arr[a_n][b_n][c_n] = 1;
                        arr[a][b][c] = 1;
                    }
            tim_kiem(a_n, b_n, c_n);
        }

            a_n = a;
            if(b + c <= 4)
                {
                    b_n = 0;
                    c_n = b + c;
                }
            else
                {
                    b_n =  b - (4 - c);
                    c_n = 4;
                }
            if (a != a_n || b != b_n || c != c_n)
            {
                if (arr[a_n][b_n][c_n] != 1)
                {
                    printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                    arr[a_n][b_n][c_n] = 1;
                    arr[a][b][c] = 1;
                }
            tim_kiem(a_n, b_n, c_n);
        }
    }

    if (b < 7)
    {
       if(b + a <= 7)
                {
                    a_n = 0 ;
                    b_n = a + b;
                }
            else
                {
                    a_n = a - (7 - b);
                    b_n = 7;

                }
        c_n = c;

        if (a != a_n || b != b_n || c != c_n)
        {
            if (arr[a_n][b_n][c_n] != 1)
            {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                arr[a_n][b_n][c_n] = 1;
                arr[a][b][c] = 1;
            }
        tim_kiem(a_n, b_n, c_n);
        }

        a_n = a;
        if( b + c <= 7)
                {
                    b_n = c + b;
                    c_n = 0 ;
                }
            else
                {
                    b_n = 7;
                    c_n = c - (7 - b);

                }

        if (a != a_n || b != b_n || c != c_n)
        {
            if (arr[a_n][b_n][c_n] != 1)
            {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                arr[a_n][b_n][c_n] = 1;
                arr[a][b][c] = 1;
            }
            tim_kiem(a_n, b_n, c_n);
        }

    }
     if (a < 10)
    {
        if(a + b <= 10)
            {
                a_n = a + b;
                b_n = 0;
            }
        else
            {
                a_n = 10;
                b_n = b - (10 - a);

            }
        c_n = c;
        if(c + a <= 10)
                {
                    a_n = a + c ;
                    c_n = 0;
                }
            else
                {
                    a_n = 10;
                    c_n = c - (10 - a);

                }
        b_n = b;

        if (a != a_n || b != b_n || c != c_n)
        {
            if (arr[a_n][b_n][c_n] != 1)
            {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                arr[a_n][b_n][c_n] = 1;
                arr[a][b][c] = 1;
            }
        tim_kiem(a_n, b_n, c_n);
        }
        if (a != a_n || b != b_n || c != c_n)
        {
            if (arr[a_n][b_n][c_n] != 1)
            {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", a, b, c, a_n, b_n, c_n);
                arr[a_n][b_n][c_n] = 1;
                arr[a][b][c] = 1;
            }
        tim_kiem(a_n, b_n, c_n);
        }
    }

}
   int main()
{
	int x = 6, y = 1, z = 4;
	printf("digraph dfs{\n");
	tim_kiem(x, y, z);
	printf("}");
}
//Vo Anh Khoi 20225870
