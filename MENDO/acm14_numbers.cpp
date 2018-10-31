#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        string ss;
        cin>>ss;
        vector<bool> vec(1000001,false);
        vector<int> v;
        for(int i=0;i<ss.size();i++)
            v.push_back(ss[i]-'0');
        for(int i=0;i<ss.size();i++)
        {
            vec[v[i]]=true;
            if(i+1<ss.size())
            {
                vec[v[i]*10+v[i+1]]=true;
            }
            if(i+2<ss.size())
            {
                vec[v[i]*100+v[i+1]*10+v[i+2]]=true;
            }
            if(i+3<ss.size())
            {
                vec[v[i]*1000+v[i+1]*100+v[i+2]*10+v[i+3]]=true;
            }
            if(i+4<ss.size())
            {
                vec[v[i]*10000+v[i+1]*1000+v[i+2]*100+v[i+3]*10+v[i+4]]=true;
            }
            if(i+5<ss.size())
            {
                vec[v[i]*100000+v[i+1]*10000+v[i+2]*1000+v[i+3]*100+v[i+4]*10+v[i+5]]=true;
            }
        }
        for(int i=0;i<=1000000;i++)
        {
            if(!vec[i])
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}