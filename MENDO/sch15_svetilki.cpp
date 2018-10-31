#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string pozicija;
    int brojac=0;
    int p=0;
    int b;
    cin>>pozicija;
    for(int i=0;i<pozicija.size();i++)
    {
        if(pozicija[i]=='Y')
        {
            b=(i+1);
            p=i;
            brojac++;
            while(p<pozicija.size())
            {
  
                if(p>=pozicija.size())
                {
                    break;
                }
                if(pozicija[p]=='Y')
                {
                    pozicija[p]='N';
                }
                else if(pozicija[p]=='N')
                {
                    pozicija[p]='Y';
                }
                p+=b;
            }
            p=0;
        }
    }
    cout<<brojac<<endl;
    return 0;
}