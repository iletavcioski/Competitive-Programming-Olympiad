#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k,l,n;
    cin>>k>>l>>n;
    int mat[1000001];
    for(int i=1;i<=1000000;i++)
        mat[i]=0;
    mat[0]=0;
 
    for(int i=1;i<=1000000;i++)
    {
        if(mat[i-1]==false)
            mat[i]=true;
        if(i-k>=0&&mat[i-k]==false)
            mat[i]=true;
        if(i-l>=0&&mat[i-l]==false)
            mat[i]=true;
    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(mat[a]==1)
        cout<<'A';
        else
            cout<<'B';
    }
    cout<<endl;
    return 0;
}