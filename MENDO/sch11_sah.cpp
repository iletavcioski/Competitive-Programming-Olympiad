#include<iostream>
#include<vector>
using namespace std;
int main()
{
    char p;
    int p2;
    int br;
    char p1;
    int br1;
    vector<int> pozicija;
    vector<int> broj;
    int n;
    int rezultat=0;
    cin>>p;
    cin>>br;
    p2=p-'0';
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p1;
        cin>>br1;
        pozicija.push_back(p1-'0');
        broj.push_back(br1);
    }
    for(int i=0;i<broj.size();i++)
    {
        if(pozicija[i]==p2+1&&broj[i]==br+2)
        {
            rezultat++;
        }
        if(pozicija[i]==p2-1&&broj[i]==br+2)
        {
            rezultat++;
        }
        if(pozicija[i]==p2-2&&broj[i]==br+1)
        {
            rezultat++;
        }
        if(pozicija[i]==p2-2&&broj[i]==br-1)
        {
            rezultat++;
        }
        if(pozicija[i]==p2-1&&broj[i]==br-2)
        {
            rezultat++;
        }
        if(pozicija[i]==p2+1&&broj[i]==br-2)
        {
            rezultat++;
        }
        if(pozicija[i]==p2+2&&broj[i]==br-1)
        {
            rezultat++;
        }
        if(pozicija[i]==p2+2&&broj[i]==br+1)
        {
            rezultat++;
        }
    }
    cout<<rezultat<<endl;
    return 0;
}