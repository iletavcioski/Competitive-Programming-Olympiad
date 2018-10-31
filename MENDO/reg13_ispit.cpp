#include <iostream>
  
using namespace std;
  
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b)
    {
        cout<<a*2-1<<endl;
    }
    else if(a>b)
    {
        cout<<b*2-2<<endl;
    }
    else
        cout<<a*2-2<<endl;
          
      
    return 0;
}