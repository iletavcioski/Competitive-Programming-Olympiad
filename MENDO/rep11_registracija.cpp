#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s.find(ss)!=-1)
        {
            v.push_back(s);
        }
    }
    vector<bool>vv(5000,false);
    for(int i=0;i<v.size();i++)
    {
        string broj="";
        for(int j=v[i].size()-1;j>=0;j--)
        {
            if(v[i][j]>='0'&&v[i][j]<='9')
                broj+=v[i][j];
            else
                break;
        }
        if(broj.size()==0)
            vv[0]=true;
        else
        {
            int k=0;
            for(int j=0;j<broj.size();j++)
            {
                double kkk=j;
                k+=(broj[j]-'0')*pow(10,kkk);
            }
            vv[k]=true;
        }
    }
    for(int i=0;i<vv.size();i++)
    {
        if(vv[i]==false)
        {
            if(i!=0)
            {
            cout<<ss<<i<<endl;
            return 0;
            }
            else
            {
                cout<<ss<<endl;
                return 0;
            }
        }
    }
    return 0;
}