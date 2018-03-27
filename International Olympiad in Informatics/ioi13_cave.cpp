#include "grader.h"
#include <iostream>
using namespace std;
void exploreCave(int N) 
{
    int S[N];
    int D[N];
    bool visited[N];
    for(int i=0;i<N;i++)
    {
    	S[i]=0;
    	D[i]=0;
    	visited[i]=0;
    }
    for(int i=0;i<N;i++)
    {
    	int position=tryCombination(S);
    	int state;
    	if(position>i||position==-1)
    		state=0;
    	else
    		state=1;
    	int l=0,r=N-1;
    	int maxi=-1;
    	while(l<r)
    	{
    		int mid=(l+r)/2;
    		int state2;
    		for(int j=0;j<=mid;j++)
    		{
    			if(!visited[j])
    			{
    				if(S[j])
    					S[j]=0;
    				else
    					S[j]=1;
    			}
    		}
    		int position1=tryCombination(S);
    		for(int j=0;j<=mid;j++)
    		{
    			if(!visited[j])
    			{
    				if(S[j])
    					S[j]=0;
    				else
    					S[j]=1;
    			}
    		}
    		if(position1>i||position1==-1)
    			state2=0;
    		else
    			state2=1;
    		if(state2!=state)
    		{
    			r=mid;
    		}
    		else
    		{
    			l=mid+1;
    		}
    	}
    	S[l]=state;
    	D[l]=i;
    	visited[l]=true;
    }
    answer(S,D);
}

