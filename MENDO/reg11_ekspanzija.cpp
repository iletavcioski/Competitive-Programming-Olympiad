#include<iostream>
#include<string>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    bool cc=false;
    string sk="";
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]>='2'&&ss[i]<='9')
        {
            int bb=ss[i]-'0';
            i++;
            for(int j=0;j<bb;j++)
                sk+=ss[i];
        }
        else
            sk+=ss[i];
    }
    cout<<sk<<endl;
    return 0;
}