#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int br;
    int brojac=0;
    vector<int> v;
    vector<int> vkraj;
    int brojac1=0;
    int p;
    div_t broj;
    for(int i=0;i<n;i++)
    {
        cin>>br;
         brojac1=0;
        p=br;
        do{
            broj=div(p,10);
            v.push_back(broj.rem);
            p=broj.quot;
        }while(broj.quot>0);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%2==0)
            {
                brojac1++;
            }
        }
        if(brojac1==v.size())
        {
            brojac++;
            for(int i=0;i<v.size();i++)
            {
                vkraj.push_back(v[i]);
            }
        }
        v.clear();
    }
    cout<<brojac<<endl;
    cout<<vkraj.size();
    return 0;
}