#include<iostream>
using namespace std;
int main()
{
    int cas1;
    int minuti1;
    int cas2;
    int minuti2;
    int cas3;
    int minuti3;
    cin>>cas1>>minuti1;
    cin>>cas2>>minuti2;
    if(minuti2<minuti1)
    {
        minuti2=minuti2+60;
        cas2=cas2-1;
    }
    if(cas2<cas1)
    {
        cas2=cas2+24;
    }
       
    minuti3=minuti2-minuti1;
    cas3=cas2-cas1;
    if(cas3==0||cas3==1||cas3==2||cas3==3||cas3==4||cas3==5||cas3==6||cas3==7||cas3==8||cas3==9)
    {
        if(minuti3==0||minuti3==1||minuti3==2||minuti3==3||minuti3==4||minuti3==5||minuti3==6||minuti3==7||minuti3==8||minuti3==9)
        {
            cout<<"0"<<cas3<<":"<<"0"<<minuti3<<endl;
        }
        else
        {
            cout<<"0"<<cas3<<":"<<minuti3<<endl;
        }
    }
    else
    {
        if(minuti3==0||minuti3==1||minuti3==2||minuti3==3||minuti3==4||minuti3==5||minuti3==6||minuti3==7||minuti3==8||minuti3==9)
        {
            cout<<cas3<<":"<<"0"<<minuti3<<endl;
        }
        else
        {
        cout<<cas3<<":"<<minuti3<<endl;
        }
    }
       
   
    return 0;
}