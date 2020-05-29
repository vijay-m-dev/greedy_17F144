#include<stdio.h>
long long int a,b,i,j,u,v,n,ne=1;
long long int visited[100]={0},min,mincost=0,cost[100][100];
void main()
{
	printf("Implementation of prim's algorithm\n'");
 	printf("Enter the number of nodes:");
 	scanf("%lld",&n);
 	printf("Enter the adjacency matrix:\n");
 	for(i=1;i<=n;i++)
 	{
  		for(j=1;j<=n;j++)
  		{
  		 scanf("%lld",&cost[i][j]);
  		 if(cost[i][j]==0)
    			cost[i][j]=999;
 		 }
 	}
	visited[1]=1;
 	while(ne<n)
 	{
  		for(i=1,min=999;i<=n;i++)
  		{
 			for(j=1;j<=n;j++)
 			{
    			if(cost[i][j]<min)
    			{
				    if(visited[i]!=0)
    				{
     					min=cost[i][j];
      					a=i;
      					b=j;
    				}
    			}
    		}
    	}
  		if(visited[a]==0 || visited[b]==0)
  		{
   			printf("Edge %d:(%d %d) cost:%d\n",ne++,a,b,min);
  			mincost+=min;
  			visited[b]=1;
  		}
  		cost[a][b]=cost[b][a]=999;
 	}
 	printf("Minimun cost:%d",mincost);
}


