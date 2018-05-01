#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    char mat[51][51];
    int visited[51][51];
    memset(visited,0,sizeof(visited));
    queue<int> qi;
    queue<int>qj;
    queue<int>qs;
    int brojac1=0;
    vector<int> jj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='F')
            {
                qi.push(i);
                qj.push(j);
                jj.push_back(i);
                qs.push(0);
                visited[i][j]++;
            }
        }
    }
    int k=qi.front();
    for(int i=0;i<jj.size();i++)
    {
        if(jj[i]==k)
            brojac1++;
        else
            break;
    }
    int g=qi.size();
    int c=g/brojac1;
    while(!qi.empty())
    {
        vector<int> topi;
        vector<int> topj;
        vector<int> tops;
        for(int i=0;i<g;i++)
        {
            topi.push_back(qi.front());
            qi.pop();
            topj.push_back(qj.front());
            qj.pop();
            tops.push_back(qs.front());
            qs.pop();
        }
        int bro1=0;
        int bro2=0;
        int bro3=0;
        for(int i=0;i<topi.size();i++)
        {
            if(mat[topi[i]][topj[i]]=='1')
                bro1++;
            if (mat[topi[i]][topj[i]]=='2')
                bro2++;
            if(mat[topi[i]][topj[i]]=='3')
                bro3++;
        }
        if(bro1==g)
        {
            cout<<1<<endl;
            cout<<tops[0]<<endl;
            return 0;
        }
        if(bro2==g)
        {
            cout<<2<<endl;
            cout<<tops[0]<<endl;
            return 0;
        }
        if(bro3==g)
        {
            cout<<3<<endl;
            cout<<tops[0]<<endl;
            return 0;
        }
        bool nagore=false;
        for(int i=0;i<brojac1;i++)
        {
            if(topi[i]-1>=0&&mat[topi[i]-1][topj[i]]!='#'&&visited[topi[i]-1][topj[i]]<4)
            {
                nagore=true;
            }
            else
            {
                nagore=false;
                    break;
            }
        }
        if(nagore==true)
        {
            for(int i=0;i<topi.size();i++)
            {
                qi.push(topi[i]-1);
                qj.push(topj[i]);
                qs.push(tops[i]+1);
                visited[topi[i]-1][topj[i]]++;
            }
        }
        bool nadole=false;
        for(int i=g-1;i>=g-brojac1;i--)
        {
            if(topi[i]+1<n&&mat[topi[i]+1][topj[i]]!='#'&&visited[topi[i]+1][topj[i]]<4)
            {
                nadole=true;
            }
            else
            {
                nadole=false;
                    break;
            }
        }
        if(nadole==true)
        {
            for(int i=0;i<topi.size();i++)
            {
                qi.push(topi[i]+1);
                qj.push(topj[i]);
                qs.push(tops[i]+1);
                visited[topi[i]+1][topj[i]]++;
            }
        }
        bool nalevo=false;
        for(int i=0;i<g;i+=brojac1)
        {
            if(topj[i]-1>=0&&mat[topi[i]][topj[i]-1]!='#'&&visited[topi[i]][topj[i]-1]<4)
            {
                nalevo=true;
            }
            else
            {
                nalevo=false;
                    break;
            }
        }
        if(nalevo==true)
        {
            for(int i=0;i<topi.size();i++)
            {
                qi.push(topi[i]);
                qj.push(topj[i]-1);
                qs.push(tops[i]+1);
                visited[topi[i]][topj[i]-1]++;
            }
        }
        bool nadesno=false;
        for(int i=g-1;i>=0;i-=brojac1)
        {
            if(topj[i]+1<m&&mat[topi[i]][topj[i]+1]!='#'&&visited[topi[i]][topj[i]+1]<4)
            {
                nadesno=true;
            }
            else
            {
                nadesno=false;
                    break;
            }
        }
        if(nadesno==true)
        {
            for(int i=0;i<topi.size();i++)
            {
                qi.push(topi[i]);
                qj.push(topj[i]+1);
                qs.push(tops[i]+1);
                visited[topi[i]][topj[i]+1]++;
            }
        }
        topi.clear();
        topj.clear();
        tops.clear();
    }
    return 0;
}