#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    vector<int> v(10,0);
    for(int i=0;i<ss.size();i++)
    {
        v[ss[i]-'0']++;
    }
    v[6]+=v[9];
    v[9]=0;
    if(v[6]%2==1)
        v[6]++;
    v[6]/=2;
    int brojac=0;
    for(int i=0;i<=8;i++)
    {
        brojac=max(brojac,v[i]);
    }
    cout<<brojac<<endl;
    return 0;
}