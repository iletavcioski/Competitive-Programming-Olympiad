#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    pair<ll,int> mm=make_pair(-1,-1);
     vector<vector<pair<ll,int> > >mat;
     vector<pair<ll,int> >vec;
     vec.insert(vec.begin(),50005,mm);
     mat.insert(mat.begin(),66,vec);
     
    int gg=0;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        for(int j=ss.size()-1;j>=0;j--)
        {
            int jj=j;
            int broj=0;
            ll brojka=0;
            while(1)
            {
                if(ss[jj]=='b')
                brojka+=pow(2,(double)broj);
                mat[broj+1][gg]=make_pair(brojka,(1<<i));
                broj++;
                jj--;
                if(broj==60||jj==-1)
                    break;
            }
            gg++;
        }
 
    }
    int maxi=0;
    for(int i=60;i>=0;i--)
    {
        sort(mat[i].begin(),mat[i].end());
        reverse(mat[i].begin(),mat[i].end());
    }
    for(int i=60;i>=0;i--)
    {
        ll ocekuva=-1;
        int bit=0;
        for(int j=0;j<mat[i].size();j++)
        {
            if(ocekuva==-1)
            {
                ocekuva=mat[i][j].first;
                bit|=mat[i][j].second;
            }
            else if(ocekuva==mat[i][j].first)
            {
                bit|=mat[i][j].second;
            }
            else
            {
                if(bit==(1<<n)-1)
                    maxi=max(maxi,i);
                ocekuva=mat[i][j].first;
                bit=mat[i][j].second;
            }
        }
    }
     
    cout<<maxi<<endl;
    return 0;
}