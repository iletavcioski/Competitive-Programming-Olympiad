#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   int n;
   cin>>n;
   char a='0';
   int brojac=0;
   for(int i=0;i<n;i++)
   {
       char b;
       cin>>b;
       if(a!=b)
           brojac++,a=b;
   }
   cout<<brojac+1<<endl;
    return 0;
}