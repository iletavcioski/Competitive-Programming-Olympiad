#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    int x=0;
    int y=0;
    int i=0;
    double rezultat;
    double krezultat;
    int brojac=0;
    vector<int> v;
    getline(cin,s);
    if(s.size()==2)
    {
        if((s[0]=='n')||(s[0]=='w')||(s[0]=='e')||(s[0]=='s'))
        {
            if(s[1]>=48&&s[1]<=57)
            {
                v.push_back(s[1]-'0');
            }
            rezultat=(v[0]*v[0]);
            krezultat=sqrt(rezultat);
            cout<<fixed<<setprecision(2);
            cout<<krezultat<<endl;
            return 0;
        }
           
    }
    for(int i=0;i<s.size()-2;i++)
    {
        if((s[i]=='n')||(s[i]=='w')||(s[i]=='e')||(s[i]=='s'))
        {
            brojac=0;
            if(s[i+1]>=48&&s[i+1]<=57&&(s[i+2]<48||s[i+2]>57))
            {
                v.push_back(s[i+1]-'0');
            brojac+=v[0];
            }
            else if(s[i+1]>=48&&s[i+1]<=57&&(s[i+2]>=48&&s[i+2]<=57))
            {
                v.push_back(s[i+1]-'0');
                v.push_back(s[i+2]-'0');
                brojac=(v[0]*10)+v[1];
            }
            if(s[i]=='n')
            {
                y+=brojac;
            }
            else if(s[i]=='s')
            {
                y-=brojac;
            }
            else if(s[i]=='e')
            {
                x-=brojac;
            }
            else if(s[i]=='w')
            {
                x+=brojac;
            }
            v.clear();
        }
    }
    rezultat=abs(x*x+y*y);
    krezultat=sqrt(rezultat);
    cout<<fixed<<setprecision(2);
    cout<<krezultat<<endl;
    return 0;
}