#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int suma;
    int razlika;
    int suma1;
    int casovi2=0;
    int casovi=0;
    int casovi1=0;
    cin>>a;
    cin>>b;
    cin>>suma;
    if(suma>=(a*100))
    {
        razlika=suma-(a*100);
        casovi1=100;
        casovi2=razlika/b;
        casovi=casovi1+casovi2;
    }
    else
    {
        suma1=suma;
        while(suma>=a)
        {
            suma=suma-a;
            casovi1++;
            if(a>suma)
            {
                break;
            }
        }
           
        razlika=suma1-(casovi1*a);
        if(razlika<b)
        {
            casovi2=1;
        }
        else
        {
        casovi2=razlika/b;
        }
        casovi=casovi1+casovi2;
    }
     if((casovi1*a)+(casovi2*b)<suma)
    {
    cout<<casovi+1<<endl;
    }
    else
    {
        cout<<casovi<<endl;
    }
    return 0;
}