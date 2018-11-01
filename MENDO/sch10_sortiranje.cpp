#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Izbor
{
    double broj;
    string ss;
};
bool compare(const Izbor &x,const Izbor &y)
{
    if(x.broj<y.broj)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    vector<Izbor> v;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        double brojac=0;
        for(int j=0;j<s1.size();j++)
        {
            brojac+=((int)(s1[j]-64));
        }
        double kk=brojac/s1.size();
        Izbor g;
        g.ss=s1;
        g.broj=kk;
        v.push_back(g);
    }
    stable_sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++)
    {
        cout<<v[i].ss<<endl;
    }
    return 0;
}