#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v;
    for(int i=0;i<n.size();i++)
    {
        v1.push_back(n[i]-'0');
        v2.push_back(n[i]-'0');
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v1.begin(),v1.end());
    bool prenos=false;
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
    vector<bool>vv(v.size(),true);
    for(int i=v.size()-1;i>0;i--)
    {
        if(v[i]==0)
            vv[i]=false;
        else
            break;
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(vv[i]==true)
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}