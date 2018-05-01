#include <iostream>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    string ss="";
    for(int i=n;i>0;i--)
    {
 
        if(k>(ll)pow(2,double(i-1))){
        ss+='1';
        k=((ll)pow(2,double(i))-k)+1;
        }
        else{
            ss+='0';
         
        }
    }
    cout<<ss<<endl;
    return 0;
}