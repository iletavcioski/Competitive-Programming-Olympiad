#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    queue<int> qi;
    queue<int> qs;
    if((n+m)!=(a+b))
    {
        cout<<-1<<endl;
        return 0;
    }
    int nn=100001;
    vector<int> dist(nn,999999);
    qi.push(n);
    qs.push(0);
    dist[n]=0;
 
    while(!qi.empty())
    {
        int topi=qi.front();
        int tops=qs.front();
        qi.pop();
        qs.pop();
        if(topi==a)
        {
            cout<<tops<<endl;
            return 0;
        }
        if(topi+1<nn){
        if(dist[topi+1]>tops+1)
        {
            dist[topi+1]=tops+1;
            qi.push(topi+1);
            qs.push(tops+1);
        }
        }
        if((topi-1-((2*topi)%31))>=0){
        if(dist[topi-1-((2*topi)%31)]>tops+1)
        {
            dist[topi-1-((2*topi)%31)]=tops+1;
            qi.push(topi-1-((2*topi)%31));
            qs.push(tops+1);
        }
        }
    }
    cout<<-1<<endl;
    return 0;
}