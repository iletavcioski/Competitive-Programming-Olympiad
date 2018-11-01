#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
using namespace std;
typedef long long ll;
int main()
{
 int n;
 cin>>n;
 vector<int> v;
 for(int i=0;i<n;i++)
 {
     int a;
     cin>>a;
     v.push_back(a);
 }
 sort(v.begin(),v.end());
 int brojac=0;
 for(int i=0;i<n;i++)
     brojac+=v[v.size()-1]-v[i];
 cout<<brojac<<endl;
    return 0;
}