#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int>kraen;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        vector<int> vv;
        for(int j=0;j<n;j++)
        {
            int bb;
            cin>>bb;
            if(bb%2==0)
            v.push_back(bb);
            else
                vv.push_back(bb);
        }
        sort(v.begin(),v.end(),greater<int>());
        sort(vv.begin(),vv.end(),greater<int>());
        int vi=0,vj=0;
        int kjk=true;
        int vvi=0,vvj=0;
        vector<int> kraj;
        vector<int>kraj2;
        int broje1=0;
        int broje2=0;
        while(vi<v.size()||vj<vv.size())
        {
            if(vi<v.size())
            {
            if(broje1==0)
            {
            kraj.push_back(v[vi]);
            broje1++;
            broje2=0;
            vi++;
            }
            else
                vi++;
            }
            if(vj<vv.size())
            {
            if(broje2==0)
            {
                kraj.push_back(vv[vj]);
                broje2++;
                broje1=0;
                vj++;
            }
            else
                vj++;
            }
        }
         vi=0;
         vj=0;
         broje2=0;
         broje1=0;
        while(vi<vv.size()||vj<v.size())
        {
            if(vi<vv.size())
            {
            if(broje2==0)
            {
            kraj2.push_back(vv[vi]);
            broje2++;
            broje1=0;
            vi++;
            }
            else
                vi++;
            }
            if(vj<v.size())
            {
            if(broje1==0)
            {
                kraj2.push_back(v[vj]);
                broje1++;
                broje2=0;
                vj++;
            }
            else
                vj++;
            }
        }
        int brojace1=0;
        int brojace2=0;
        for(int j=kraj.size()-1;j>=0;j--)
        {
            double cc=kraj.size()-j-1;
            int broj=pow(10,cc)+0.00000001;
            brojace1+=(kraj[j]*broj);
        }
        for(int j=kraj2.size()-1;j>=0;j--)
        {
            double cc=kraj2.size()-j-1;
            int broj=pow(10,cc)+0.00000001;
            brojace2+=(kraj2[j]*broj);
        }
        kraj.clear();
        kraj2.clear();
        v.clear();
        vv.clear();
        kraen.push_back(max(brojace1,brojace2));
    }
    for(int i=0;i<kraen.size();i++)
    {
        cout<<kraen[i]<<endl;
    }
    return 0;
}