#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    vector<int> v;
    for(int i=0;i<7;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int> vc(100000,0);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            int a;
            cin>>a;
            vc[a]++;
        }
    }
    for(int i=0;i<7;i++)
    {
        vc[v[i]]--;
        if(vc[v[i]]<0)
        {
            cout<<"NE"<<endl;
            return 0;
        }
    }
    cout<<"DA"<<endl;
    return 0;
}