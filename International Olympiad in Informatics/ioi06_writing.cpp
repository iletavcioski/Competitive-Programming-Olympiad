#include <iostream>
#include <string>
using namespace std;
int v[100];
int main()
{
	int n,k;
	cin>>n>>k;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i]-'a'<0)
			v[s1[i]-'A'+26]--;
		else
			v[s1[i]-'a']--;

	}
	int l=0,r=0;
	int broj=0;
	for(int i=0;i<100;i++)
	{
		if(!v[i])
			broj++;
	}
	int brojac=0;
	s1=s2;
	while(r<k)
	{
		if(s1[r]-'a'<0)
		{
			if(v[s1[r]-'A'+26]==0)
				broj--;
			else if(v[s1[r]-'A'+26]==-1)
				broj++;
			v[s1[r]-'A'+26]++;
			r++;
		}
		else
		{
			if(v[s1[r]-'a']==0)
				broj--;
			else if(v[s1[r]-'a']==-1)
				broj++;
			v[s1[r]-'a']++;
			r++;
		}
		while(1&&l<k)
		{
			bool cc=false;
			if(s1[l]-'a'<0)
			{
				if(v[s1[l]-'A'+26]>=1){
					if(v[s1[l]-'A'+26]==1)
						broj++;
				v[s1[l]-'A'+26]--;
				l++;
				cc=true;
				}
			}
			else
			{
				if(v[s1[l]-'a']>=1){
					if(v[s1[l]-'a']==1)
						broj++;
				v[s1[l]-'a']--;
				l++;
				cc=true;
				}
			}
			if(!cc)
				break;
		}
		if(broj==100)
			brojac++;
	}
	cout<<brojac<<endl;
	return 0;
}