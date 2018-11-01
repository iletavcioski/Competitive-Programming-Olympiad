#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int maxi=0;
int n;
int k;
int mini=999999999;
void dfs(int x,int y,int broj,int b,int broj1)
{
    int brojce=0;
    if(y==n-1&&b==k&&(broj-broj1)<mini){
        maxi=broj;
    mini=(broj-broj1);
    return;
}
    int a=y+1;
    for(int i=y+1;i<n;i++)
    {
        brojce+=v[i];
        dfs(a,i,max(broj,brojce),b+1,min(broj,broj1));
    }
}
int main()
{
    cin>>k>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    dfs(-1,-1,0,0,99999999);
    cout<<maxi<<endl;
    return 0;
}