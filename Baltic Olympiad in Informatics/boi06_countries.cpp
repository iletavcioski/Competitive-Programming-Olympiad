#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node
{
	double x,y;
	double value;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin>>n;
	vector<node> v;
	vector<int> kraj(n+1,-1);
	for(int i=0;i<n;i++)
	{
		node g;
		cin>>g.x>>g.y>>g.value;
		v.push_back(g);
	}
	vector<int> dp(n+1,-1);
	for(int i=0;i<n;i++)
	{
		int brojac=0;
		double maxi=-1,ind=-1;
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			double broj=(v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y);
			broj=v[j].value/broj;
			//cout<<broj<<" "<<i<<endl;
			if(broj>v[i].value)
			{
				if(broj>maxi)
				{
					maxi=broj;
					ind=j;
				}
				else if(broj==maxi)
				{
					ind=-1;
				}
			}
		}
		if(maxi==-1)
		{
			
			kraj[i]=2;
		}
		else if(ind==-1)
		{
			
			kraj[i]=1;
		}
		else
		{
			dp[i]=ind;
			
		}
	}
	for(int i=0;i<n;i++)
	{
		if(kraj[i]==2)
			cout<<"K"<<"\n";
		else if(kraj[i]==1)
		{
			cout<<"D"<<"\n";
		}
		else
		{
			int y=i;
			while(dp[y]!=-1)
				y=dp[y];
			cout<<y+1<<"\n";
		}
	}
	return 0;
}