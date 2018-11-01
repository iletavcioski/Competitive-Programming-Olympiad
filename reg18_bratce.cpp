#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    int p=n;
    int broj=1;
    int brojac=0;
    vector<int> v;
    while(n>0)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        brojac+=v[i]*broj,broj*=10;
    cout<<max(p,brojac)<<endl;
    return 0;
}