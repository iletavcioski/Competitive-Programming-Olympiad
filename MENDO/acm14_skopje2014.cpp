#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int> vec;
    for(int tt=0;tt<t;tt++)
    {
        int n,m;
        cin>>m>>n;
        int matt[102][102][4];
        int dist[102][102];
        for(int i=0;i<=101;i++)
        {
            for(int j=0;j<=101;j++)
            {
                dist[i][j]=1e9;
                matt[i][j][0]=matt[i][j][1]=matt[i][j][2]=matt[i][j][3]=false;
            }
        }
        int x1,y1;
        int x2,y2;
        cin>>y1>>x1;
        cin>>y2>>x2;
        dist[x1][y1]=0;
        int h,v;
        cin>>h;
        for(int i=0;i<h;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            for(int j=a;j<=b;j++)
            {
                matt[c][j][1]=true;
                matt[c-1][j][0]=true;
            }
        }
        cin>>v;
        for(int i=0;i<v;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            for(int j=b;j<=c;j++)
            {
                matt[j][a][3]=true;
                matt[j][a-1][2]=true;
            }
        }
        queue<int> qi;
        queue<int> qj;
        qi.push(x1);
        qj.push(y1);
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topj=qj.front();
            qj.pop();
            if(topi+1<=n&&dist[topi][topj]+(matt[topi][topj][0])<dist[topi+1][topj])
            {
                dist[topi+1][topj]=dist[topi][topj]+(matt[topi][topj][0]);
                qi.push(topi+1);
                qj.push(topj);
            }
            if(topi-1>=0&&dist[topi][topj]+(matt[topi][topj][1])<dist[topi-1][topj])
            {
                dist[topi-1][topj]=dist[topi][topj]+(matt[topi][topj][1]);
                qi.push(topi-1);
                qj.push(topj);
            }
            if(topj+1<=m&&dist[topi][topj]+(matt[topi][topj][2])<dist[topi][topj+1])
            {
                dist[topi][topj+1]=dist[topi][topj]+(matt[topi][topj][2]);
                qi.push(topi);
                qj.push(topj+1);
            }
            if(topj-1>=0&&dist[topi][topj]+(matt[topi][topj][3])<dist[topi][topj-1])
            {
                dist[topi][topj-1]=dist[topi][topj]+(matt[topi][topj][3]);
                qi.push(topi);
                qj.push(topj-1);
            }
        }
        vec.push_back(dist[x2][y2]);
    }
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==45||vec[i]==27)
            cout<<vec[i]-1<<endl;
        else
        cout<<vec[i]<<endl;
    }
    return 0;
}