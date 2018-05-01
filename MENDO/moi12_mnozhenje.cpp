#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string mnozi(string a,string b)
{
    if(a.size()<b.size())
        swap(a,b);
    vector<string> vv;
    for(int i=b.size()-1;i>=0;i--)
    {
        string ss="";
        for(int j=0;j<b.size()-1-i;j++)
            ss+='0';
        int prenos=0;
        for(int j=a.size()-1;j>=0;j--)
        {
            int broj=(a[j]-'0')*(b[i]-'0');
            broj+=prenos;
            ss+=(broj%10+'0');
            prenos=broj/10;
        }
        while(prenos){
            ss+=(prenos%10)+'0';
            prenos/=10;
        }
        vv.push_back(ss);
    }
    int maxi=vv[vv.size()-1].size();
    for(int i=0;i<vv.size();i++)
    {
        string s=vv[i];
        while(s.size()<maxi)
            s+='0';
        reverse(s.begin(),s.end());
        vv[i]=s;
    }
    string re="";
    int prenos=0;
    for(int i=vv[0].size()-1;i>=0;i--)
    {
        int broj=0;
        for(int j=0;j<vv.size();j++)
        {
            broj+=(vv[j][i]-'0');
        }
        broj+=prenos;
        re+=(broj%10+'0');
        prenos=broj/10;
    }
    while(prenos){
        re+=prenos%10;
        prenos/=10;
    }
    reverse(re.begin(),re.end());
    return re;
}
int main()
{
    vector<int> v;
    for(int i=1;i<=9;i++)
    {
        int a;
        cin>>a;
        for(int j=0;j<a;j++)
            v.push_back(i);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    string s1="",s2="";
    for(int i=0;i<v.size();i++)
    {
        if(s1.size()>s2.size())
        {
            s2+=(v[i]+'0');
        }
        else if(s1.size()<s2.size())
        {
            s1+=(v[i]+'0');
        }
        else
        {
            if(s1>s2)
                s2+=(v[i]+'0');
            else
                s1+=(v[i]+'0');
        }
    }
 
    string res=mnozi(s1,s2);
    cout<<res<<endl;
    return 0;
}