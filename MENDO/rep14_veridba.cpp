#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int a;
    int b;
    int broj;
    cin>>a>>b;
    cin>>broj;
    int dolzina=1;
    bool k=true;
    bool prost=true;
    vector<int> vi;
    vector<int> vj;
    for(int i=2;i<=sqrt((double)broj);i++)
    {
        if(broj%i==0)
        {
            prost=false;
            break;
        }
    }
    if(prost)
    {
        cout<<-1<<endl;
        return 0;
    }
    int dolzinaa=1;
    while(k)
    {
        if(dolzina>sqrt((double)broj))
            break;
        if(broj%dolzina==0&&((broj/dolzina<=a&&dolzina<=b)||(broj/dolzina<=b&&dolzina<=a)))
        {
            vi.push_back(min(broj/dolzina,dolzina));
            vj.push_back(max(broj/dolzina,dolzina));
        }
            dolzina++;
    }
      
    if(a>b)
    {
        swap(a,b);
    }
    if(vi.size()==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    int brojcence=vi.size();
    for(int i=0;i<brojcence;i++)
    {
        vi.push_back(vj[i]);
        vj.push_back(vi[i]);
    }
    int brojac=9999999;
    for(int i=0;i<vi.size();i++)
    {
        if(a>=vi[i]&&b>=vj[i])
        {
        int kkk=0;
        if(a>vi[i])
            kkk++;
        if(b>vj[i])
            kkk++;
      brojac=min(kkk,brojac);
        }
    }
    cout<<brojac<<endl;
    return 0;
}