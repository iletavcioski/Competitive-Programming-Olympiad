#include<iostream>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    int brojac=0;
    for(int i=0;i<ss.size();i++)
        brojac+=ss[i]-'0';
    int b=brojac;
    int g=0;
    while(brojac%9!=0)
    {
        brojac+=b;
        g++;
    }
    cout<<g<<endl;
    return 0;
}