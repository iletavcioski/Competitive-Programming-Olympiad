#include <iostream>
using namespace std;
int main()
{
    bool mat[2000003];
    for(int i=0;i<=2000001;i++)
        mat[i]=false;
    int n;
    cin>>n;
    int val[100005];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        mat[val[i]]=true;
    }
    int nn;
    cin>>nn;
    int brojac=0;
    for(int i=0;i<n;i++)
    {
        if(nn>=val[i]){
        if(mat[nn-val[i]])
            brojac++;
    }
    }
    brojac/=2;
    cout<<brojac<<endl;
    return 0;
}