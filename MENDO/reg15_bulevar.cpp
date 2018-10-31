#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    vector<int> parni;
    vector<int>neparni;
    bool parnite[10000];
    bool neparnite[10000];
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            parni.push_back(i);
        }
        else
        {
            neparni.push_back(i);
        }
    }
    int n;
    int rastojanie;
    cin>>rastojanie;
    cin>>n;
    int zafateni;
    memset(parnite,false,sizeof(parnite));
    memset(neparnite,false,sizeof(neparnite));
    for(int i=0;i<n;i++)
    {
        cin>>zafateni;
        if(zafateni%2==0)
        {
            for(int j=0;j<parni.size();j++)
            {
                if(zafateni==parni[j])
                {
                    for(int k=j;k<=(j+rastojanie);k++)
                    {
                        parnite[k]=true;
                    }
                }
            }
        }
        else
        {
            for(int j=0;j<neparni.size();j++)
            {
                if(zafateni==neparni[j])
                {
                    for(int g=j;g<=(j+rastojanie);g++)
                    {
                        neparnite[g]=true;
                    }
                }
            }
        }
    }
    int brojac=0;
    int brojac1=0;
    for(int i=0;i<parni.size();i++)
    {
        brojac1=0;
        if(parnite[i]==false)
        {
            for(int j=i;j<=(i+rastojanie);j++)
            {
                if(parnite[j]==true)
                {
                    brojac1++;
                }
            }
            if(brojac1==0)
            {
                brojac++;
                for(int k=i;k<=(i+rastojanie);k++)
                {
                    parnite[k]=true;
                }
            }
        }
    }
    for(int i=0;i<neparni.size();i++)
    {
        brojac1=0;
        if(neparnite[i]==false)
        {
            for(int j=i;j<=(i+rastojanie);j++)
            {
                if(neparnite[j]==true)
                {
                    brojac1++;
                }
            }
            if(brojac1==0)
            {
                for(int k=i;k<=(i+rastojanie);k++)
                {
                    neparnite[k]=true;
                }
                brojac++;
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}