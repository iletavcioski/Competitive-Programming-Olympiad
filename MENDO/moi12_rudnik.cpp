#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll mat[303][303];
pair<int,int>p[303][303];
    int d[303][303];
pair<int,int> dsu(pair<int,int> a)
{
    if(p[a.first][a.second].first==-1)
        return a;
    else
        return dsu(p[a.first][a.second]);
}
struct node
{
    int ii;
    int jj;
    ll dd;
};
bool  operator <(const node &x,const node&y)
{
    if(x.dd<y.dd)
        return true;
    return false;
}
int main()
{
    vector<ll> vak;
    int k;
    cin>>k;
    vector<ll> v;
     
    for(int i=0;i<k;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    int n,m;
    cin>>n>>m;
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            p[i][j]=make_pair(-2,-2);
            d[i][j]=-1;
        }
    }
    priority_queue<node>qi;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            node g;
            g.ii=i;
            g.jj=j;
            g.dd=mat[i][j];
            qi.push(g);
            vak.push_back(mat[i][j]);
        }
    }
     
     
 
    map<ll,int> mapa;
//  vector<int> vkraj;
    int brojac=0;
 
    while(!qi.empty())
    {
        int a=qi.top().ii;
        int b=qi.top().jj;
    //  cout<<a<<" "<<b<<" "<<mat[a][b]<<endl;
         
            qi.pop();
        if(p[a][b].first==-2)
        {
            p[a][b].first=-1;
            p[a][b].second=-1;
            d[a][b]=0;
            brojac++;
        }
        vector<pair<int,int> > pari;
        if(a+1<n&&p[a+1][b].first!=-2)
            pari.push_back(make_pair(a+1,b));
        if(a-1>=0&&p[a-1][b].first!=-2)
            pari.push_back(make_pair(a-1,b));
        if(b+1<m&&p[a][b+1].first!=-2)
            pari.push_back(make_pair(a,b+1));
        if(b-1>=0&&p[a][b-1].first!=-2)
            pari.push_back(make_pair(a,b-1));
        for(int i=0;i<pari.size();i++)
        {
            pair<int,int> a1=pari[i];
            pair<int,int> a2=make_pair(a,b);
            a1=dsu(a1);
            a2=dsu(a2);
             
            if(a1==a2)
                continue;
            brojac--;
            if(d[a1.first][a1.second]>d[a2.first][a2.second])
            {
                p[a2.first][a2.second]=make_pair(a1.first,a1.second);
            }
            else if(d[a1.first][a1.second]<d[a2.first][a2.second])
            {
                p[a1.first][a1.second]=make_pair(a2.first,a2.second);
            }
            else if(d[a1.first][a1.second]==d[a2.first][a2.second])
            {
                if(a1>a2)
                    swap(a1,a2);
                p[a2.first][a2.second]=make_pair(a1.first,a1.second);
                d[a1.first][a1.second]++;
            }
        }
        mapa[mat[a][b]]=brojac;
    }
 
 
    int kraj=mapa[vak[0]];
    int i=0;
    sort(vak.begin(),vak.end());
    while(1)
    {
        if(v[i]<vak[0])
            cout<<mapa[vak[0]]<<endl;
        else
            break;
        i++;
        if(i==v.size())
            break;
    }
    int j=0;
    while(1)
    {
        if(vak[j]<=v[i]){
            j++;
        }
        else
        {
            cout<<mapa[vak[j]]<<endl;
            i++;
        }
        if(i==v.size()||j==vak.size())
            break;
    }
    kraj=mapa[vak[vak.size()-1]];
    for(;i<v.size();i++)
        cout<<mapa[v[i]+1]<<endl;
    return 0;
}