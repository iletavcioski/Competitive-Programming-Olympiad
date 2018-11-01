#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long k;
    cin>>k;
    vector<long long> v;
    long long zbir=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        zbir+=a;
        v.push_back(a);
    }
    if(k>=zbir)
    {
        cout<<0<<endl;
        return 0;
    }
    while(true)
    {
        long long broj=0;
        long long maxi=99999999999;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0){
                maxi=min(maxi,v[i]);broj++;}
        }
        if(k==0)
        {
            cout<<broj<<endl;
            return 0;
        }
        if(maxi==9999999){
            cout<<0<<endl;
            return 0;
        }
        if(k>=maxi*broj){
            k-=maxi*broj;
            for(int i=0;i<v.size();i++)
                if(v[i]>0)
                v[i]-=maxi;
        }
        else
        {
            int bbb=k/broj;
            int ccc=bbb;
            if(k%broj!=0)
            ccc=k%broj;
            for(int i=0;i<v.size();i++)
                if(v[i]>0)
                v[i]-=bbb;
            if(k%broj!=0)
            {
                for(int i=0;i<ccc;i++)
                    if(v[i]>0)
                    v[i]--;
            }
            k=0;
        }
    }
    return 0;
}