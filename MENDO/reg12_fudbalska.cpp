#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int kk;
    cin>>kk;
    int nat=(2*n)-2;
    int pobedi=999999,porazi=999999,nereseno=999999;
    for(int i=0;i<=nat;i++)
    {
        for(int j=0;j<=nat;j++)
        {
            for(int k=0;k<=nat;k++)
            {
                if(i+j+k==nat&&(3*i+j)==kk)
                {
                    if(k<porazi)
                        pobedi=i,nereseno=j,porazi=k;
                }
            }
        }
    }
    cout<<pobedi<<" "<<nereseno<<" "<<porazi<<endl;
    return 0;
}