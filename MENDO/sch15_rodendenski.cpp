#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat[32][13];
    memset(mat,0,sizeof(mat));
    vector<int> v(13,0);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(!mat[a][b])
            v[b]++,mat[a][b]=true;
    }
    int maxi=0;
    for(int i=1;i<=12;i++)
        maxi=max(maxi,v[i]);
    for(int i=1;i<=12;i++)
        if(v[i]==maxi)
            cout<<i<<endl;
    return 0;
}