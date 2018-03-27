#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Izbor
{
	int broj;
	int zadi;
	int id;
};
bool compare(const Izbor&x,const Izbor &y)
{
	if(x.broj!=y.broj)
		return x.broj>y.broj;
	if(x.zadi!=y.zadi)
		return x.zadi>y.zadi;
	return x.id<y.id;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<Izbor>v;
	vector<int> zad(m+1,0);
	int mat[2002][2002];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			mat[i][j]=a;
			if(a==0)
				zad[j]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		Izbor g;
		g.broj=0;
		g.id=i+1;
		g.zadi=0;
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]){
				g.broj+=zad[j];
				g.zadi++;
			}
		}
		v.push_back(g);
	}
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size();i++)
		if(v[i].id==k){
			cout<<v[i].broj<<" "<<i+1<<endl;
			return 0;
		}
	return 0;
}