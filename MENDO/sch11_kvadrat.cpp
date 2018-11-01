#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat[100][100];
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        int brojac=0;
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
            brojac+=mat[i][j];
        }
        if(maxi==0)
            maxi=brojac;
        if(maxi!=0)
        {
            if(maxi!=brojac)
            {
                cout<<abs(maxi-brojac)-1<<endl;
                return 0;
            }
        }
    }
    return 0;
}