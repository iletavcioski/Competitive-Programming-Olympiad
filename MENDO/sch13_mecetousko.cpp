#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int zbir=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        zbir+=a;
        v.push_back(a);
    }
    vector<bool> dp((zbir+1)/2+3,0);
    dp[0]=1;
     
        for(int i=0;i<v.size();i++)
        {
            for(int j=((zbir+1)/2);j>=0;j--)
            {
                if(dp[j]&&((j+v[i])<=((zbir+1)/2)))
                {
                    dp[j+v[i]]=true;
                }
            }
        }
        int res=0;
    for(int i=(zbir+1)/2;i>=0;i--)
    {
        if(dp[i]){
            res=i;
            break;
        }
    }
    cout<<abs(res-(zbir-res))<<endl;
    return 0;
}