#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int kraj[1025][1025];
int n;
int ma[1025][1025];
int parent[1025];
int findd(int k)
{
    if(parent[k]==k)
        return k;
    parent[k]=parent[parent[k]];
    return findd(parent[k]);
}
void unionn(int x,int y)
{
    parent[findd(x)]=findd(y);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        parent[i]=i;
    vector<pair<int,pair<int, int> > > v;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cin>>ma[i][j];
            ma[j][i]=ma[i][j];
            v.push_back(make_pair(ma[i][j],make_pair(i,j)));
        }
    }
    sort(v.begin(),v.end());
    memset(kraj,0,sizeof(kraj));
    for(int i=0;i<v.size();i++)
    {
        if(findd(v[i].second.first)!=findd(v[i].second.second))
        {
            unionn(v[i].second.first,v[i].second.second);
            kraj[v[i].second.first][v[i].second.second]=kraj[v[i].second.second][v[i].second.first]=1;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    { 
        int brojac=0;
        for(int j=0;j<n;j++)
            if(kraj[i][j])
                brojac++;
        cout<<brojac<<" ";
        for(int j=0;j<n;j++)
            if(kraj[i][j])
                cout<<j+1<<" ";
        cout<<endl;
    }
    return 0;
}