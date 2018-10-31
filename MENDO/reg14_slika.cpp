#include<iostream>
#include<vector>
using namespace std;
int main()
{
    bool t=true;
    vector<int> v;
    int brojac1=0;
    int brojac=0;
    while(t==true)
    {
        int broj;
        cin>>broj;
        v.push_back(broj);
            if(broj==3)
                break;
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1)
            brojac++;
        else
            break;
    }
    cout<<(v.size()/(brojac-1))<<" "<<(brojac-1)<<endl;
return 0;
}