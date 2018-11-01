#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    string s="";
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]+n<=122)
            s+=ss[i]+n;
        else
        {
            int razlika=((ss[i]+n)-122);
            s+=(122-razlika);
        }
    }
    cout<<s<<endl;
    return 0;
}