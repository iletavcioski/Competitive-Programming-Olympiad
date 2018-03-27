#include <iostream>
using namespace std;
typedef long long ll;
ll R,L;
ll B;
ll levo[100001];
ll desno[100001];
ll X[100001];
int main()
{	
	cin>>R>>L;
	cin>>B;
	for(int i=0;i<R;i++)
	{
		cin>>X[i];
	}
	for(ll i=1;i<R;i++)
	{
		levo[i]=((X[i]-X[i-1])*i)+levo[i-1];
	}
	for(ll i=R-2;i>=0;i--)
	{
		desno[i]=desno[i+1]+((X[i+1]-X[i])*(R-i-1));
	}
	ll l=1,r=R;
	ll best=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		ll mini=1e18;
		for(ll i=0;i<=R-mid;i++)
		{
			ll midd=(i+(i+mid-1))/2;
			ll broj1=levo[midd]-levo[i]-(i*(X[midd]-X[i]));
			ll broj2=desno[midd]-desno[i+mid-1]-((R-(i+mid-1)-1)*(X[i+mid-1]-X[midd]));
			ll brojac=broj1+broj2;
			mini=min(mini,brojac);
		}
		if(mini<=B)
		{
			l=mid+1;
			best=max(best,mid);
		}
		else
			r=mid-1;
	}
	cout<<best<<endl;
	return 0;
}