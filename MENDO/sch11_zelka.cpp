#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int brojac=0;
    int den=0;
    while(brojac<=n)
    {
        den++;
        brojac+=a;
        if(brojac>=n){
            cout<<den<<endl;
            return 0;
        }
        brojac-=b;
    }
 
}