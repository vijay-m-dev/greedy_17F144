#include<bits/stdc++.h> 
using namespace std; 
struct Node
{ 
	long long int value;
	long long int weight;
}arr[50]; 
bool comp(Node a,Node b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 
double fractionalKnapsack(long long int w,long long int n) 
{ 
	sort(arr,arr + n,comp);
	long long int cur=0;
	double tot=0.0;
	for (long long int i=0;i<n;i++) 
	{
		if (cur+arr[i].weight<=w) 
		{ 
			cur+=(arr[i].weight); 
			tot+=(arr[i].value); 
		} 
		else
		{ 
			long long int r=w-cur; 
			tot+=(arr[i].value)*(((double)r)/(arr[i].weight)); 
			cout<<tot<<endl;
			return 0;
		} 
	} 
	cout<<tot<<endl;
	return 0;
}
int main() 
{
	long long int w,n,i,vv,ww;
	printf("Enter total number of items:");
	scanf("%lld",&n);
	printf("Enter total weight:");
	scanf("%lld",&w);
	for(i=0;i<n;i++)
	{
		printf("Enter Value:");
		scanf("%lld",&vv);
		arr[i].value=vv;
		printf("Enter Weight:");
		scanf("%lld",&ww);
		arr[i].weight=ww;
	}
	fractionalKnapsack(w,n);
	return 0;
}
