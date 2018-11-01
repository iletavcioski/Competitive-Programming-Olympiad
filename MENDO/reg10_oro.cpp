#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int nn;
    cin>>nn;
    vector<int> v;
    for(int i=0;i<nn;i++)
    {
        int bb;
        cin>>bb;
        v.push_back(bb);
    }
    int vv[1001][1001];
    memset(vv,0,sizeof(vv));
    vv[0][n]=1;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(vv[i][j]==1)
            {
                if(j+v[i]<=k)
                {
                    vv[i+1][j+v[i]]=1;
                }
                if(j-v[i]>=0)
                {
                    vv[i+1][j-v[i]]=1;
                }
                  
            }
        }
    }
    int g=-1;
    for(int i=0;i<=k;i++)
    {
        if(vv[v.size()][i]==1)
            g=i;
    }
    cout<<g<<endl;
    return 0;
}