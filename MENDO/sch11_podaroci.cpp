#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    vector<int> v,vv;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if((x<=a&&y<=b)||(y<=a&&x<=b)){
            v.push_back(x);
            vv.push_back(y);
        }
    }
    cout<<v.size()<<endl;
    if(v.size()!=0)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" "<<vv[i]<<endl;
    }
    return 0;
}