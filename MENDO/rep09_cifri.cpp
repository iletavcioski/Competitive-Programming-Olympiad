#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string broj;
    int n;
    vector<int> v;
    int brojac=0;
    cin>>broj;
    cin>>n;
    for(int i=0;i<broj.size();i++)
    {
        v.push_back(broj[i]-'0');
    }
    //for(vector<int>::iterator it=v.begin();it!=v.end()-1;it++)
    vector<int>::iterator it=v.begin();
    while(it!=v.end()-1){
        vector<int>::iterator it2=it;
        it2++;
        if(*it<*(it2))
        {
            if(it==v.begin())
            {
                it=v.erase(it);
                n--;
                if(n==0)
                {
                    break;
                }
                it++;
                it=v.begin();
                continue;
            }
            else if(it==v.begin()+1)
            {
                it=v.erase(it);
                if(n==0)
                {
                    break;
                }
                it--;
                n--;
                continue;
            }
            else
            {
                it=v.erase(it);
                it-=2;
                n--;
            }
   
        }
        if(n==0)
        {
            break;
        }
        it++;
   
    }
    vector<int> vkraj;
    if(n>0)
    {
        if(v[0]<v[v.size()-1])
        {
            for(int i=n;i<v.size();i++)
            {
                vkraj.push_back(v[i]);
            }
        }
        else
        {
            reverse(v.begin(),v.end());
            for(int i=n;i<v.size();i++)
            {
                vkraj.push_back(v[i]);
            }
            reverse(vkraj.begin(),vkraj.end());
        }
    }
    else
    {
        vkraj=v;
    }
    for(int i=0;i<vkraj.size();i++)
    {
        cout<<vkraj[i];
    }
}