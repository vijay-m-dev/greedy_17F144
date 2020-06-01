#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int> >v;
long long int n,par[51]={0};
void add(long long int st,long long int en)
{
	v.push_back(make_pair(st,en));
}
long long int find(long long int i)  
{
    while(par[i])
		i=par[i];
	return i;
}    
void un(long long int x,long long int y)  
{
	long long int xs,ys;
    xs=find(x);  
    ys=find(y);  
    if(xs!=ys) 
    {  
        par[xs]=ys;  
    }  
}
int cycle()  
{   
    long long int i,x,y;  
    for(i=0;i<v.size();i++)  
    { 
        x=find(v[i].first);  
        y=find(v[i].second); 
        if(x==y)
            return 1;
        un(x,y);
    }  
    return 0;  
}
int main()
{
	long long int e,st,en,w;
	cout<<"Enter no of nodes:";
	cin>>n;
	cout<<"Enter no of edges:";
	cin>>e;
	cout<<"Enter edges numbered from 1 to n"<<endl;
	while(e--)
	{
		cin>>st>>en;
		add(st,en);
	}
	if(cycle())
	{
	 	cout<<"There is cycle"<<endl;
	}
	else
	{
	 	cout<<"There is no cycle"<<endl;
	}
	return 0;
}
