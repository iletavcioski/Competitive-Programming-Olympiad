#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int zbirn=n;
    int zbir1=1;
    int zbir3=3;
    int zbir9=9;
    vector<int> vn;
    vector<int> v1;
    vector<int> v3;
    vector<int>v9;
    for(int i=0;i<1500;i++)
    {
        int k=zbirn;
        vn.push_back(k);
        while(k>0)
        {
            zbirn+=k%10;
            k/=10;
        }
    }
    for(int i=0;i<1500;i++)
    {
        int k=zbir1;
        v1.push_back(k);
        while(k>0)
        {
            zbir1+=k%10;
            k/=10;
        }
    }
    for(int i=0;i<1500;i++)
    {
        int k=zbir3;
        v3.push_back(k);
        while(k>0)
        {
            zbir3+=k%10;
            k/=10;
        }
    }
    for(int i=0;i<1500;i++)
    {
        int k=zbir9;
        v9.push_back(k);
        while(k>0)
        {
            zbir9+=k%10;
            k/=10;
        }
    }
  
    for(int i=0;i<vn.size();i++)
    {
        for(int j=0;j<v1.size();j++)
        {
            if(vn[i]==v1[j])
            {
                cout<<1<<" "<<v1[j]<<endl;
                return 0;
            }
            if(vn[i]==v3[j])
            {
                cout<<3<<" "<<v3[j]<<endl;
                return 0;
            }
            if(vn[i]==v9[j])
            {
                cout<<9<<" "<<v9[j]<<endl;
                return 0;
            }
        }
    }
}