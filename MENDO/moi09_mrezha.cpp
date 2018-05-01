#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
int mat[300][300];
map<int,pair<int,int> > m;
int najd(int a,int b)
{
    if(a>b)
        swap(a,b);
    int x1,x2,y1,y2;
    x1=m[a].first;
    x2=m[b].first;
    y1=m[a].second;
    y2=m[b].second;
    int brojac=0;
    int x,y;
    if((x1+y1)==(x2+y2))
    {
        x=x1;
        y=y1;
        while(x!=x2&&y!=y2)
        {
            if(x!=0)
            x--;
            else
                return -1;
            y++;
            brojac++;
            if(x==x2&&y==y2)
                return brojac;
        }
    }
    else if(x1==x2)
        return abs(y2-y1);
    else if(y1==y2)
        return abs(x2-x1);
    else return -1;
}
bool acki(vector<int> vv)
{
    do{
        set<int> ss;
        ss.insert(najd(vv[0],vv[vv.size()-1]));;
        for(int i=0;i<vv.size()-1;i++)
            ss.insert(najd(vv[i],vv[i+1]));
        set<int>::iterator it=ss.begin();
        if(*it!=-1&&ss.size()==1)
            return true;
    }while(next_permutation(vv.begin(),vv.end()));
    return false;
}
int main()
{
    int n;
      
    int bb=0;
      
    int bbb=2;
    memset(mat,0,sizeof(mat));
    mat[0][0]=1;
    m[1]=make_pair(0,0);
    for(int i=1;i<=257;i++)
    {
        mat[0][i]=mat[0][i-1]+bbb;
        m[mat[0][i]]=make_pair(0,i);
        bbb++;
    }
  
    for(int j=0;j<=257;j++)
    {
        bb++;
        bbb=bb;
        for(int i=1;i<=257;i++)
        {
            mat[i][j]=mat[i-1][j]+bbb;
            m[mat[i][j]]=make_pair(i,j);
            bbb++;
        }
    }
    cin>>n;
    vector<string> vkraj;
    for(int i=0;i<n;i++)
    {
        int broj;
        cin>>broj;
        if(broj==5||broj==7||broj==8)
            vkraj.push_back("NISTO");
        vector<int> v;
        v.clear();
        bool kkk;
        for(int j=0;j<broj;j++)
        {
            int gg;
            cin>>gg;
              
            v.push_back(gg);
        }
          
        kkk=acki(v);
        if(kkk)
        {
            if(v.size()==3)
                vkraj.push_back("TRIAGOLNIK");
            if(v.size()==4)
                vkraj.push_back("PARALELOGRAM");
            if(v.size()==6)
                vkraj.push_back("SESTOAGOLNIK");
        }
        else if(v.size()!=5&&v.size()!=7&&v.size()!=8)
            vkraj.push_back("NISTO");
  
    }
    for(int i=0;i<vkraj.size();i++)
    {
        cout<<vkraj[i]<<endl;
    }
    return 0;
}