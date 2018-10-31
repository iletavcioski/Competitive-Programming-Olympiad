#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
   // ios_base::sync_with_stdio(false);
    string ss;
    cin>>ss;
    vector<bool> v(1000001,1);
    v[0]=0;
    v[1]=0;
    for(int i=2;i<=1000000;i++)
    {
        if(v[i])
        {
            int p=i;
            for(int j=i+p;j<=1000000;j+=p)
                v[j]=false;
        }
    }
   
    vector<bool> visi(1000001,0);
    ll brojac=0;
    for(int i=0;i<ss.size();i++)
    {
        int broj1=ss[i]-'0';
        //cout<<broj1<<endl;
        if(v[broj1]&&!visi[broj1])
            brojac++,visi[broj1]=true;
        if(i+1<ss.size())
        {
            int broj1=((ss[i]-'0')*10+(ss[i+1]-'0'));
            if(v[broj1]&&!visi[broj1])
                brojac++,visi[broj1]=true;
              //  cout<<broj1<<endl;
        }
        if(i+2<ss.size())
        {
            int broj1=((ss[i]-'0')*100+(ss[i+1]-'0')*10+(ss[i+2]-'0'));
            if(v[broj1]&&!visi[broj1])
                brojac++,visi[broj1]=true;
                //cout<<broj1<<endl;
        }
        if(i+3<ss.size())
        {
            int broj1=((ss[i]-'0')*1000+(ss[i+1]-'0')*100+(ss[i+2]-'0')*10+(ss[i+3]-'0'));
            if(v[broj1]&&!visi[broj1])
                brojac++,visi[broj1]=true;
                //cout<<broj1<<endl;
        }
        if(i+4<ss.size())
        {
            int broj1=((ss[i]-'0')*10000+(ss[i+1]-'0')*1000+(ss[i+2]-'0')*100+(ss[i+3]-'0')*10+(ss[i+4]-'0'));
            if(v[broj1]&&!visi[broj1])
                brojac++,visi[broj1]=true;
                //cout<<broj1<<endl;
        }
        if(i+5<ss.size())
        {
            int broj1=((ss[i]-'0')*100000+(ss[i+1]-'0')*10000+(ss[i+2]-'0')*1000+(ss[i+3]-'0')*100+(ss[i+4]-'0')*10+(ss[i+5]-'0'));
            if(v[broj1]&&!visi[broj1])
                brojac++,visi[broj1]=true;
                //cout<<broj1<<endl;
        }
    }
    cout<<brojac<<endl;
    return 0;
}