#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
struct Node
{
    int index;
    int a,b,w;
};
bool operator <(const Node &x,const Node &y)
{
        return x.w>y.w;
}
int main()
{
    priority_queue<Node> qi;
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    for(int i=0;i<n;i++)
        vec.push_back(i);
    Node g;
    vector<Node> vrski;
    for(int i=0;i<m;i++)
    {
        cin>>g.a>>g.b>>g.w;
        g.index=i;
        g.a--;
        g.b--;
        qi.push(g);
        vrski.push_back(g);
    }
    int brojac=0;
    vector<int> v;
    while(!qi.empty())
    {
        int topi=qi.top().a;
        int topj=qi.top().b;
        int weight=qi.top().w;
        int indx=qi.top().index;
        qi.pop();
        if(vec[topi]!=vec[topj])
        {
            brojac+=weight;
            int mini=min(vec[topi],vec[topj]);
            int maxi=max(vec[topi],vec[topj]);
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]==maxi)
                    vec[i]=mini;
            }
            v.push_back(indx);
        }
        else
            continue;
 
    }
    int brojac2=99999999;
    for(int i=0;i<v.size();i++)
    {
        vec.clear();
        for(int ii=0;ii<n;ii++)
        vec.push_back(ii);
        for(int j=0;j<vrski.size();j++)
        {
            if(vrski[j].index!=v[i])
            {
                qi.push(vrski[j]);
            }
        }
        int broj=0;
            while(!qi.empty())
            {
                int topi=qi.top().a;
                int topj=qi.top().b;
                int weight=qi.top().w;
                int indx=qi.top().index;
                qi.pop();
                if(vec[topi]!=vec[topj])
                {
                    broj+=weight;
                    int mini=min(vec[topi],vec[topj]);
                    int maxi=max(vec[topi],vec[topj]);
                    for(int ii=0;ii<vec.size();ii++)
                    {
                        if(vec[ii]==maxi)
                            vec[ii]=mini;
                    }
                }
                else
                    continue;
 
            }
            set<int> ss;
            for(int ii=0;ii<vec.size();ii++)
                ss.insert(vec[ii]);
            if(ss.size()==1)
            brojac2=min(brojac2,broj);
    }
    cout<<brojac<<" "<<brojac2<<endl;
    return 0;
}