#include<bits/stdc++.h>
using namesapce std;

#define INF 0x3f3f3f3f

typedef pair<int,int> ipair;

void addEdge(vector <pair<int,int> > adj[], int u , int v , int wt)

{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
void prims(vector <pair <int,int> > adj[] , int v)

{
	priority_queue < pair<int,int>,vector <pair<int , int> >,greater<pair<int,int> >> pq;
	int src=0;
	
	vector <int> key (v,INF);
	vector <int>parent (v,-1);
	vector <bool>inmst(V,false);

	pq.push(make_pair(0,src));
	key[src]=0;
	while(!pq.empty())
	{
		int u = pq.tip().second;
		pq.pop;

		inmst[u]=true;
		for (auto  x : adj[u])
		{
			if (key(x.first)>weight & !inmst[v])
				key[x.first]=x.second;
				pq.push(make_pair(key[v],x.first));
				parent[x.first]=u;

		}
	}
}
int main()
{
	int X
	int Y;
	for (int i = 0 ; i<v;i++)
		addEdge(adj )
	v= 12;
	struct points adj[v]
	int * parent_1= prims();
	for(i=0;i<v; i++)
	{
		if (parent_1[i]!=-1) :

			pair <int,int > w =makepair(,1)
			addEdge_2(adj,i,parent[i])

	}
	int parent_2 =prims();
	for(int i=0;i<v; i++ )
	{
		if (parent_1[i]!=parent_2[i])
			print "NOT UNIQUE";
			break		;
		elseif (i==v)
			print unique;

	} 
}