#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool visited[50001];
    bool visited1[50001];
    memset(visited,false,sizeof(visited));
    memset(visited1,false,sizeof(visited1));
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int bb;
        cin>>bb;
        bb--;
        v.push_back(bb);
    }
    int maxi=0;
    int g=0;
    for(int i=0;i<v.size();i++)
    {
        int brojac=0;
        if(visited1[i]==false)
        {
            bool b=false;
            int k=i;
            while(b==false)
            {
                if(visited[k]==false)
                {
                    brojac++;
                    visited[k]=true;
                    visited1[k]=true;
                    b=false;
                    g=v[k];
                    k=g;
                }
                else
                {
                    b=true;
                    break;
                }
            }
            maxi=max(maxi,brojac);
        }
  
            memset(visited,false,sizeof(visited));
    }
    cout<<maxi<<endl;
    return 0;
}