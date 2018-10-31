#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    int j=0;
    int maxi=9999999;
    int kraj=-1;
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
 
    for(int i=0;i<n;i++)
    {
            if(j==m)
                break;
        while(j<m){
            if(v2[j]>=v1[i])
            {
                if((v2[j]-v1[i])<maxi)
                {
                    maxi=(v2[j]-v1[i]);
                    kraj=v1[i];
                     
                }
                 j++;           
 
            }
            else{
                break;
            }
        }
    }
     cout<<kraj<<endl;
    return 0;
}