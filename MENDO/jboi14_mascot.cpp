#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int brojac=1;
    int pocetno=0;
    int krajno=n-1;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>=v[i+1])
            brojac++;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int b,c;
            cin>>b>>c;
            int poz=(pocetno+b-1)%n;
            int cc=v[poz];
            int pozp=(poz+1)%n;
            int pozm=(poz-1+n)%n;
            v[poz]=c;
            if(pocetno!=poz&&v[poz]>v[pozm]&&cc<=v[pozm])
                brojac--;
            if(pocetno!=poz&&v[poz]<=v[pozm]&&cc>v[pozm])
                brojac++;
            if(krajno!=poz&&v[poz]>=v[pozp]&&cc<v[pozp])
                brojac++;
            if(krajno!=poz&&v[poz]<v[pozp]&&cc>=v[pozp])
                brojac--;
             
        }
        else
        {
            int b;
            cin>>b;
            int poz=(pocetno+b-1)%n;
            int poz1=(poz+1)%n;
            if(v[poz]>=v[poz1])
                brojac--;
            if(v[krajno]>=v[pocetno])
                brojac++;
            pocetno=poz1;
            krajno=poz;
        }
        cout<<brojac<<endl;
    }
    return 0;
}