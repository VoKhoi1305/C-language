#include<stdio.h>
#include <stdlib.h>
#define MAX 100000
#define NUMBER_COLOR 500
#define MAX_GRAPH 10000
#include<string.h>
typedef struct{
	int x,y;
}Edge;
typedef struct{
	int point,color,level;
}Vertex;
//-----------------------------------
int k,i,j,n,m;
int graph[MAX_GRAPH][MAX_GRAPH]={0};
	int degree[MAX_GRAPH]={0};
	Edge edge1[MAX],edge2[MAX];
	Vertex vertex[MAX_GRAPH],tmp;
	int color[NUMBER_COLOR];
//-----------------------------------
int main()
{
	scanf("%d %d",&n,&m);//khai bao dinh va canh
//---------------------------------------------------------------khai bao luong mau
	for(i=1;i<=NUMBER_COLOR;i++)
	color[i-1]=i;
//--------------------------------------------------------------- nhap canh
     FILE *f3=fopen("F:\\tomau\\graph.txt.txt","r");
    for(i=1;i<=m;i++)
	{
		fscanf(f3,"%d %d",&edge1[i].x,&edge1[i].y);
		graph[edge1[i].y][edge1[i].x]=1;
		graph[edge1[i].x][edge1[i].y]=graph[edge1[i].y][edge1[i].x];
		degree[edge1[i].x]++;
		degree[edge1[i].y]++;
	}
	fclose(f3);
	/*for(i=1;i<=m;i++)
	{
		scanf("%d %d",&edge[i].x,&edge[i].y);
		graph[edge[i].y][edge[i].x]=1;
		graph[edge[i].x][edge[i].y]=graph[edge[i].y][edge[i].x];
		degree[edge[i].x]++;
		degree[edge[i].y]++;
	}*/
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
		int used_color[NUMBER_COLOR]={0};
		for(j=1;vertex[j].level<=vertex[i].level,j<=n;j++)//xet hang xom cua dinh dang can to mau
		{
			if((graph[u][j]==1||graph[j][u]==1)&&(vertex[j].color>0))
			used_color[vertex[j].color-1]=1;
		}
		for(j=0;j<NUMBER_COLOR;j++)//chon mau cho dinh
		if(used_color[color[j]-1]==0)
		{
			vertex[u].color=color[j];
			break;
		}
	}
//--------------------------------------------------------------- in ra man hinh
    FILE *f1=fopen("F:\\tomau\\dothitomau.txt","w");//link dan den file to mau
    /*fprintf(f1,"%s","graph dothi\n");
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
			fprintf(f1,"%3d %s",i,"[fillcolor=yellow, style=filled]; \n");
			break;
		case 5:
			fprintf(f1,"%3d %s",i,"[fillcolor=orange, style=filled]; \n");
			break;
		case 6:
		    fprintf(f1,"%3d %s",i,"[fillcolor=skyblue, style=filled]; \n");
			break;
		case 7:
		    fprintf(f1,"%3d %s",i,"[fillcolor=peru, style=filled]; \n");
			break;
		case 8:
		    fprintf(f1,"%3d %s",i,"[fillcolor=tan, style=filled]; \n");
			break;
		case 9:
		    fprintf(f1,"%3d %s",i,"[fillcolor=violet, style=filled]; \n");
			break;
		case 10:
		    fprintf(f1,"%3d %s",i,"[fillcolor=cyan, style=filled]; \n");
			break;
		case 11:
		    fprintf(f1,"%3d %s",i,"[fillcolor=purple, style=filled]; \n");
			break;
		case 12:
	        fprintf(f1,"%3d %s",i,"[fillcolor=lavender, style=filled]; \n");
        	break;
        case 13:
        	fprintf(f1,"%3d %s",i,"[fillcolor=tomato, style=filled]; \n");
        	break;
        case 14:
        	fprintf(f1,"%3d %s",i,"[fillcolor=sandybrown, style=filled]; \n");
         	break;
         case 15:
            fprintf(f1,"%3d %s",i,"[fillcolor=royalblue, style=filled]; \n");
            break;
        case 16:
            fprintf(f1,"%3d %s",i,"[fillcolor=teal, style=filled]; \n");
            break;
        case 17:
            fprintf(f1,"%3d %s",i,"[fillcolor=orangered, style=filled]; \n");
            break;
        case 18:
           	fprintf(f1,"%3d %s",i,"[fillcolor=magenta, style=filled]; \n");
           	break;
        case 19:
            fprintf(f1,"%3d %s",i,"[fillcolor=seagreen1, style=filled]; \n");
            break;
		case 20:
	        fprintf(f1,"%3d %s",i,"[fillcolor=antiquewhite, style=filled]; \n");
	        break;
        case 21:
        	fprintf(f1,"%3d %s",i,"[fillcolor=aquamarine, style=filled]; \n");
        	break;
        case 22:
        	fprintf(f1,"%3d %s",i,"[fillcolor=burlywood, style=filled]; \n");
        	break;
        case 23:
        	fprintf(f1,"%3d %s",i,"[fillcolor=chartreuse, style=filled]; \n");
        	break;
        case 24:
        	fprintf(f1,"%3d %s",i,"[fillcolor=chocolate, style=filled]; \n");
        	break;
        case 25:
        	fprintf(f1,"%3d %s",i,"[fillcolor=coral, style=filled]; \n");
         	break;
        case 26:
        	fprintf(f1,"%3d %s",i,"[fillcolor=cornflowerblue, style=filled]; \n");
        	break;
        case 27:

        	fprintf(f1,"%3d %s",i,"[fillcolor=crimson, style=filled]; \n");
            break;
        case 28:
        	fprintf(f1,"%3d %s",i,"[fillcolor=fuchsia, style=filled]; \n");
        	break;
        case 29:
        	fprintf(f1,"%3d %s",i,"[fillcolor=hotpink, style=filled]; \n");
        	break;
        case 30:
        	fprintf(f1,"%3d %s",i,"[fillcolor=indigo, style=filled]; \n");
        	break;
		}
	}
	for(i=1;i<=m;i++)
	fprintf(f1,"%3d -- %d\n",edge[i].x,edge[i].y,edge[i].y);
	fprintf(f1,"%s","}");*/
	fprintf(f1,"%d\n",NUMBER_COLOR);
	for(i=1;i<=n;i++)
	fprintf(f1,"%d ",vertex[i].color);
	fclose(f1);
//---------------------------------------------------------------------------------------------------------------
/*	FILE *f2=fopen("F:\\tomau\\graph.txt.txt","w");//link den file do thi
	fprintf(f2,"%d %d\n",n,m);
	for(i=1;i<=m;i++)
	fprintf(f2,"%d %d\n",edge1[i].x,edge1[i].y);
	fclose(f2);*/
     return 0;
 }

