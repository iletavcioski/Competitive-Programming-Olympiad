#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int X[2001][2];
int Y[2001][2];
int main()
{
	int n;
	cin>>n;	
	vector<int> x,y;
	x.push_back(1000);
	y.push_back(1000);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a+=1000;
		b+=1000;
		x.push_back(a);
		y.push_back(b);
	}
	int maxi=1e9;
	int p=0;
	int s=1;
	X[1000][0]=0;
	Y[1000][0]=0;

	for(int i=0;i<=2000;i++)
	{
		X[i][0]=abs(i-1000);
		Y[i][0]=abs(i-1000);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2000;j++)
		{
			Y[j][s]=min(X[x[i]][p]+abs(y[i-1]-j),Y[j][p]+abs(x[i-1]-x[i]));
			X[j][s]=min(Y[y[i]][p]+abs(x[i-1]-j),X[j][p]+abs(y[i-1]-y[i]));
		}
		swap(p,s);
	}
	for(int i=0;i<=2000;i++)
	{
		maxi=min(maxi,min(X[i][p],Y[i][p]));
	}
	cout<<maxi<<endl;
	return 0;
}