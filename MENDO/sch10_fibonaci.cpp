#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int b1=1;
    int b2=1;
    int brojac=0;
    while(b2<=m)
    {
        if(b2>=n&&b2<=m)
            brojac++;
        int p=b1;
        b1=b2;
        b2=p+b1;
    }
    cout<<brojac<<endl;
    return 0;
}