#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int v1[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    vector<vector<string> > v;
    vector<string> vec;
    v.insert(v.begin(),26,vec);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        v[ss[0]-'a'].push_back(ss);
    }
    for(int i=0;i<26;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=0;i<k;i++)
    {
        char a;
        cin>>a;
        cout<<v[a-'a'][v1[a-'a']]<<endl;
        if(v1[a-'a']==v[a-'a'].size()-1)
            v1[a-'a']=0;
        else
            v1[a-'a']++;
    }
    return 0;
}