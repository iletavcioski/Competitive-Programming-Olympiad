#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    int brojac=0;
    while(1)
    {
        int maxi=1e9;
        bool krajj=false;
        int maxxi=0;
        int l=-1,r=-1;
        int orr=-1;
        for(int i=0;i<n;i++)
        {
 
            if(v1[i]>v2[i])
            {
                krajj=true;
                int poc=i;
                int kraj=poc;
                while(v1[i]>v2[i])
                {
                    kraj=i;
                    i++;
                    if(i==n)
                        break;
                }
                i=kraj;
                if(maxxi<kraj-poc+1)
                {
                     maxxi=kraj-poc+1;
                     orr=1;
                     l=poc,r=kraj;
                }
 
            }
            else if(v2[i]>v1[i])
            {
                krajj=true;
                int poc=i;
                int kraj=poc;
                while(v2[i]>v1[i])
                {
                    kraj=i;
                    i++;
                    if(i==n)
                        break;
                }
                i=kraj;
                if(maxxi<kraj-poc+1)
                {
                     maxxi=kraj-poc+1;
                     orr=2;
                     l=poc,r=kraj;
                }
            }
        }
        if(r!=-1)
                {
                    for(int j=l;j<=r;j++)
                        maxi=min(maxi,(int)abs(v1[j]-v2[j]));
                    for(int j=l;j<=r;j++)
                        {
                            if(orr==2){
                                v1[j]+=maxi;
                                 
                            }
                            else
                            {
                                v1[j]-=maxi;
                               
                            }
                        }
 
                    brojac+=maxi;
                    maxi=1e9;
                }
        if(!krajj)
            break;
    }
    cout<<brojac<<endl;
    return 0;
}