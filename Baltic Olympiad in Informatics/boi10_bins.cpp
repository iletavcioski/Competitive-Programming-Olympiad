#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int m;
    cin>>m;
    int n;
    cin>>n;
    vector<int> v;
    vector<int> vis1(1001,0);
    vector<int> vis2(1001,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int res=0;
    for(int i=1;2*i-1<=n;i++)
    {
        bool cc=true;
        int brojac=0;
        vis1[v[i-1]]++;
        vis2[v[i-1]]--;
        vis2[v[2*i-1]]++;
        vis2[v[2*i-2]]++;
        for(int j=m;j>=0;j--)
        {
            brojac-=vis1[j];
            if(brojac<0)
            {
                cc=false;
                break;
            }
            brojac+=vis2[j];
        }
        if(cc)
            res=i;
    }
    cout<<res<<endl;
    
    return 0;
}