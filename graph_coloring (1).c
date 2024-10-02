#include<stdio.h>
#define MAX 1000
typedef struct{
	int x,y;
}Edge;
typedef struct{
	int point,color,level;
}Vertex;
int main()
{
	int i,j,n,m;
	scanf("%d %d",&n,&m);// nhap vao so dinh va so canh
	int graph[100][100]={0};
	int degree[MAX]={0};
	Edge edge[MAX];
	Vertex vertex[MAX],tmp;
	int color[5]={1,2,3,4,5};
//--------------------------------------------------------------- nhap canh
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&edge[i].x,&edge[i].y);
		graph[edge[i].y][edge[i].x]=1;
		graph[edge[i].x][edge[i].y]=graph[edge[i].y][edge[i].x];// de 2 canh bang nhau ko bi trung
		degree[edge[i].x]++;// tang bac cua dinh x len 1 bac
		degree[edge[i].y]++; // tang bac cua dinh y len 1 bac
	}
//--------------------------------------------------------------- gan dinh va bac vao 1 vertex
	for(i=1;i<=n;i++)
	{
	 	vertex[i].point=i;
		vertex[i].level=degree[i];
	}
//--------------------------------------------------------------- sap xep thu tu bac dinh tang dan
    for(i=1;i<n;i++)
	    for(j=i+1;j<=n;j++)
		{
			if(vertex[i].level<=vertex[j].level)
			{
			    tmp=vertex[j];
				vertex[j]=vertex[i];
				vertex[i]=tmp;
			}
		}
//--------------------------------------------------------------- gan mau cho tung dinh
    for(i=1;i<=n;i++)
	{
		int u=vertex[i].point;
		int used_color[1000]={0};
		for(j=1;j<=n;j++)//xet hang xom cua dinh dang can to mau
		{
			if((graph[u][j]==1||graph[j][u]==1)&&(vertex[j].color>0))
			used_color[vertex[j].color-1]=1;
		}
		for(j=0;j<6;j++)//chon mau cho dinh
		if(used_color[color[j]-1]==0)
		{
			vertex[u].color=color[j];
			break;
		}
	}
//--------------------------------------------------------------- in ra man hinh
    /*FILE *f1=fopen("C:\\Users\\Admin\\OneDrive - Hanoi University of Science and Technology\\MaiVanDang_20225699\\CODE\\dothitomau.dot","w");//link dan den file
    fprintf(f1,"%s","graph dothi\n");
	fprintf(f1,"%s","{\n");
    for(i=1;i<=n;i++)
	{
		switch(vertex[i].color){
		case 1:
			fprintf(f1,"%3d %s",i,"[fillcolor=red, style=filled]; \n");
			break;
		case 2:
			fprintf(f1,"%3d %s",i,"[fillcolor=green, style=filled]; \n");
			break;
		case 3:
			fprintf(f1,"%3d %s",i,"[fillcolor=blue, style=filled]; \n");
			break;
		case 4:
			fprintf(f1,"%3d %s",i,"[fillcolor=yellow, style=filled]; \n",i);
			break;
		case 5:
			fprintf(f1,"%3d %s",i,"[fillcolor=orange, style=filled]; \n",i);
			break;
		}
	}
	for(i=1;i<=m;i++)
	fprintf(f1,"%3d -- %d\n",edge[i].x,edge[i].y,edge[i].y);
	fprintf(f1,"%s","}");
	fclose(f1);
     return 0; */
     printf("%s","graph dothi\n");
	printf("%s","{\n");
    for(i=1;i<=n;i++)
	{
		switch(vertex[i].color){
		case 1:
			printf("%3d %s",i,"[fillcolor=red, style=filled]; \n");
			break;
		case 2:
			printf("%3d %s",i,"[fillcolor=green, style=filled]; \n");
			break;
		case 3:
			printf("%3d %s",i,"[fillcolor=blue, style=filled]; \n");
			break;
		case 4:
			printf("%3d %s",i,"[fillcolor=yellow, style=filled]; \n",i);
			break;
		case 5:
			printf("%3d %s",i,"[fillcolor=orange, style=filled]; \n",i);
			break;
		}
	}
	for(i=1;i<=m;i++)
	fprintf("%3d -- %d\n",edge[i].x,edge[i].y,edge[i].y);
	printf("%s}");

     return 0;
 }
