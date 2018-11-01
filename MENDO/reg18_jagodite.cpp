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
    int m;
    cin>>m;
    int brojac=0;
    while(m>0)
    {
        if(m>=n)
            m-=n,m+=3,brojac++;
            else
                break;
    }
    cout<<brojac<<endl;
    return 0;
}