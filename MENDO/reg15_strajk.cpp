#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    int zbir;
    int brojac=0;
    cin>>n;
    if(n<=15)
    {
        cout<<brojac<<endl;
        return 0;
    }
    else
    {
        zbir=n-15;
        while(zbir>0)
        {
            zbir=zbir-5;
            brojac++;
            if(zbir<=0)
            {
                break;
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}