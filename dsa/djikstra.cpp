/
#include<bits/stdc++.h>
using namesapce std;

#define INF 0x3f3f3f3f

typedef pair<int,int> ipair;

void addEdge(vector <pair<int,int> > adj[], int u , int v , int wt)

{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}

void shortest path(vector <pair<int,int> > adj[],int V ,int src  )
{
	priority_queue < pair<int,int>,vector <pair<int , int> >,greater<pair<int,int> >> pq;
	vector <int> dist(V,INF);
	pq.push(make_pair(0,src));
	dist[src]=0;
	while (!pq.empty())
	{
		int u =pq.top().second;
		pq.pop();

		for(auto x : adj[u])
		{
			int v = x.first;
			int weight= x.second;

			if (dist[v]>dist[u]+weight)
			{
				dist[v]=dist[u]+weight;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
}