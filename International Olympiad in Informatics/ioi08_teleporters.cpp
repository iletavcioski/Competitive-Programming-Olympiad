#include <iostream>
#include <queue>
using namespace std;
int tel[2000005];
int n,m;
bool vis[2000005];
priority_queue<int> pq;
int main()
{
    int maxi=2000001;
    vis[maxi]=1;
    for(int i=0;i<maxi;i++)
    {
        tel[i]=i+1;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        tel[s-1]=e;
        tel[e-1]=s;
    }
    int brojac=-1;
    for(int i=0;i<maxi;i++)
    {
        if(!vis[i])
        {
            int pos=i;
            int ret=0;
            while(!vis[pos])
            {
                vis[pos]=1;
                if(tel[pos]!=pos+1) 
                    ret++;
                pos=tel[pos];
            }
            if(brojac==-1) 
                brojac=ret;
            else 
                pq.push(ret);
        }
    }
    while(!pq.empty()&&m--)
    {
        brojac+=pq.top()+2;
        pq.pop();
    }
    brojac+=(m+1)/2;
    brojac+=(m/2)*3;
    cout<<brojac<<endl;
    return 0;
}