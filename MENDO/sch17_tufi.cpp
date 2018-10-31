#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;
int main()
{
    int a1,a2;
    cin>>a1>>a2;
    int b1,b2;
    cin>>b1>>b2;
    int c1,c2;
    cin>>c1>>c2;
    int d1,d2;
    cin>>d1>>d2;
    int t1=60*a1+a2;
    int t2=60*b1+b2;
    int t3=60*c1+c2;
    int t4=60*d1+d2;
    t1+=t2;
    t3+=t4;
    if(t3>t1)
    {
        cout<<"T"<<endl;
        int tt=t3-t1;
        cout<<tt/60<<" "<<tt%60<<endl;
        return 0;
    }
    else
    {
        cout<<"D"<<endl;
        int tt=t1-t3;
        cout<<tt/60<<" "<<tt%60<<endl;
        return 0;
    }
    return 0;
}