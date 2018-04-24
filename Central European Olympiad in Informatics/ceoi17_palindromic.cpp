#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string ss;
        cin>>ss;
        int i=0;
        int j=ss.size();
        int brojac=0;
        while(i<j) 
        {
            int k;
            ll hl=0;
            ll hr=0;
            ll base=31;
            ll ff=1;
            ll mod=1e17+7;
            for(k=1;i+k<=j-k;k++) 
            {
                hl=(hl*base+ (ss[i+k-1]-'a'))%mod;
                hr=(hr+(ss[j-k]-'a')*ff)%mod;
                ff=(ff*base)%mod;
                if(hl==hr) 
                    break;
            }
            if(i+k<=j-k) 
                brojac+=2;
            else 
                brojac++;
            i+=k;
            j-=k;
        }
        cout<<brojac<<"\n";
    }
    return 0;
}
