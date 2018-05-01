#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    int v[101];
    int brojac=0;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int g=k+1;g<n;g++)
                {
                    if(v[i]*v[k]==v[g]*v[j])
                        brojac++;
                }
            }
        }
    }
    cout<<brojac;
    return 0;
}