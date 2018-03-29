#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.push_back(1);
	vector<int> vkraj(n+1,0);
	vkraj[1]=1;
	for(int i=2;i<=n;i++)
	{
		int k=v.size();
		cout<<k+1<<endl;
		for(int j=0;j<v.size();j++)
		{
			cout<<v[j]<<endl;
		}
		cout<<i<<endl;
		int b;
		cin>>b;
		if(b>k)
		{
			v.push_back(i);
			vkraj[i]=v.size();
		}
		else
		{
			for(int j=0;j<v.size();j++)
			{
				cout<<2<<endl;
				cout<<v[j]<<endl;
				cout<<i<<endl;
				int b;
				cin>>b;
				if(b==1)
				{
					vkraj[i]=vkraj[v[j]];
					break;
				}
			}
		}
	}
	cout<<0<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<vkraj[i]<<endl;
	}
	return 0;
}