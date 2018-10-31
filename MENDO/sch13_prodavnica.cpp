#include<iostream>
using namespace std;
int main()
{
int p,v;
cin>>p>>v;
int broj=v-p;
int brojac=0;
while(broj>=5)
broj-=5,brojac++;
while(broj>=2)
broj-=2,brojac++;
while(broj>=1)
broj-=1,brojac++;
 
cout<<brojac<<endl;
return 0;
}