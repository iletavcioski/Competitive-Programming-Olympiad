#include<iostream>
#include<vector>
using namespace std;
vector<int> v[10];
vector<int> v1;
vector<int> kraj;
int n,maxi=2100000;
void mozi(vector<int> vv)
{
    int brojac=0;
    vector<int> visi(10+1,0);
    for(int i=0;i<vv.size();i++)
    {
        int b=vv[i];
        visi[b]=true;
        brojac+=(v1[b-1]*i);
        vector<int> vk=v[b];
        for(int j=0;j<vk.size();j++)
        {
            if(!visi[vk[j]])
                return;
        }
    }
    if(brojac<maxi)
    {
        maxi=brojac;
        kraj=vv;
    }
}
void rek(vector<int> vv,int broj)
{
    if(broj>=n)
    {
        mozi(vv);
    }
    else
    {
        vector<int> visi(10,false);
        for(int i=0;i<vv.size();i++)
        {
            visi[vv[i]]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(!visi[i])
            {
                vv.push_back(i);
                rek(vv,broj+1);
                vv.pop_back();
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    rek(vector<int> (),0);
    for(int i=0;i<kraj.size();i++)
    {
        if(i==0)
        {
            cout<<kraj[i];
        }
        else
            cout<<" "<<kraj[i];
    }
    cout<<endl;
    return 0;
}