#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> vec;
    vector<pair<string,string> > v;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        maxi=max(maxi,(int)ss.size());
        vec.push_back(ss);
    }
    int brojce;
    for(int i=1;i<=5040;i++)
    {
        bool cc=true;
        for(int j=0;j<vec.size();j++)
        {
            if(i%vec[j].size()!=0){
                cc=false;
            break;
            }
        }
        if(cc)
        {
            brojce=i;
            break;
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        string s1="";
        while(s1.size()<brojce)
            s1+=vec[i];
        v.push_back(make_pair(s1,vec[i]));
    }
    string sk="";
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        sk+=v[i].second;
    cout<<sk<<endl;
    return 0;
}