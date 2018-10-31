#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int> q1;
    queue<int> q2;
    vector<string> vs;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        if(ss=="LL")
            q1.push(i);
        if(ss=="DD")
            q2.push(i);
    }
    long long brojac=0;
    while(!q1.empty())
    {
        int topi=q1.front();
            q1.pop();
        int topj=q2.front();
        q2.pop();
        brojac+=abs(topi-topj);
    }
    cout<<brojac<<endl;
    return 0;
}