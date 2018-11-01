#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int mat[201][201];
    memset(mat,0,sizeof(mat));
    int brojac=0;
 
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(mat[i][j]==1&&mat[j][i]==0)
                brojac++;
        }
    }
    cout<<brojac<<endl;
    return 0;
}