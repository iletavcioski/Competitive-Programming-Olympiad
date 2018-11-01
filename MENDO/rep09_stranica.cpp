#include<iostream>
#include<cstring>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    bool visited[101];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        visited[a]=true;
    }
    int maxi=n-100;
    
    for(int i=100;i<=100000;i++)
    {
        int p=i;
        stringstream ss;
        ss<<p;string s="";ss>>s;
        bool cc=false;
        for(int j=0;j<s.size();j++)
        {
            if(visited[s[j]-'0']){
                cc=true;break;
            }
        }
        if(!cc)
        {
            int pp=s.size();
            int kk=min((pp+abs(p-n)),abs(100-n));
            maxi=min(maxi,kk);
        }
    }
    cout<<maxi<<endl;
    return 0;
}