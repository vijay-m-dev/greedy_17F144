#include<bits/stdc++.h>
using namespace std;
vector<long long int>v[51];
long long int visited[51]={0};
void bfs(long long int ver)
{
	long long int j,e;
	queue<long long int>q;
	visited[ver]=1;
	q.push(ver);
	cout<<ver<<" -> ";
	while(!q.empty())
	{
		e=q.front();
		q.pop();
		for(j=0;j<v[e].size();j++)
		{
			if(visited[v[e][j]]==0)
			{
				q.push(v[e][j]);
				cout<<v[e][j]<<" -> ";
				visited[v[e][j]]=1;
			}
		}
	}
	
}
int main()
{
	long long int n,i,j,e,st,en;
	cout<<"Enter no of nodes:";
	cin>>n;
	cout<<"Enter no of edges:";
	cin>>e;
	while(e--)
	{
		cin>>st>>en;
		v[st].push_back(en);
		v[en].push_back(st);
	}
	cout<<"Enter starting node:";
	cin>>st;
	bfs(st);
	cout<<" end "<<endl;
	return 0;
	
}
