#include<bits/stdc++.h>
using namespace std;
vector<long long int>v[51];
long long int visited[51]={0};
void dfs(long long int ver)
{
	long long int j;
	cout<<ver<<" -> ";
	visited[ver]=1;
	for(j=0;j<v[ver].size();j++)
	{
		if(visited[v[ver][j]]==0)
		{
			dfs(v[ver][j]);
		}
	}
}
int main()
{
	long long int n,i,j,e,st,en;
	cout<<"Enter no of nodes:";
	cin>>n;
	cout<<"Enter no of vertices:";
	cin>>e;
	while(e--)
	{
		cin>>st>>en;
		v[st].push_back(en);
		v[en].push_back(st);
	}
	cout<<"Enter starting node:";
	cin>>st;
	dfs(st);
	cout<<" end "<<endl;
	return 0;
	
}
