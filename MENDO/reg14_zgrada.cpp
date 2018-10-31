#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    n=5;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int m;
    cin>>m;
    int brojac=0;
    if(m==1)
    {
        cout<<100<<endl;
        return 0;
    }
    for(int i=0;i<m-1;i++)
    {
        brojac+=v[i];
    }
    if(brojac==0)
    {
        cout<<100<<endl;
        return 0;
    }
    else if(brojac<=5)
    {
        cout<<80<<endl;
        return 0;
    }
    else if(brojac<=20)
    {
        cout<<60<<endl;
        return 0;
    }
    else
    {
        cout<<50<<endl;
        return 0;
    }
    return 0;
}