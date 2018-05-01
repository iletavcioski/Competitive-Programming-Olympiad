#include <iostream>
using namespace std;
typedef long long ll;
int niza[1000001];
int niza2[1000001];
int n;
ll brojac;
void merge(int niza[],int l,int r)
{ 
    if(r-l<2) 
        return;
    int mid=(l+r+1)/2;
  
    merge(niza,l,mid); 
    merge(niza,mid,r); 
  
    for(int i=l;i<r;i++) 
        niza2[i]=niza[i];
    int i=l;
    int j=mid;
    int k=l;
    while(i<mid&&j<r)
    { 
        if(niza2[i]<niza2[j]) 
        { 
            niza[k]=niza2[i]; 
            i++; 
            k++; 
        }
        else
        {
            brojac+=mid-i; 
            niza[k]=niza2[j]; 
            j++; 
            k++; 
        }
    }
    while(i<mid) 
    { 
        niza[k]=niza2[i]; 
        i++; 
        k++; 
    }
    while(j<mid) 
    { 
        niza[k]=niza2[j]; 
        j++; 
        k++; 
    }
}
int main()
{ 
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>niza[i];
    merge(niza,0,n);
    cout<<brojac<<endl;
    return 0;
}