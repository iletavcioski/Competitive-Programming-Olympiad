#include <iostream>
#include <string>
#include <vector>
#include <queue>
using  namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    vector<int> v1,v2;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v1.push_back(a);
        v2.push_back(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> vv(n+1,false);
    int poc=0;
    int poc1=0;
    int brojce=0;
    for(int i=0;i<n;i++)
    {
        if(!vv[i])
        {
            brojce++;
            vector<int> vk;
            queue<int> qi;
			qi.push(i);
			vv[i]=true;
            while(!qi.empty())
            {
                int topi=qi.front();
                qi.pop();
                vk.push_back(topi);
                for(int j=0;j<v[topi].size();j++)
                {
                    if(!vv[v[topi][j]])
                    {
                        vv[v[topi][j]]=true;
                        qi.push(v[topi][j]);
                    }
                }
            }
            if(!i)
            {
                poc1=vk.size();
                for(int j=0;j<m;j++)
                {
                    if(vv[v1[j]]||vv[v2[j]])
                        poc++;
                }
            }   
        }
        
    }
    if(brojce==1)
    {
        if(m==((n*(n-1))/2))
            cout<<"DA"<<endl;
        else
            cout<<"NE"<<endl;
    }
    else if(brojce==2)
    {
        int m1=m-poc;
        int n1=n-poc1;
        if((m1==((n1*(n1-1))/2))&&(poc==((poc1*(poc1-1))/2)))
            cout<<"DA"<<endl;
        else
            cout<<"NE"<<endl;
    }
    else
        cout<<"NE"<<endl;
    return 0;
}