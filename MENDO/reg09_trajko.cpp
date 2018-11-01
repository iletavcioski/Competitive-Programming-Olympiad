#include<iostream>
#include<string>
using namespace std;
int main()
{
   string ss;
   cin>>ss;
   string sss="";
   long long brojac=1;
   for(int i=0;i<ss.size();i++)
   {
       if(ss[i]<96)
       {
           sss+=ss[i]+32;
       }
       else
        sss+=ss[i];
       if(sss=="minus")
       {
        brojac--;
        sss="";
       }
       else if(sss=="troduplo")
       {
        brojac*=3;
        sss="";
       }
       else if(sss=="duplo")
       {
        brojac*=2;
        sss="";
        }
   }
   cout<<brojac<<endl;
   return 0;
}