#include <stdio.h>

int check[9000] = {0};
int arr[11][11][11] = {0};
void ve_do_thi( int x, int y,  int z)
{
     if (x < 0 || y < 0 || z < 0 || x > 10 || y > 7 || z > 4) {
        return;}

    int h = 100 * x + 10 * y + z;
    if (check[h] != 0) {
        return;
    }
    check[h] = 1;

    if (y == 2 || z == 2) {
        return;
    }

    int new_x, new_y, new_z;
    if (z < 4) {
        new_x = (x + z <= 4) ? 0 : x - (4 - z);
        new_z = (x + z <= 4) ? x + z : 4;
        new_y = y;
        if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
            }
        }
        new_x = x;
        new_z = (y + z <= 4) ? y + z : 4;
        new_y = (y + z <=4) ? 0 : y - (4 - z);

         if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
                    }
        }
       ve_do_thi(new_x, new_y, new_z);
    }

    if (y < 7) {
        new_x = (x + y <= 7) ? 0 : x - (7 - y);
        new_y = (x + y <= 7) ? x + y : 7;
        new_z = z;

        if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
            }
        }

        ve_do_thi(new_x, new_y, new_z);

        new_x = x;
        new_y = (z + y <= 7) ? z + y : 7;
        new_z = (y + z <= 7) ? 0 : z - (7 - y);

        if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
            }
        }
       ve_do_thi(new_x, new_y, new_z);
    }
     if (x < 10) {
        new_x = (x + y <= 10) ? x + y : 10;
        new_y = (x + y <= 10) ? 0 : y - (10 - x);
        new_z = z;

        if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
            }
        }

        ve_do_thi(new_x, new_y, new_z);

        new_x = (x + z <= 10) ? x + z : 10;
        new_z = (x + z <= 10) ? 0 : z - (10 - x);
        new_y = y;

        if (x != new_x || y != new_y || z != new_z) {
            if (arr[new_x][new_y][new_z] != 1) {
                printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
                arr[new_x][new_y][new_z] = 1;
                arr[x][y][z] = 1;
            }
        }

        ve_do_thi(new_x, new_y, new_z);
    }

}
   int main()
{
	int x1 = 6, y1 = 1, z1 = 4;
	printf("digraph dfs{\n");
	ve_do_thi(x1, y1, z1);
	printf("}");
}

