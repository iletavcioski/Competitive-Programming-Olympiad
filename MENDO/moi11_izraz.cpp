#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char mat[251];
string ss;
struct Izbor
{
    string brojc;
    int cifri;
    char znak;
};
bool compare(const Izbor& x, const Izbor& y)
{
    if(x.cifri<y.cifri)
        return true;
    else
        return false;
}
void acki(int x,int y,char z)
{
    mat[x]=z;
    x++;
      
    mat[y]=z;
    int bb=1;
    int zz=z;
    for(int i=x;i<y;i++)
    {
    if(bb==1)
    {
        if(ss[i]=='?')
        {
            mat[i]=zz;
        }
        if(ss[i]=='+')
        {
            if(z=='-')
                zz='-';
            else
                zz='+';
            mat[i]=zz;
        }
        if(ss[i]=='-')
        {
            if(z=='+')
                zz='-';
            else
                zz='+';
            mat[i]=zz;
        }
        if(ss[i]=='(')
        {
            bb++;
            mat[i]=zz;
        }
    }
    else
    {
        if(ss[i]=='(')
            bb++;
        else if(ss[i]==')')
            bb--;
    }
    }
      
}
  
int main()
{
    string s;
    cin>>s;
    string broj;
    cin>>broj;
    ss="(";
    for(int i=0;i<s.size();i++)
        ss+=s[i];
    memset(mat,'0',sizeof(mat));
    vector<int> v1;
    vector<int> v2;
    ss+=')';
      
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='('){
            v1.push_back(i);
        int iii=1;
        int mmm=0;
        for(int j=i+1;j<ss.size();j++)
        {
            if(ss[j]=='(')iii++;
            if(ss[j]==')')mmm++;
            if(iii==mmm)
            {
                v2.push_back(j);
                break;
            }
        }
        }
    }
  
    mat[0]='+';
    for(int i=0;i<v1.size();i++)
    {
        int a=v1[i];
        int b=v2[i];
        char c=mat[v1[i]];
        acki(a,b,c);
    }
      
    Izbor g;
    vector<Izbor> vv;
    string pp="";
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]!='?')
        {
            if(pp.size()>0)
            {
                g.brojc=pp;
            g.cifri=pp.size();
            g.znak=mat[i-1];
            vv.push_back(g);
            }
            pp="";
  
        }
        else
            pp+=ss[i];
    }
      
    if(pp.size()>0)
    {
        g.brojc=pp;
        g.cifri=pp.size();
        g.znak=mat[ss.size()-1];
        vv.push_back(g);
    }
    sort(vv.begin(),vv.end(),compare);
    reverse(vv.begin(),vv.end());
  
    vector<int> brojki;
    for(int i=0;i<broj.size();i++)
    {
        brojki.push_back(broj[i]-'0');
    }
    bool visited[250];
    memset(visited,false,sizeof(visited));
    long long brojac=0;
    int brojce;
    sort(brojki.begin(),brojki.end());
    int cif=vv[0].cifri;
    for(int i=cif;i>=1;i--)
    {
        for(int j=0;j<vv.size();j++)
        {
            if(vv[j].cifri>=i)
            {
                if(vv[j].znak=='+')
                {
                    for(int ii=brojki.size()-1;ii>=0;ii--)
                    {
                        if(!visited[ii])
                        {
                            visited[ii]=true;
                            double stepen=i-1;
                            int ssst=pow(10.0,stepen)+0.00000000001;
                            brojac+=brojki[ii]*ssst;
                            break;
                        }
                    }
                }
                else
                {
                    for(int ii=0;ii<brojki.size();ii++)
                    {
                        if(!visited[ii])
                        {
                            visited[ii]=true;
                            double stepen=i-1;
                            int ssst=pow(10.0,stepen)+0.00000000001;
                            brojac-=brojki[ii]*ssst;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<brojac<<endl;
return 0;
}