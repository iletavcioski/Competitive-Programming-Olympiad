#include<iostream>
using namespace std;
int main()
{
    int t1;
    int t2;
    int t3;
    int t4;
    int t5=0;
    double average;
    int ocena;
    int poeni;
    cin>>ocena;
    cin>>t1;
    cin>>t2;
    cin>>t3;
    cin>>t4;
    if(ocena==1)
    {
        cout<<"0"<<endl;
    }
    else if(ocena==2)
    {
        poeni=60;
    }
    else if(ocena==3)
    {
        poeni=70;
    }
    else if(ocena==4)
    {
        poeni=80;
    }
    else if(ocena==5)
    {
        poeni=90;
    }
    for(int i=0;i<=100;i++)
    {
        t5=t5+i;
        average=(t1+t2+t3+t4+t5)/5;
        if(average>=poeni)
        {
            cout<<i<<endl;
            return 0;
        }
        t5=t5-i;
           
    }
    cout<<"GRESHKA"<<endl;
    return 0;
}