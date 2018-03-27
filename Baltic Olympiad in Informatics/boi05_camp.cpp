#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int dp[1201][1201];
struct characteristic
{
	int a,b,c,d;
	bool e,f;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	vector<characteristic> v;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>dp[i][j];
			dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
		}
	}
	int x,y;
	cin>>x>>y;
	int h;
	cin>>h;
	characteristic g;
	for(int i=0;i<h;i++)
	{
		cin>>g.a>>g.b>>g.c>>g.d>>g.e>>g.f;
		v.push_back(g);
	}
	int maxi=0;
	int X=1,Y=1;
	for(int i=1;i<=n-x+1;i++)
	{
		for(int j=1;j<=m-y+1;j++)
		{
			int brojac=0;
			//cout<<i<<"----"<<j<<endl;
			for(int k=0;k<h;k++)
			{
				int a1=i+v[k].a-1;
				int b1=j+v[k].b-1;
				int a2=a1+v[k].c-1;
				int b2=b1+v[k].d-1;
				//cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
				if(v[k].e)
				{
					int br1=dp[a2][b2]-dp[a1-1][b2]-dp[a2][b1-1]+dp[a1-1][b1-1];
					a1+=v[k].c;
					a2+=v[k].c;
					int br2=dp[a2][b2]-dp[a1-1][b2]-dp[a2][b1-1]+dp[a1-1][b1-1];
					if(v[k].f&&br1>=br2)
						brojac++;
					else if(!v[k].f&&br1<br2)
						brojac++;
					//cout<<br1<<" "<<br2<<endl;
				}
				else
				{
					int br1=dp[a2][b2]-dp[a1-1][b2]-dp[a2][b1-1]+dp[a1-1][b1-1];
					b1+=v[k].d;
					b2+=v[k].d;
					int br2=dp[a2][b2]-dp[a1-1][b2]-dp[a2][b1-1]+dp[a1-1][b1-1];
					if(v[k].f&&br1>=br2)
						brojac++;
					else if(!v[k].f&&br1<br2)
						brojac++;
					//cout<<br1<<" "<<br2<<endl;
				}
				if(brojac+(h-k+1)<=maxi)
					break;
			}
			if(brojac>maxi)
			{
				maxi=brojac;
				X=i;
				Y=j;
			}
		}
	}
	cout<<X<<" "<<Y<<endl;
	cout<<maxi<<endl;
	return 0;
}