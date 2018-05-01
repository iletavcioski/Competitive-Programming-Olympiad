#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int brojac2=0;
    int brojac3=0;
    int brojac5=0;
    int brojac7=0;
    vector<int> v2;
    vector<int> v3;
    vector<int> v5;
    vector<int> v7;
    int n;
    char s[250];
    cin>>n;
       
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i]=='?')
        {
            v2.push_back(('2'-'0'));
            v3.push_back(('3'-'0'));
            v5.push_back(('5'-'0'));
            v7.push_back(('7'-'0'));
        }
        else
        {
            v2.push_back(s[i]-'0');
            v3.push_back(s[i]-'0');
            v5.push_back(s[i]-'0');
            v7.push_back(s[i]-'0');
        }
    }
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]==2)
        {
            brojac2++;
            if(brojac2==2)
            {
                cout<<"cool"<<endl;
                return 0;
            }
               
        }
        else
        {
            brojac2=0;
        }
    }
    for(int i=0;i<v3.size();i++)
    {
        if(v3[i]==3)
        {
            brojac3++;
            if(brojac3==3)
            {
                cout<<"cool"<<endl;
                return 0;
            }
               
        }
        else
        {
            brojac3=0;
        }
    }
    for(int i=0;i<v5.size();i++)
    {
        if(v5[i]==5)
        {
            brojac5++;
            if(brojac5==5)
            {
                cout<<"cool"<<endl;
                return 0;
            }
               
        }
        else
        {
            brojac5=0;
        }
    }
    for(int i=0;i<v7.size();i++)
    {
        if(v7[i]==7)
        {
            brojac7++;
            if(brojac7==7)
            {
                cout<<"cool"<<endl;
                return 0;
            }
               
        }
        else
        {
            brojac7=0;
        }
    }
    cout<<"boring"<<endl;
    return 0;
}