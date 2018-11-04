#include<iostream>
#include<stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    stack<pair<int,long long> > s;
    long long brojac=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        pair<int,long long> pp=make_pair(a,(long long)1);
        while(!s.empty())
        {
            if(s.top().first>a)
                break;
            else{
                brojac+=s.top().second;
                if(s.top().first==a)
                    pp.second+=s.top().second;
                s.pop();}
        }
        if(!s.empty())
            brojac++;
        s.push(pp);
    }
    cout<<brojac<<endl;
    return 0;
}