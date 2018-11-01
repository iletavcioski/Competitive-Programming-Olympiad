#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int mat[102][102];
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=n;i++)
        mat[i][i]=1;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
          
        for(int j=1;j<=n;j++)
        {
            if(mat[j][a]||mat[j][b])
                mat[j][a]=mat[j][b]=1;
        }
          
    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        int brojac=0;
        for(int j=1;j<=n;j++)
        {
            if(mat[j][i])
                brojac++;
        }
        maxi=max(maxi,brojac);
    }
    cout<<maxi-1<<endl;
    return 0;
}