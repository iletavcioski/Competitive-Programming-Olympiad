#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string mnozi(string a)
{
    string res="";
    reverse(a.begin(),a.end());
    int prenos=0;
    for(int i=0;i<a.size();i++)
    {
        int aa=(a[i]-'0')*9;
        res+=(((aa+prenos)%10)+'0');
        prenos=(aa+prenos)/10;
    }
    if(prenos)
            {
                while(prenos)
                {
                    res+=((prenos%10)+'0');
                    prenos/=10;
                }
            }
            reverse(res.begin(),res.end());
    return res;
}
string sobiranje(string a,string b)
{
            string res;
            if(a.size()<b.size())
                swap(a,b);
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            int prenos=0;
            while(b.size()<a.size())
                b+=('0');
            for(int i=0;i<b.size();i++)
            {
                int aa=((a[i]-'0')+(b[i]-'0'));
                res+=(((prenos+aa)%10)+'0');
                prenos=((prenos+aa)/10);
            }
            if(prenos)
            {
                res+=((prenos+'0'));
            }
            reverse(res.begin(),res.end());
            return res;
}
int sporedi(string a,string b)
{
    if(a.size()>b.size())
        return 1;
    else if(a.size()<b.size())
        return 0;
    else
    {
        if(a>b)
            return 1;
        else if(a<b)
            return 0;
        else if(a==b)
            return 0;
    }
}
vector<int> str2vec(string a)
{
    vector<int> res;
    for(int i=0;i<a.size();i++)
        res.push_back(a[i]-'0');
    return res;
}
string vec2str(vector<int> a)
{
    string res;
    for(int i=0;i<a.size();i++)
        res.push_back(a[i]+'0');
    return res;
}
vector<int> int2vec(int a)
{
    vector<int> res;
    if(a==0)
    {
        res.push_back(0);
        return res;
    }
    else
    {
        while(a)
        {
            res.push_back(a%10);
            a/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
}
vector<int>  substr(vector<int> v1,vector<int> v2)
{
    vector<int> v;
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    v2.push_back(0);
     bool prenos=false;
     reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    for(int i=v1.size()-1;i>=0;i--)
    {
        if(v1[i]>=v2[i]&&prenos==false)
        {
            v.push_back(v1[i]-v2[i]);
        }
        else if(v1[i]>v2[i]&&prenos==true)
        {
            v.push_back(v1[i]-v2[i]-1);
            prenos=false;
        }
        else if(v1[i]==v2[i]&&prenos==true)
        {
            v.push_back(9);
        }
        else if(v1[i]<v2[i]&&prenos==false)
        {
            v.push_back(v1[i]+10-v2[i]);
            prenos=true;
        }
        else if(v1[i]<v2[i]&&prenos==true)
        {
            v.push_back(v1[i]+9-v2[i]);
        }
    }
    reverse(v.begin(),v.end());
    int i=0;
    for(;i<v.size();i++)
        if(v[i]!=0)
            break;
    vector<int> res;
    for(;i<v.size();i++)
        res.push_back(v[i]);
    return res;
}
int main()
{
    string ss;
    cin>>ss;
    string broj="1";
    vector<string> v(107,"");
    v[0]="1";
 
    for(int i=1;i<=105;i++)
    {
        v[i]=mnozi(v[i-1]);
    }
    string brojce="0";
    int i=0;
    int brojki=0;
    while(1)
    {
        if(sporedi(sobiranje(brojce,v[i]),ss))
        {
            brojki=i;
            break;
        }
        else{
            brojce=sobiranje(brojce,v[i]);
            i++;
        }
    }
 
    string skraj="";
    string brojac="0";
    int pcifra=0;
    brojki--;
    while(brojki>=0)
    {
        for(int i=0;i<=9;i++)
        {
            if(i!=pcifra){
            if(sporedi(sobiranje(brojce,v[brojki]),ss))
            {
                pcifra=i;
                 
                skraj+=(pcifra+'0');
                brojki--;
                break;
            }
            else
                brojce=sobiranje(brojce,v[brojki]);
            }
        }
    }
     cout<<skraj<<endl;
    return 0;
}