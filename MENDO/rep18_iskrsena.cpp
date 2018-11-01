#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int a1=v[1];
    int b1=v[3];
    cout<<a1*b1<<endl;
    return 0;
}