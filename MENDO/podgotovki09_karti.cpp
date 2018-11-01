#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int brojac1=0;
    int brojac2=0;
    vector<int> v1(n+1,0);
    int zbir1=0;
    int zbir2=0;
    vector<int> v2(n+1,0);
    for(int i=0;i<n;i++)
    {
        if((v[i]+zbir1)%2!=0)
        {
            v1[i]=1;
        }
        if(i>=k-1)
            zbir1+=v1[i]-v1[i-k+1];
        else
            zbir1+=v1[i];
        brojac1+=v1[i];
        if(i>n-k&&v1[i]!=0){
            brojac1=1e9;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if((v[i]+zbir2)%2!=1)
        {
            v2[i]=1;
        }
        if(i>=k-1)
            zbir2+=v2[i]-v2[i-k+1];
        else
            zbir2+=v2[i];
        brojac2+=v2[i];
        if(i>n-k&&v2[i]!=0){
            brojac2=1e9;
            break;
        }
    }
    int brojac=min(brojac1,brojac2);
    if(brojac==1e9)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        cout<<brojac<<endl;
    }
    return 0;
}