#include<iostream>
#include<string>
using namespace std;
int main()
{
int brojac=0;
string ss;
cin>>ss;
for(int i=0;i<ss.size()-1;i++)
{
   if(ss[i]!='a'&&ss[i]!='u'&&ss[i]!='e'&&ss[i]!='i'&&ss[i]!='o')
{
if(ss[i+1]!='a'&&ss[i+1]!='u'&&ss[i+1]!='e'&&ss[i+1]!='i'&&ss[i+1]!='o')
brojac++;
}
 
}
cout<<brojac<<endl;
return 0;
}