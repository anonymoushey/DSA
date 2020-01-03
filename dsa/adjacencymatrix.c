#include <stdio.h>
#include <stdlib.h>
void dfs(int a[7][7],int visited[7],int n,int k )
{
	if (visited[k]==1)
	{
		return ;
	}
	printf("%d",k);
	visited[k]=1;
	int i,j;
	for(j=0;j<n;j++)
	{
		if (a[k][j]==1)
			dfs(a,visited,n,j);
	}
}



int main()
{
	int a[7][7];
	for (int i=0;i<7;i++)
	{
		for (int j=0;j<7;j++)
		{
			a[i][j]=0;
		}
	}
	a[0][1]=1;
	a[0][5]=1;
	a[1][0]=1;
	a[1][2]=1;
	a[1][4]=1;
	a[2][2]=1;
	a[2][3]=1;
	a[2][6]=1;
	a[3][2]=1;
	a[4][1]=1;
	a[4][5]=1;
	a[5][4]=1;
	a[5][0]=1;
	a[6][2]=1;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
	//		printf("%d ",a[i][j]);
		}
	//	printf("\n");
	}
	int visited[7];
	for(int i=0;i<7;i++)
		visited[i]=0;
	dfs(a,visited,7,0);

}

