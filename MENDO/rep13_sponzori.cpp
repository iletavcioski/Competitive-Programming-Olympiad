#include <iostream>
#include <vector>
#include <algorithm>
    
    
using namespace std;
    
int main()
{
    int n;
    int sponzor;
    cin>>n;
    
    vector<int> sponzori;
    vector<int> maximumi;
    
    int zlatniSponzoriMaximum=0;
    int srebreniSpozoriMaximum=0;
    int maxSponzorostvo=0;
    int zlatniSponzori=0;
    int srebreniSponzri=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>sponzor;
        sponzori.push_back(sponzor);
    }
    sort(sponzori.begin(),sponzori.end());
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            srebreniSponzri=sponzori[i]*(j-i);
            zlatniSponzori=sponzori[j]*(n-j);
            if(maxSponzorostvo<(srebreniSponzri+zlatniSponzori))
            {
                maxSponzorostvo=srebreniSponzri+zlatniSponzori;
            }
        }
    
    }
    cout<<maxSponzorostvo<<endl;
    
    return 0;
}