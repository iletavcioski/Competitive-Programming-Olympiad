#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
    int minuti1;
    int minuti2;
    int cas1;
    int cas2;
    int brojacm=0;
    int brojach=0;
    int brojac;
    cin>>cas1;
    cin>>minuti1;
    if(minuti1<51)
    {
        minuti2=minuti1+10;
        cas2=cas1;
    }
    if(minuti1>=51)
    {
        minuti2=(minuti1+10)-60;
        cas2=cas1+1;
    }
    if(minuti1<minuti2)
    {
        brojacm=brojacm+11;
    }
    else if(minuti1>minuti2)
    {
        brojacm=brojacm+11;
    }
    if(minuti1>=50)
    {
        if(cas1==19||cas1==23||cas1==9)
        {
            brojach=brojach+2;
        }
        else
        {
            brojach=brojach+1;
        }
    }
  
    brojac=brojach+brojacm;
    cout<<brojac<<endl;
    return 0;
}