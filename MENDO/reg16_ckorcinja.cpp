#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat[11];
    mat[1]=3;
    mat[2]=5;
    mat[3]=5;
    mat[4]=4;
    mat[5]=5;
    mat[6]=5;
    mat[7]=3;
    mat[8]=7;
    mat[9]=5;
    mat[0]=6;
    int maxi=-1;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int l=0;l<=9;l++)
            {
                for(int k=0;k<=9;k++)
                {
                    if(mat[i]+mat[j]+mat[k]+mat[l]==n)
                    {
                        maxi=max(maxi,i*1000+j*100+k*10+l);
                    }
                }
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}