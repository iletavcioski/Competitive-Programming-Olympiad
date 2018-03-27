#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> find_subset(int l,int u,vector<int> w)
{
    int n;
    n=w.size();
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        int a=w[i];
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    ll brojac=0;
    int i=0,j=0;
    bool cc=false;

    while(i<n)
    {
        if(cc)
            break;
        brojac+=v[i].first;
        if(brojac>=l&&brojac<=u)
        {
            cc=true;
            break;
        }
        if(brojac>u)
        {
            while(brojac>u)
            {
                brojac-=v[j].first;
                j++;
                if(brojac>=l&&brojac<=u)
                {
                    cc=true;
                    break;
                }

            }
        }
        if(cc)
            break;
        i++;
    }
    vector<int> result;

    if(cc){
        result.push_back(v[j].second);
        int iii=2;
        if((i-j+1)>1){
            for(int ii=j+1;ii<=i;ii++)
                result.push_back(v[ii].second);
        }
    }

    return result;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> vp;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vp.push_back(a);
    }
	vector<int> vv=find_subset(m,k,vp);
    cout<<vv.size()<<endl;
	for(int i=0;i<vv.size();i++) {
        if(i)
            cout<<" ";
        cout << vv[i];
    }
    cout<<endl;
	return 0;
}