#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    char c;
    cin>>a>>b>>c;
    char mat1[n+1][n+1];
    char mat2[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            mat1[i][j]='0',mat2[i][j]='0';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
            mat1[i][j]='1';
    }
  
    char cc='0';
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            cc='0';
        else cc='1';
        for(int j=0;j<n;j++)
        {
            mat2[i][j]=cc;
            if(cc=='0')
                cc='1';
            else
                cc='0';
        }
    }
      
    int i=b;
    int j=a;
    //cout<<mat1[i][j]<<" "<<mat2[i][j]<<endl;
    if(mat1[i][j]==mat2[i][j])
    {
        if(c!=mat1[i][j])
            cout<<4<<endl;
        else
            cout<<3<<endl;
    }
    else if(mat1[i][j]==c)
        cout<<2<<endl;
    else
        cout<<1<<endl;
    return 0;
}