#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h, l;
vector<int> read() 
{
    vector<int> v;
    for(int i=0;i<4;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    return v;
}
int main() 
{
    for(int i=1;i<13;i++)
    {
        h.push_back(i);
        l.push_back(i);
    }
    vector<int> tmp(12);
    for(int i=0;i<3;i++) 
    {
        vector<int> a=read();
        char s;
        cin>>s;
        vector<int> b=read();
        if(s=='>') 
        {
            s='<';
            swap(a,b);
        }
        if(s=='<')
        {
            h=vector<int>(tmp.begin(),set_intersection(h.begin(),h.end(),b.begin(),b.end(),tmp.begin()));
            l=vector<int>(tmp.begin(),set_intersection(l.begin(),l.end(),a.begin(),a.end(),tmp.begin()));
        }
        else
        {
            a.insert(a.end(),b.begin(),b.end());
            sort(a.begin(),a.end());
            h=vector<int>(tmp.begin(),set_difference(h.begin(),h.end(),a.begin(),a.end(),tmp.begin()));
            l=vector<int>(tmp.begin(),set_difference(l.begin(),l.end(),a.begin(),a.end(),tmp.begin()));
        }
    }
  
    if(h.size()+l.size()==0)
    {
        cout<<"impossible"<<endl;
    } 
    else if(h.size()+l.size()>1)
    {
        cout<<"indefinite"<<endl;
    } 
    else
    {
        if(h.size()) 
        {
            cout<<h[0]<<"+"<<endl;
        }
        else
        {
            cout<<l[0]<<"-"<<endl;
        }
    }
    return 0;
}