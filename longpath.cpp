#include<bits/stdc++.h>
using namespace std;
vector<long long int>v[1000];
long long int n;
void add(long long int st,long long int en)
{
	v[st].push_back(en);
	v[en].push_back(st);
}
pair<long long int,long long int> bfs(long long int ver)
{
	long long int j,e,i,m=0,ii;
	long long int dis[n+1];
	for(i=1;i<=n;i++)
	dis[i]=-1;
	queue<long long int>q;
	dis[ver]=0;
	q.push(ver);
	while(!q.empty())
	{
		e=q.front();
		q.pop();
		for(j=0;j<v[e].size();j++)
		{
			if(dis[v[e][j]]==-1)
			{
				q.push(v[e][j]);
				dis[v[e][j]]=dis[e]+1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(m<dis[i])
		{
			m=dis[i];
			ii=i;
		}
	}
	return make_pair(ii,m);
}
int main()
{
	long long int i,j,e,st,en;
	pair<long long int,long long int>p1,p2;
	cout<<"Enter no of nodes:";
	cin>>n;
	cout<<"Enter no of edges:";
	cin>>e;
	cout<<"Enter edges from 1 to n"<<endl;
	while(e--)
	{
		cin>>st>>en;
		add(st,en);
	}
	p1=bfs(1);
	p2=bfs(p1.first);
	cout<<"path from "<<p1.first<<" node to "<<p2.first<<" is one of the longest path with distance "<<p2.second<<endl;
	return 0;
	
}
