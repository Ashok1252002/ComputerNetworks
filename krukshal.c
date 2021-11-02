#include<stdio.h>
int p,q,u,v,n;
int t[50][2],i,j;
int min=99,mincost=0;
int t[50][2],i,j;
int parent[50],edge[50][50];
void sunion(int,int);
int find(int);
void main()
{
	printf("\n Enter the number of nodes : "); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%c\t",65+i);
		parent[i]=-1;
	}
	printf("\n"); 
	for(i=0;i<n;i++){
		printf("%c",65+i);
		for(j=0;j<n;j++)
		scanf("%d",&edge[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n; j++)
			if(edge[i][j]!=99)
				if(min>edge[i][j]){
					min=edge[i][j];
					u=i;
					v=j;
				}
	p=find(u);
	q=find(v);
	if(p!=q){
		t[i][0]=u;
		t[i][1]=v;
		mincost=mincost+edge[u][v];
		sunion(p,q);
	}
	else{
		t[i][0]=-1;
		t[i][1]=-1;
		}
		min=99;
	}
	printf("Minimum cost is %d \n Minimum spanning tree is \n",mincost);
	for(i=0;i<n;i++)
	if(t[i][0]!=-1 && t[i][1]!=-1)
	{
		printf("%c %c %d",65+t[i][0],65+t[i][1],edge[t[i][0]][t[i][1]]);
		printf("\n");
	}
}
void sunion(int I,int m)
{
	parent[I]=m;
}
int find(int I)
{
	if(parent[I]>0)
	I=parent[I];
	return I;
}