#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int tezina[1000001];
int golemina[1000001];
int tezinapodredeni[1000001];
int goleminapodredeni[1000001];
bool visi[1000001];
int tezinakapacitet[1000001];
int goleminakapacitet[1000001];
int a,b;
priority_queue<pair<int,int> > qi;
bool mozi(int minuti)
{
    for(int i=0;i<n;i++)
        visi[i]=false;
    while(!qi.empty())
        qi.pop();
    int k=0;
    for(int i=0;i<a;i++)
    {
        while(k<n&&tezina[tezinapodredeni[k]]<tezinakapacitet[i])
        {
            qi.push(make_pair(golemina[tezinapodredeni[k]],tezinapodredeni[k]));
            k++;
        }
        for(int j=0;j<minuti&&!qi.empty();j++)
        {
            visi[qi.top().second]=true;
            qi.pop();
        }
    }
    k=0;
    for(int i=0;i<b;i++)
    {
        int j=0;
        while(j<minuti&&k<n&&golemina[goleminapodredeni[k]]<goleminakapacitet[i])
        {
            if(visi[goleminapodredeni[k]])
            {
                k++;
                continue;
            }
            visi[goleminapodredeni[k]]=true;
            k++;
            j++;
        }
    }
    int brojac=-1;
    for(int i=0;i<n;i++)
    {
        if(!visi[i])
        {
            brojac=i;
        }
    }
    if(brojac==-1)
        return true;
    else
        return false;
}
bool comparetezina(int x,int y)
{
    return (tezina[x]<tezina[y]);
}
bool comparegolemina(int x,int y)
{
    return (golemina[x]<golemina[y]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d",&a,&b,&n);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&tezinakapacitet[i]);
    }
    sort(tezinakapacitet,tezinakapacitet+a);
    for(int i=0;i<b;i++)
    {
        scanf("%d",&goleminakapacitet[i]);
    }
    sort(goleminakapacitet,goleminakapacitet+b);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&tezina[i],&golemina[i]);
        tezinapodredeni[i]=i;
        goleminapodredeni[i]=i;
    }
    sort(tezinapodredeni,tezinapodredeni+n,comparetezina);
    sort(goleminapodredeni,goleminapodredeni+n,comparegolemina);
    int l=0;
    int r=n+1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(mozi(mid))
        {
            r=mid;
        }
        else
            l=mid+1;
    }
    if(l>n)
        cout<<-1<<endl;
    else
        cout<<l<<endl;
    return 0;
}