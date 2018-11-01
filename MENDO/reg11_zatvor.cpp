#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int res=0;
    char mat[1001][1001];
    bool visited[1001][1001];
    vector<int>vi;
    vector<int> vj;
    vector<int>sidi;
    vector<int>sidj;
    int pocetoki,pocetokj;
    int kraji,krajj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='Z')
            {
                kraji=i;
                krajj=j;
            }
            if(mat[i][j]=='G')
            {
                vi.push_back(i);
                vj.push_back(j);
            }
            if(mat[i][j]=='*')
            {
                sidi.push_back(i);
                sidj.push_back(j);
            }
            if(mat[i][j]=='R')
            {
                pocetoki=i;
                pocetokj=j;
            }
        }
    }
    bool k=true;
    while(k)
    {
        memset(visited,false,sizeof(visited));
        if(mat[pocetoki][pocetokj]=='G'||mat[pocetoki][pocetokj]=='*'||visited[pocetoki][pocetokj])
        {
            cout<<res<<endl;
            return 0;
        }
        if(mat[kraji][krajj]=='G'||mat[kraji][krajj]=='*'||visited[kraji][krajj])
        {
            cout<<res<<endl;
            return 0;
        }
        visited[pocetoki][pocetokj]=true;
        queue<int>qi;
        queue<int>qj;
        qi.push(pocetoki);
        qj.push(pocetokj);
        bool dobro=false;
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topj=qj.front();
            qj.pop();
            if(mat[topi][topj]=='Z')
            {
                dobro=true;
                break;
            }
            if(topi+1<n&&!visited[topi+1][topj]&&mat[topi+1][topj]!='G'&&mat[topi+1][topj]!='*')
            {
                qi.push(topi+1);
                qj.push(topj);
                visited[topi+1][topj]=true;
            }
            if(topj-1>=0&&!visited[topi][topj-1]&&mat[topi][topj-1]!='G'&&mat[topi][topj-1]!='*')
            {
                qi.push(topi);
                qj.push(topj-1);
                visited[topi][topj-1]=true;
            }
            if(topi-1>=0&&!visited[topi-1][topj]&&mat[topi-1][topj]!='G'&&mat[topi-1][topj]!='*')
            {
                qi.push(topi-1);
                qj.push(topj);
                visited[topi-1][topj]=true;
            }
            if(topj+1<m&&!visited[topi][topj+1]&&mat[topi][topj+1]!='G'&&mat[topi][topj+1]!='*')
            {
                qi.push(topi);
                qj.push(topj+1);
                visited[topi][topj+1]=true;
            }
        }
        if(!dobro)
        {
            cout<<res<<endl;
            return 0;
        }
        if(dobro)
            res++;
        int brojce=vi.size();
        for(int i=0;i<brojce;i++)
        {
            if(vi[i]+1<n&&mat[vi[i]+1][vj[i]]!='G'&&mat[vi[i]+1][vj[i]]!='*')
            {
                vi.push_back(vi[i]+1);
                vj.push_back(vj[i]);
                mat[vi[i]+1][vj[i]]='G';
            }
            if(vj[i]+1<m&&mat[vi[i]][vj[i]+1]!='G'&&mat[vi[i]][vj[i]+1]!='*')
            {
                vi.push_back(vi[i]);
                vj.push_back(vj[i]+1);
                mat[vi[i]][vj[i]+1]='G';
            }if(vi[i]-1>=0&&mat[vi[i]-1][vj[i]]!='G'&&mat[vi[i]-1][vj[i]]!='*')
            {
                vi.push_back(vi[i]-1);
                vj.push_back(vj[i]);
                mat[vi[i]-1][vj[i]]='G';
            }if(vj[i]-1>=0&&mat[vi[i]][vj[i]-1]!='G'&&mat[vi[i]][vj[i]-1]!='*')
            {
                vi.push_back(vi[i]);
                vj.push_back(vj[i]-1);
                mat[vi[i]][vj[i]-1]='G';
            }
        }
  
    }
    return 0;
}