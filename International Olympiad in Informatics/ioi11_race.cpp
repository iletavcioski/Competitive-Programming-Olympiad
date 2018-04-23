#include <iostream>
#include <vector>
using namespace std;
int golemina_na_subtree[200002];
bool visi[200002];
int minimum_dp_patista[1000001];
int H[200002][2];
int L[200002];
int visi2[1000001];
int maxxi_centroid;
int centroid_cvor;
int zapisuvanje;
int brojac;
int n,k;
vector<vector<pair<int,int> > > v;
void dfs1(int x,int prev)
{
	golemina_na_subtree[x]=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(!visi[v[x][i].first]&&v[x][i].first!=prev)
		{
			dfs1(v[x][i].first,x);
			golemina_na_subtree[x]+=1+golemina_na_subtree[v[x][i].first];
		}
	}
}
void centroid(int x,int prev,int vkupno)
{
  int maxi=(vkupno-golemina_na_subtree[x]-1);
  for(int i=0;i<v[x].size();i++)
  {
    if(!visi[v[x][i].first]&&v[x][i].first!=prev)
    {
      centroid(v[x][i].first,x,vkupno);
      maxi=max(maxi,1+golemina_na_subtree[v[x][i].first]);
    }
  }
  if(maxi<maxxi_centroid)
  {
    centroid_cvor=x;
    maxxi_centroid=maxi;
  }
}
void dfs3(int x,int prev,int dolzina_na_pat,int brojce,bool mozi)
{
	if(dolzina_na_pat>k)
		return;
	if(!mozi)
	{
		if(visi2[k-dolzina_na_pat]==zapisuvanje)
		{
			if(brojce+minimum_dp_patista[k-dolzina_na_pat]<brojac||brojac==-1)
				brojac=brojce+minimum_dp_patista[k-dolzina_na_pat];
		}
		if(dolzina_na_pat==k)
		{
		  if(brojce<brojac||brojac==-1)
			brojac=brojce;
		}
	}
	else
	{
		if(visi2[dolzina_na_pat]<zapisuvanje)
		{
			visi2[dolzina_na_pat]=zapisuvanje;
			minimum_dp_patista[dolzina_na_pat]=brojce;
		}
		else if(brojce<minimum_dp_patista[dolzina_na_pat])
		{
			visi2[dolzina_na_pat]=zapisuvanje;
			minimum_dp_patista[dolzina_na_pat]=brojce;
		}
	}
	for (int i=0;i<v[x].size();i++)
	{
		if(!visi[v[x][i].first]&&v[x][i].first!=prev)
		{
			dfs3(v[x][i].first,x,dolzina_na_pat+v[x][i].second,brojce+1,mozi);
		}
	}
}
void dfs(int x)
{
	dfs1(x,-1);
	if(golemina_na_subtree[x]==1)
		return;
	centroid_cvor=-1;
	maxxi_centroid=golemina_na_subtree[x]+3;
	centroid(x,-1,golemina_na_subtree[x]+1);
	zapisuvanje++;
	for(int i=0;i<v[centroid_cvor].size();i++)
	{
		if(!visi[v[centroid_cvor][i].first])
		{
			dfs3(v[centroid_cvor][i].first,centroid_cvor,v[centroid_cvor][i].second,1,0);
			dfs3(v[centroid_cvor][i].first,centroid_cvor,v[centroid_cvor][i].second,1,1);
		}
	}
	int cvor=centroid_cvor;
	visi[cvor]=true;
	for(int i=0;i<v[cvor].size();i++)
	{
		if(!visi[v[cvor][i].first])
			dfs(v[cvor][i].first);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d %d", &n, &k);
	memset(visi,0,sizeof(visi));
	memset(visi2,0,sizeof(visi2));
	memset(minimum_dp_patista,0,sizeof(minimum_dp_patista));
	zapisuvanje=0;
	vector<pair<int,int> > vec;
	v.insert(v.begin(),n+5,vec);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d", &H[i][0], &H[i][1], &L[i]);
		v[H[i][1]].push_back(make_pair(H[i][0],L[i]));
		v[H[i][0]].push_back(make_pair(H[i][1],L[i]));
	}
	brojac=-1;
	dfs(0);
	cout<<brojac<<endl;
	return 0;
}