#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int main() 
{
    int n,m;
    cin>>n>>m;
    queue<int> qi;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a)
        qi.push(i);
    }
    int i=0;
    int brojac=0;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
       // cout<<topi<<endl;
        if(!qi.empty())
        {
            if(qi.front()<=i+m)
            continue;
            else{
                if(topi<=i+m){
            i=topi;
            brojac++;
                }
                else
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        else
        {
            if(topi<=i+m){
            i=topi;
            brojac++;
                }
                else
                {
                    cout<<-1<<endl;
                    return 0;
                }
        }
    }
    cout<<brojac<<endl;
    return 0;
}