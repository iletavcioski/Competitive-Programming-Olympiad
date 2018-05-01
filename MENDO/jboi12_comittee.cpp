#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int brojac=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int bb;
        cin>>bb;
        v.push_back(bb);
    }
    int borjac=0;
    int maxi=0;
    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i-1]>v[i]&&v[i+1]>v[i]||v[i-1]<v[i]&&v[i+1]<v[i])
        {
            brojac++;
            maxi=max(maxi,brojac);
        }
        else
        {
            brojac=0;
        }
    }
    cout<<maxi<<endl;
    return 0;
}