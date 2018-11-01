#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int maxi=0;
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if(i*3+j*5<=n)
            {
                maxi=max(maxi,i*5+j*9);
            }
        }
    }
    if(k%maxi!=0)
    cout<<k/maxi+1<<endl;
    else
        cout<<k/maxi<<endl;
    return 0;
}