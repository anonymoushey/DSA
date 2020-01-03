#include<bits/stdc++.h>
using namesapce std;

#define INF 0x3f3f3f3f

typedef pair<int ,int> ipair;

void addEdge(struct points  adj[], int u , int v , pair <int,int> wt)

{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
int * prims(vector <pair <int,int> > adj[] , int v)

struct points{
	int x;
	int y;
	vector <pair<int , pair<int,int> >> keys
}
void compare ( <pair <int , pair<int,int> > > a , <pair <int , pair<int,int> > > b)
{
	if (a.second.first > b .second.first)
		return 1;

	elseif (a.second.first == b.second.first)
	{
		if (a.second.second>b.second.second)
			return 1;
	}	
	return 0;
}
	priority_queue < pair<int,pair <int ,int > > > ,vector <pair<int , pair <int,int> > >,compare> pq;
	
	int src=0;
	vector <int> key (v,INF);
	int *parent ;
	parent =(int*(malloc(sizeof (int)*v)))
	for (int qw=0;qw<v;qw++)
	{
		parent[qw]=-1;
	}
	vector <bool>inmst(V,false);

	pq.push(make_pair(0,src));
	key[src]=0;
	while(!pq.empty())
	{
		int u = pq.top().second.first;
		pq.pop;

		inmst[u]=true;
		for (auto  x : adj[u]->keys)
		{
			v= x.first;
			if (key(x.second.second)>weight & !inmst[v])
				key[x.first]=x.second;
				pq.push(make_pair(key[v],x.first));
				parent[x.first]=u;

		}
	}

void addEdge_2(struct points  adj[], int u , int v , pair < int ,int > wt;)

{	
		adj[u]->keys.erase((v,wt));
		adj[v]->keys.erase((u,wt));
		wt=make_pair(wt.first,1)
		adj[u]->keys.push_back(make_pair(v,wt))
		adj[v]->keys.push_back(make_pair(v,wt))

}
int main()
{
	
}

