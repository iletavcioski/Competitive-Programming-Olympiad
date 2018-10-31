#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++)
    {
        int nn,kk;
        cin>>nn>>kk;
        v1.push_back(nn);
        v2.push_back(kk);
    }
    int maxi=1;
    int brojac=1;
    for(int i=0;i<v1.size()-1;i++)
    {
        if(v1[i]==v1[i+1]&&v2[i]==v2[i+1])
        {
            brojac++;
            maxi=max(maxi,brojac);
        }
        else
        {
            brojac=1;
        }
          
    }
    cout<<maxi<<endl;
    return 0;
}