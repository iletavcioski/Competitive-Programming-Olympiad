#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c,d;
    cin>>c>>d;
    int brojac=0;
    while(true)
    {
        string ss="";
        string s1="";
        if(a<10){
            ss+='0';
        ss+=(a+'0');
        }
        else
        {
            ss+=((a/10)+'0');
            ss+=((a%10)+'0');
        }
        if(b<10)
        {
            ss+='0';
            ss+=(b+'0');
        }
        else
        {
            ss+=((b/10)+'0');
            ss+=((b%10)+'0');
        }
        s1=ss;
        reverse(s1.begin(),s1.end());
        if(ss==s1)
            brojac++;
        if(a==c&&b==d)
            break;
        b++;
        if(b==60){
            b=0;
            a++;
            if(a==24)
                a=0;
        }
         
    }
    cout<<brojac<<endl;
    return 0;
}