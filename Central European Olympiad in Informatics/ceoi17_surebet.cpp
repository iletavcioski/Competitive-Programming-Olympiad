#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<double> v1,v2;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    int i=1,j=1;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    double maxi=min(v1[0],v2[0])-2;
    double br=2;
    double b1=v1[0],b2=v2[0];
    while(i<n||j<n)
    {

        //cout<<i<<" "<<j<<" "<<b1<<" "<<b2<<endl; 
        //cout<<maxi<<endl;
        double a,b;
        if(i<n)
            a=min(b1+v1[i]-(br+1),b2-(br+1));
        else
            a=0;
        if(j<n)
            b=min(b2+v2[j]-(br+1),b1-(br+1));
        else
            b=0;
        if(a>b)
        {
            maxi=max(maxi,a);
            b1+=v1[i];
            i++;
            br++;
            if(i==n)
                break;
        }
        else
        {
            maxi=max(maxi,b);
            b2+=v2[j];
            j++;
            br++;
            if(j==n)
                break;
        }
    }
    cout<<fixed<<setprecision(4);
    cout<<max(maxi,0.0000)<<endl;
    return 0;
}