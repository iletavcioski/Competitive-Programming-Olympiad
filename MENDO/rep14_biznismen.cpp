#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
     
    string ss1;
    string ss2;
    cin>>ss1;
    cin>>ss2;
    vector<int> v1;
    vector<int> v2;
    int brojac1=0;
    for(int i=0;i<ss1.size();i++)
    {
        v1.push_back(ss1[i]-'0');
    }
    for(int i=0;i<ss2.size();i++)
    {
        v2.push_back(ss2[i]-'0');
    }
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]<v2[i])
        {
            if((v2[i]-v1[i])<=5)
            {
            brojac1=brojac1+(v2[i]-v1[i]);
            }
            else
            {
                v1[i]=v1[i]+10;
                brojac1=brojac1+(v1[i]-v2[i]);
            }
        }
        else if(v1[i]==v2[i])
        {
            brojac1=brojac1+(v2[i]-v1[i]);
        }
        else if(v1[i]>v2[i])
        {
            if((v1[i]-v2[i])<=5)
            {
                brojac1=brojac1+(v1[i]-v2[i]);
            }
            else
            {
                v2[i]=v2[i]+10;
                brojac1=brojac1+(v2[i]-v1[i]);
            }
        }
    }
    cout<<brojac1<<endl;
    return 0;
}