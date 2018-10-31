#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int mod=1e6+7;
int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
    int t;  
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        int w[101];
        memset(w,0,sizeof(w));
        int n;
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int b;
            cin>>b;
            v.push_back(b);
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<25;j++)
            {
                if(v[i]==primes[j])
                    break;
                if(v[i]%primes[j]==0)
                {   
                    v[i]/=primes[j];
                    v.push_back(primes[j]);
                    j--;
                }
            }
            w[v[i]]++;
        }
        int brojac=1;
        for(int i=0;i<=100;i++)
        {
            if(w[i]%2==1)
                brojac=(brojac*i)%mod;
        }
        cout<<brojac<<endl;
    }
    return 0;
}