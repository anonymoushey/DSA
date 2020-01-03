#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std ;

void bfs(int a[7][7],int visited[7],int k)
{
	queue <int> q; 
	q.push(k);
	visited[k]=1;
	while(!q.empty())
	{
		int p =q.front();
		printf("%d. ",p);
		q.pop();
		for(int j=0;j<7;j++)
		{
			if (a[p][j]==1)
			{
				if (visited[j]==0)
				{
					q.push(j);
					visited[j]=1;
				}
			}
		}
	}
}

int main(){
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
	a[2][1]=1;
	a[1][4]=1;
	a[2][3]=1;
	a[2][6]=1;
	a[3][2]=1;
	a[4][1]=1;
	a[4][5]=1;
	a[5][4]=1;
	a[5][0]=1;
	a[6][2]=1;
	int visited[7];
	for(int i=0;i<7;i++)
		visited[i]=0;
	bfs(a,visited,0);
}