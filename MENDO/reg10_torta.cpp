#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<k;i++)
    {
        int bb;
        cin>>bb;
        v1.push_back(bb);
        int b;
        cin>>b;
        v2.push_back(b);
    }
    int brojac=0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v2[0]*6<=v1[0])
    {
        cout<<n*v2[0]<<endl;
        return 0;
    }
    else
    {
        int brojac=0;
        while(n>=6)
        {
            n-=6;
            brojac+=v1[0];
        }
        if(v1[0]>=n*v2[0])
            brojac+=n*v2[0];
        else
            brojac+=v1[0];
        cout<<brojac<<endl;
    }
      
    return 0;
}