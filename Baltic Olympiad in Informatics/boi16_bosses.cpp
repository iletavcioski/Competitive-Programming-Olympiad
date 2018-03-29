#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a;
            cin>>a;
            a--;
            v[a].push_back(i);
        }
    }
    ll maxi=1e18;
    for(int i=0;i<n;i++)
    {
        vector<int> vi(n+1,false);
        vi[i]=true;
        queue<int> qi;
        qi.push(i);
        queue<int> qs;
        qs.push(1);
        ll brojac=0;
        int broj=1;
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int tops=qs.front();
            qs.pop();
            brojac+=(ll)tops;
            for(int j=0;j<v[topi].size();j++)
            {
                if(!vi[v[topi][j]])
                {
                    vi[v[topi][j]]=true;
                    broj++;
                    qi.push(v[topi][j]);
                    qs.push(tops+1);
                }
            }
        }
        if(broj==n)
        maxi=min(maxi,brojac);
    }
    cout<<maxi<<endl;
    return 0;
}