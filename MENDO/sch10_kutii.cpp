#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> visited(m+1);
    vector<int> v1,v2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    int brojac=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[j]&&v1[i]<=v2[j])
            {
                visited[j]=true;
                brojac++;
                break;
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}