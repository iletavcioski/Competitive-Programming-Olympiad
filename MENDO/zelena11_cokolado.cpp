#include<iostream>
#include<string>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    char s;
    cin>>s;
     bool cc=false;
    if(ss[0]==s)
        cc=true;
    int brojac=0;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]==s)
        {
            if(!cc)
            {
                cc=true;
                brojac++;
            }
        }
        else
        {
            if(cc)
            {
                cc=false;
                brojac++;
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}