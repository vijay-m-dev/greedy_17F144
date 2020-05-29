#include <bits/stdc++.h> 
using namespace std; 
int overlap(string s1,string s2,string &s) 
{
	long long int m,l1,l2,i,j;
	l1=s1.length(); 
	l2=s2.length();  
	m=INT_MIN;
	for(i=1;i<=min(l1,l2);i++) 
	{
		if(s1.compare(0,i,s2,l2-i,i)==0) 
		{
			if(m<i) 
			{
				m=i; 
				s=s2+s1.substr(i); 
			}
		}
	}
	for(i=1;i<=min(l1,l2);i++) 
	{
		if(s1.compare(l1-i,i,s2,0,i)==0) 
		{
			if (m<i) 
			{
				m=i; 
				s=s1+s2.substr(i); 
			}
		}
	}
	return m; 
}  
string superstring(string s[],long long int n) 
{ 
	while(n>1) 
	{ 
		long long int m=INT_MIN,l,r,i,j,t;  
		string ss;  
		for(i=0;i<n;i++) 
		{
			for(j=i+1;j<n;j++) 
			{
				string s1; 
				t=overlap(s[i],s[j],s1); 
				if (m<t) 
				{ 
					m=t;
					l=i;
					r=j;
					ss.assign(s1); 
				} 
			} 
		} 
		if (m==INT_MIN) 
			s[0]+=s[n-1]; 
		else
		{
			s[l]=ss;  
			s[r]=s[n-1]; 
		} 
		n--;
	} 
	return s[0]; 
} 
int main() 
{ 
	long long int n,i;
	cout<<"Enter number of strings"<<endl;
	cin>>n;
	string s[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cout<<superstring(s,n); 
	return 0; 
}

