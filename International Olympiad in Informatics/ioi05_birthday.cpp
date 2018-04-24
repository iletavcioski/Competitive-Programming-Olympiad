#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int niza[1000001];
    int nizarev[1000001];
    for(int i=0;i<n;i++)
    {
        cin>>niza[i];
        niza[i]--;
        nizarev[n-1-i]=niza[i];
        niza[i]=i-niza[i];
        nizarev[n-1-i]=n-1-i-nizarev[n-1-i];
    }
    for(int i=0;i<n;i++)
    {
        if(niza[i]<=-(n/2)) 
            niza[i]+=n;
        else if(niza[i]>n/2)
            niza[i]-=n;
        if(nizarev[i]<=-(n/2))
            nizarev[i]+=n;
        else if(nizarev[i]>n/2) 
            nizarev[i]-=n;
    }
    sort(niza,niza+n);
    sort(nizarev,nizarev+n);
    int maxi=0;
    for(int i=0;i<n-1;i++)
    {
        maxi=max(maxi,niza[i+1]-niza[i]);
        maxi=max(maxi,nizarev[i+1]-nizarev[i]);
    }
    maxi=max(maxi,max(nizarev[0]+n-nizarev[n-1],niza[0]+n-niza[n-1]))-1;
    cout<<(n-maxi)/2<<endl;
    return 0;
}