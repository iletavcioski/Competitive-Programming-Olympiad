#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        v.push_back(ss);
    }
    for(int i=0;i<v.size();i++)
    {
        string ss="";
 bool cc=true;
        for(int ii=0;ii<v[i].size();ii++)
        {
            ss+=v[i][ii];
            cc=true;
            for(int j=0;j<v.size();j++)
            {
                if(i!=j)
                {
                    string sk=v[j].substr(0,ss.size());
 
                    if(sk==ss)
                    {
                        cc=false;
                        break;
                    }
                }
                if(!cc)
                    break;
            }
            if(cc)
            {
                cout<<ss<<endl;
                cc=true;
                break;
            }
        }
    }
    return 0;
}