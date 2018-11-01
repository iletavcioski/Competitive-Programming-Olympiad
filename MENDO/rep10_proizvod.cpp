#include<iostream>
#include<vector>
using namespace std;
int main()
{
    double n;
    double k;
    cin>>n>>k;
    n*=100;
    k*=100;
    int nn=(n+0.1);
    int kk=(k+0.1);
    for(int i=min(nn,kk);i>=0;i--)
    {
        if(nn%i==0&&kk%i==0)
        {
            int vkupno=nn/i;
            int kkk=kk/i;
            cout<<"KUPI "<<kkk<<" DOBIJ "<<(vkupno-kkk)<<" GRATIS"<<endl;
            return 0;
        }
    }
    return 0;
}