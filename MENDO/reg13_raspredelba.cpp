#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int res=10000000;
void solve(vector<int>a,vector<int>b,int ans)
{
    int i,j;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<b.size();j++)
        {
            if(a[i]==b[j])
            {
                a.erase(a.begin()+i);
                i=0;
                b.erase(b.begin()+j);
                break;
            }
        }
    }
    if(a.size()==0 || b.size()==0)
    {
        res=min(ans,res);
    }
    else
    {
        if(a[0]>b[0])
        {
        for(i=0;i<min((int)b.size(),3);i++)
        {
            if(i && b[i]==b[i-1])
            continue;
            if(a[0]>b[i])
            {
                vector<int>a1=a,b1=b;
                a1[0]-=b1[i];
                b1.erase(b1.begin()+i);
                solve(a1,b1,ans+1);
            }
            else
                break;
            }
            }
        else
        {
            for(i=0;i<min((int)a.size(),3);i++)
            {
                if(i && a[i]==a[i-1])
                continue;
                if(b[0]>a[i])
                {
                    vector<int>a1=a,b1=b;
                    b1[0]-=a1[i];
                    a1.erase(a1.begin()+i);
                    solve(a1,b1,ans+1);
                }
                else
                    break;
            }
        }
    }
}
int main()
{
    int n,m;
    vector<int> a,b;
    int i,j,k,l,sum1=0,sum2=0,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j,a.push_back(j),sum1+=j;
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>j,b.push_back(j),sum2+=j;
    }
    if(sum1!=sum2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    solve(a,b,0);
    cout<<res<<endl;
    return 0;
}