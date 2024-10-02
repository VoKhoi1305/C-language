#include <bits/stdc++.h>
using namespace std;

//int const x_c = 10, y_c = 7, z_c = 4;
string check = "";
string h = "";
int new_x, new_y, new_z;
int arr[11][11][11] = {0};
void ve_do_thi(int x, int y, int z)
{
	if(y == 2 || z == 2)
	{
		return;
	}
	h = "";
	h += to_string(x);
	h += to_string(y);
	h += to_string(z);
	check += " ";
	if(check.find(h) > check.size())
	{
		if(x < 10)
		{

			new_x = (x + y <= 10) ? x + y : 10;
			new_y = (x + y <= 10) ? 0 : y - (10-x);
			new_z = z;
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1)
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
			ve_do_thi(new_x, new_y, new_z);
			new_x = (x + z <= 10) ? x + z : 10;
			new_z = (x + z <= 10) ? 0 : z - (10-x);
			new_y = y;
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1)
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
//			printf("(%d, %d, %d) -- ", new_x, new_y, new_z);
			ve_do_thi(new_x, new_y, new_z);
		}
		if(y < 7)
		{
			new_x = (x + y <= 7 ) ? 0 : x - (7 - y);
			new_y = (x + y <= 7) ? x + y : 7;
			new_z = z;
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1 )
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
//			printf("(%d, %d, %d) -- ", new_x, new_y, new_z);
			ve_do_thi(new_x, new_y, new_z);
			new_x = x;
			new_y  = (z + y <= 7) ? z + y : 7;
			new_z = (y + z <= 7 ) ? 0 : z - (7 - y);
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1)
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
//			printf("(%d, %d, %d) -- ", new_x, new_y, new_z);
			ve_do_thi(new_x, new_y, new_z);
		}
		if(z < 4)
		{
			new_x = (x + z <= 4) ? 0 : x - (4 - z);
			new_z = (x + z <= 4) ? x + z : 4;
			new_y = y;
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1)
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
//			printf("(%d, %d, %d) -- ", new_x, new_y, new_z);
			ve_do_thi(new_x, new_y, new_z);
			new_x = x;
			new_y = (z + y <= 4) ? 0 : y - (4 - z);
			new_z = (y + z <= 4) ? z + y : 4;
			if(x != new_x || y != new_y || z != new_z)
			{
				if(arr[new_x][new_y][new_z] != 1)
				{
					printf("\"%d, %d, %d\" -> \"%d, %d, %d\";\n ", x, y, z, new_x, new_y, new_z);
					arr[new_x][new_y][new_z] = 1;
					arr[x][y][z] = 1;
				}
			}check += (h + ' ');
//			printf("(%d, %d, %d) -- ", new_x, new_y, new_z);
			ve_do_thi(new_x, new_y, new_z);
		}
	}
}
int main()
{
	int x1 = 0, y1 = 7, z1 = 4;
	cout<<"digraph dfs{\n";
	ve_do_thi(x1, y1, z1);
	cout<<"}";
}
