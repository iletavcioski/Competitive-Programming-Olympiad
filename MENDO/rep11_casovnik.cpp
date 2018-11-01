#include <iostream>
using namespace std;
int main()
{
    int h1;
    int h2;
    int m1;
    int m2;
    cin>>h1;
    cin>>m1;
    cin>>h2;
    cin>>m2;
    int pm=0;
    int ph=0;
    int p=0;
    if(0<=h1&&h1<=23&&0<=h2&&h2<=23&&0<=m1&&m1<=59&&0<=m2&&m2<=59)
    {
        if(h1<h2)
        {
            if(h2-h1>12)
            {
                if(h1==0&&h2==23)
                    ph=1;
                    else
                ph=h1+24-h2;
            }
            else
            {
                ph=h2-h1;
            }
        }
        else
        {
                if(h1-h2>12)
                {
                    if(h1==23&&h2==0)
                    ph=1;
                    else
                    ph=24-h1+h2;
                }
                else
                {
                    ph=h1-h2;
                }       
        }
        if(m1<m2)
        {
            if(m2-m1==30)
            {
                if(h1<12)
                {
                    pm=m2-m1-1;
                }
                else if(h2>h1)
                {
                    pm=m2-m1;
                }               
                else if(h1+24>h2)
                {
                    pm=m2-m1-1;
                }
            }
            else if(m2-m1>30)
            {
                pm=m1+60-m2+1;
            }
                  
            else
            {
                pm=m2-m1;
            }
     
        }
        else
        {
                if(m1-m2>=30)
                {
      
                    pm=60-m1+m2-1;
                }
                else
                {
                    pm=m1-m2;
                }
                     
      
        }
                
     
     
     
     
     
      
             
     p=pm+ph;     
        cout<<p<<endl;
    }
          
    return 0;
}