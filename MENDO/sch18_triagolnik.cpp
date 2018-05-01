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
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    cout<<((v[1]-v[0])+(v[2]-v[1]))*10<<endl;
    return 0;
}