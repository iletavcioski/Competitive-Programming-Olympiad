#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string ss;
    cin>>ss;
    int brojac=0;
    for(int i=0;i<k;i++)
    {
        map<char,int> m;
        int maxi=0;
        for(int j=i;j<n;j+=k)
        {
            m[ss[j]]++;
            maxi=max(maxi,m[ss[j]]);
        }
        brojac+=((n/k)-maxi);
    }
    cout<<brojac<<endl;
    return 0;
}