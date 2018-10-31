#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int brojac=0;
    for(int i=n;i<=m;i++)
    {
        if(i>=0&&i<10)
            brojac++;
        else if(i>=10&&i<=99)
            brojac+=2;
        else if(i>=100&&i<=999)
            brojac+=3;
        else
            brojac+=4;
    }
    int broj=brojac;
    for(int i=1;i<=brojac;i++)
    {
        if(i%k==0)
            broj--;
    }
    cout<<broj<<endl;
    return 0;
}