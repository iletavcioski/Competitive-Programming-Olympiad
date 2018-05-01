#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int matrica[51][51];
    bool mat[51][51];
    memset(mat,false,sizeof(mat));
    int brojac=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrica[i][j];
                
        }
    }
    int broj1;
    int broj2;
    for(int i=0;i<n;i++)
    {
        broj1=0;
        broj2=0;
        for(int j=0;j<n;j++)
        {
                
            if(mat[i][j]==false&&matrica[i][j]>broj1)
            {
                brojac++;
                broj1=matrica[i][j];
                mat[i][j]=true;
            }
            if(mat[i][(n-1)-j]==false&&matrica[i][(n-1)-j]>broj2)
            {
                brojac++;
                broj2=matrica[i][(n-1)-j];
                mat[i][(n-1)-j]=true;
            }
            broj1=max(matrica[i][j],broj1);
            broj2=max(matrica[i][(n-1)-j],broj2);
        }
    }
    for(int j=0;j<n;j++)
    {
        broj1=0;
        broj2=0;
        for(int i=0;i<n;i++)
        {
                
            if(mat[i][j]==false&&matrica[i][j]>broj1)
            {
                brojac++;
                broj1=matrica[i][j];
                mat[i][j]=true;
            }
            if(mat[(n-1)-i][j]==false&&matrica[(n-1)-i][j]>broj2)
            {
                brojac++;
                broj2=matrica[(n-1)-i][j];
                mat[(n-1)-i][j]=true;
            }
               
                broj1=max(matrica[i][j],broj1);
                broj2=max(matrica[(n-1)-i][j],broj2);
        }
    }
    cout<<brojac<<endl;
    return 0;
}