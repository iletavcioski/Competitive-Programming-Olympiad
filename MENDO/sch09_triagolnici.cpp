#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> x;
    vector<int> y;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    int brojac=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i<j&&j<k)
                {
                    int d1=(pow(x[i]-x[j],2.00)+pow(y[i]-y[j],2.00));
                    int d2=(pow(x[i]-x[k],2.00)+pow(y[i]-y[k],2.00));
                    int d3=(pow(x[j]-x[k],2.00)+pow(y[j]-y[k],2.00));
                    if(d1+d2==d3||d2+d3==d1||d1+d3==d2)
                        brojac++;
                }
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}