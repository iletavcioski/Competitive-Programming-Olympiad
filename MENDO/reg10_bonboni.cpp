#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int paketi=1;
    vector<int> nino,tino;
    nino.push_back(n);
    while(n)
    {
        if(n%3==2)
        {
            n/=3;
            n++;
            nino.push_back(paketi);
        }
        else if(n%3==1)
        {
            n/=3;
            tino.push_back(paketi);
        }
        else
            n/=3;
        paketi*=3;
    }
    sort(nino.begin(),nino.end());
    for(int i=0;i<nino.size();i++)
    {
        if(i!=nino.size()-1)
            cout<<nino[i]<<" ";
        else
            cout<<nino[i]<<endl;;
    }
    for(int i=0;i<tino.size();i++)
    {
        if(i!=tino.size()-1)
            cout<<tino[i]<<" ";
        else
            cout<<tino[i]<<endl;;
    }
    return 0;
}