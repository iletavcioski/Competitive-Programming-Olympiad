#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v(30,0);
    for(int i=0;i<26;i++)
    {
        char b;
        cin>>b;
        int vrednost;
        cin>>vrednost;
        int kk=b-96;
        v[kk]=vrednost;
    }
    int n;
    cin>>n;
    int maxi=0;
    string maxx;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        int brojac=0;
        for(int j=0;j<ss.size();j++)
        {
            int kkk=ss[j];
            if(kkk>=97&&kkk<=122)
            {
                brojac+=v[kkk-96];
            }
            else
            {
                brojac+=(v[kkk-64]+21);
            }
        }
        if(brojac>maxi)
        {
            maxi=brojac;
            maxx=ss;
        }
    }
    cout<<maxx<<endl;
    return 0;
}