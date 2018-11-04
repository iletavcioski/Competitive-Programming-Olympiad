#include<iostream>
#include<iomanip>
using namespace std;
int n;
double k;
double d[100000];
bool mozi(double t)
{
  double x=d[0]+t;
  for(int i=1;i<n;i++)
  {
     if(d[i]-t>x+k)
     return 0;
     x=min(x+k,d[i]+t);
  }
  return 1;
}
int main()
 {
   cin>>k>>n;
   for(int i=0;i<n;i++)
    cin>>d[i];
   double l=0.0,r=1e9;
   for(int i=0;i<100;i++)
    {
      double mid=(l+r)/2.0;
      if(mozi(mid))
        r=mid;
      else l=mid;
   }
   cout<<fixed<<setprecision(3);
   cout<<l<<endl;
   return 0;
}