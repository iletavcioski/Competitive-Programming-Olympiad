#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
string sobiranje(string aa,string bb)
{
    int prenos=0;
    string ss="";
    if(aa.size()>bb.size())
        swap(aa,bb);
    while(aa.size()<bb.size())
        aa+='0';
    for(int i=aa.size()-1;i>=0;i--)
    {
        int broj=aa[i]-'0';
        int broj2=bb[i]-'0';
    broj+=broj2;
        broj+=prenos;
        prenos=broj/10;
        broj%=10;
        ss+=(broj+'0');
    }
    string k="";
    while(prenos)
        k+=(prenos%10+'0'),prenos/=10;
        ss+=k;
        reverse(ss.begin(),ss.end());
        return ss;
}
string mnozenje(string aa)
{
    int prenos=0;
    string ss="";
    for(int i=aa.size()-1;i>=0;i--)
    {
        int broj=aa[i]-'0';
        broj*=2;
        broj+=prenos;
        prenos=broj/10;
        broj%=10;
        ss+=broj+'0';
    }
    string k="";
    while(prenos)
        k+=prenos%10+'0',prenos/=10;
        ss+=k;
        reverse(ss.begin(),ss.end());
        return ss;
}
int main()
{
    int n;
    cin>>n;
    string brojac="0";
    string brojce="1";
    for(int i=1;i<=n;i++)
    {
      brojce=mnozenje(brojce);
   
      brojac=sobiranje(brojac,brojce);
   
    }
    cout<<brojac<<endl;
    return 0;
}