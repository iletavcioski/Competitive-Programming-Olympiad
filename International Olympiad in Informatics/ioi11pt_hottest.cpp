#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	ll brojac=0;
	for(int i=0;i<k;i++)
		brojac+=v[i];
	ll maxi=0;
	maxi=max(maxi,brojac);
	int i=0;
	int j=k-1;
	while(j+1<n)
	{
		brojac-=v[i];
		brojac+=v[j+1];
		i++;
		j++;
		maxi=max(maxi,brojac);
	}
	cout<<maxi<<endl;
	return 0;
}