#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int brojac=0;
    int niza[1000][4];
    int lr;
    int lc;
    for(int i=0;i<n;i++)
    {
        cin>>niza[i][1];
        cin>>niza[i][2];
        cin>>niza[i][3];
        cin>>niza[i][4];
           
    }
    cin>>lr;
        cin>>lc;
    for(int i=n-1;i>=0;i--)
    {
        if((lr>=niza[i][1]&&lr<=((niza[i][1]+niza[i][3])-1))&&(lc>=niza[i][2]&&lc<=((niza[i][2]+niza[i][4])-1)))
        {
            cout<<"prozorec "<<i+1<<endl;
            brojac++;
            break;
        }
    }
    if(brojac==0)
    {
        cout<<"pozadina"<<endl;
    }
    return 0;
}