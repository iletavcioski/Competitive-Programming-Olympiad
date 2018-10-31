#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> brojaci;
    int broj;
    int grupa;
    int brojac11=0;
    int brojac22=0;
    int brojac33=0;
    int brojac1=0;
    int brojac2=0;
    int brojac3=0;
    for(int i=0;i<n;i++)
    {
        cin>>grupa;
        v1.push_back(grupa);
        v2.push_back(grupa);
        v3.push_back(grupa);
        if(grupa==1)
        {
            brojac11++;
        }
        else if(grupa==2)
        {
            brojac22++;
        }
        else if(grupa==3)
        {
            brojac33++;
        }
    }
    if(brojac11>0&&brojac22>0&&brojac33>0)
    {
    broj=1;
    brojac1=brojac1+brojac11;
     for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
     {
         if(*it==broj)
         {
             v1.erase(it);
             it--;
         }
     }
     for(int i=0;i<v1.size()-1;i++)
     {
         if(v1[i]==v1[i+1])
         {
             brojac1++;
         }
     }
     broj=2;
    brojac2=brojac2+brojac22;
     for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
     {
         if(*it==broj)
         {
             v2.erase(it);
             it--;
         }
     }
     for(int i=0;i<v2.size()-1;i++)
     {
         if(v2[i]==v2[i+1])
         {
             brojac2++;
         }
     }
     broj=3;
    brojac3=brojac3+brojac33;
     for(vector<int>::iterator it=v3.begin();it!=v3.end();it++)
     {
         if(*it==broj)
         {
             v3.erase(it);
             it--;
         }
     }
     for(int i=0;i<v3.size()-1;i++)
     {
         if(v3[i]==v3[i+1])
         {
             brojac3++;
         }
     }
     brojaci.push_back(brojac1);
     brojaci.push_back(brojac2);
     brojaci.push_back(brojac3);
     sort(brojaci.begin(), brojaci.end());
     cout<<brojaci[0]<<endl;
    return 0;
    }
    else if((brojac1>0&&brojac2>0&&brojac3==0)||(brojac3>0&&brojac2>0&&brojac1==0)||(brojac1>0&&brojac3>0&&brojac2==0))
    {
        brojac1=0;
        for(int i=0;i<v1.size()-1;i++)
        {
        if(v1[i]==v1[i+1])
        {
            brojac1++;
        }
        }
        cout<<brojac1<<endl;
        return 0;
    }
    else
    {
        brojac1=v1.size()-1;
        cout<<brojac1<<endl;
        return 0;
    }
    return 0;
}