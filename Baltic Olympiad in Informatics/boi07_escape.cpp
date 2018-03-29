#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int mat[505][505];
vector<vector<int> > gr;
int netflow(int x,int y)
{
    int brojac=0;
    int kk=y;
    while(1)
    {
        
        queue<int> qi;
        queue<int> qm;
        qm.push(1e9);
        qi.push(x);
        vector<int> p(505,-1);
        vector<int> vis(505,0);
        bool cc=false;
        vis[0]=true;
        y=kk;
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topm=qm.front();
            qm.pop();
            //cout<<topi<<"n"<<endl;
            if(topi==y)
            {
                brojac+=topm;
                while(p[y]!=-1)
                {
                   //cout<<y<<endl;
                    mat[p[y]][y]-=topm;
                    mat[y][p[y]]+=topm;
                    y=p[y];
                }
                cc=true;
                //cout<<"DA"<<endl;
                break;
            }
            for(int i=0;i<=504;i++){
                if(mat[topi][i]>0&&!vis[i])
                {
                    qi.push(i);
                    qm.push(min(topm,mat[topi][i]));
                    p[i]=topi;
                    vis[i]=true;
                }
            }
        }
        if(!cc)
            break;
    }
    return brojac;
}
int main()
{
    int l,w,n;
    cin>>l>>w>>n;
    vector<pair<int,int> > v;
    v.push_back(make_pair(0,0));
    double d=200;
    double d1=100;
    vector<int> vec;
    gr.insert(gr.begin(),2*n+3,vec);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(int i=1;i<=n;i++)
    {
        mat[i][i+n+1]=1;
        gr[i].push_back(i+n+1);
        for(int j=i+1;j<=n;j++)
        {
            int dist=((v[i].first-v[j].first)*(v[i].first-v[j].first))+((v[i].second-v[j].second)*(v[i].second-v[j].second));
            if(dist<=40000)
            {
               // cout<<i<<" "<<j<<endl;
                mat[j+n+1][i]=1e9;
                mat[i+n+1][j]=1e9;
                gr[j+n+1].push_back(i);
                gr[j+n+1].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i].second<=100)
        {
            mat[0][i]=1e9,gr[0].push_back(i);
            
        }
        if((v[i].second+100)>=w)
        {
            mat[i+n+1][n+1]=1e9,gr[i+n+1].push_back(n+1);
           
        }
    }
    cout<<netflow(0,n+1)<<endl;
    return 0;
}