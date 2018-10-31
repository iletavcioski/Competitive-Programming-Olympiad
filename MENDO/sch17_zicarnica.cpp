#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int brojac=0;
    int maxi=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
  
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
        if(brojac+v[i]<=m)
            brojac+=v[i];
        else
        {
            maxi++;
            brojac=v[i];
        }
        }
        if(i==n-1)
        {
            if(brojac+v[i]<=m)
                maxi++;
            else
                maxi+=2;
        }
    }
      
    cout<<maxi<<endl;
    return 0;
}