#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    int n;
    int k;
    int num;
    int brojac1=0;
    vector<int> v;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int brojce;
    brojce=v[0];
    brojac1=0;
    for(int i=0;i<v.size();i++)
    {
        if(brojce==v[i])
        {
            brojac1++;
        }
        else
        {
            if(brojac1%k!=0)
            {
                cout<<brojce<<endl;
                return 0;
            }
            else
            {
                brojac1=1;
                brojce=v[i];
            }
               
               
        }
    }
    if(brojac1%k!=0)
            {
                cout<<brojce<<endl;
                return 0;
            }
    return 0;
}