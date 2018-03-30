#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ll;
vector<int> v1,v2;
ll dp1(int firstnum,int secondnum,int length)
{
    ll dp[19][11][11];
    if(firstnum==secondnum)
        return 0;
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<11;j++)
        {
            for(int k=0;k<11;k++)
            {
                dp[i][j][k]=0;
            }
        }
    }
    dp[1][firstnum][secondnum]=1;
    ll brojac=0;
    if(firstnum==10)
    {
        for(int i=2;i<=length;i++)
        {
            for(int j=0;j<11;j++)
            {
                for(int k=0;k<11;k++)
                {
                    for(int newnum=0;newnum<=9;newnum++)
                    {
                        if(j==k||j==newnum||k==newnum)
                            continue;
                        dp[i][k][newnum]+=dp[i-1][j][k];
                        if(i==length)
                            brojac+=dp[i-1][j][k];
                    }
                }
            }
        }
    }
    else
    {
        dp[2][firstnum][secondnum]=1;
        for(int i=3;i<=length;i++)
        {
            for(int j=0;j<11;j++)
            {
                for(int k=0;k<11;k++)
                {
                    for(int newnum=0;newnum<=9;newnum++)
                    {
                        if(j==k||j==newnum||k==newnum)
                            continue;
                        dp[i][k][newnum]+=dp[i-1][j][k];
                        if(i==length)
                            brojac+=dp[i-1][j][k];
                    }
                }
            }
        }
    }
    return brojac;
}
ll dp2(vector<int> b1,int firstnum,int secondnum)
{
    int a=firstnum,b=secondnum;
    ll brojac=0;
    for(int i=0;i<b1.size();i++)
    {
        int br=b1[i];
        for(int j=br+1;j<=9;j++)
        {
            
            if(i==b1.size()-1)
            {
                 if(b!=j&&a!=j)
                    brojac++;
            }
            else
            {
                if(b==j||a==j)
                    continue;
                brojac+=dp1(b,j,b1.size()-i+(b!=10));
            }
        }
        if(br==a||b==br)
            break;
        a=b,b=br;
    }
    return brojac;
}
ll dp3(vector<int> b1,int firstnum,int secondnum)
{
    int a=firstnum,b=secondnum;
    ll brojac=0;
    for(int i=0;i<b1.size();i++)
    {
        int br=b1[i];
        for(int j=b1[i]-1;j>=0;j--)
        {
            if(i==b1.size()-1)
            {
                 if(b!=j&&a!=j)
                    brojac++;
            }
            else
            {
                if(b==10&&j==0)
                    continue;
                if(b==j||a==j)
                    continue;

                brojac+=dp1(b,j,b1.size()-i+(b!=10));
            }
        }
        if(br==a||b==br)
            break;
        a=b,b=br;
    }
    return brojac;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++)
    {
        v1.push_back(s1[i]-'0');
    }
    for(int i=0;i<s2.size();i++)
    {
        v2.push_back(s2[i]-'0');
    }
    ll res=0;
    for(int i=v1.size()+1;i<v2.size();i++)
    {
        for(int j=1;j<=9;j++)
            res+=dp1(10,j,i);
    }
    vector<int> vec;
    if(v1.size()!=v2.size())
    {
        res+=dp2(v1,10,10);
        res+=dp3(v2,10,10);
    }
    else
    {
        int a=10,b=10;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==v2[i])
            {
                if(v1[i]==a||v1[i]==b)
                    break;
                a=b,b=v1[i];
                continue;
            }
            else
            {
                int kr=i;
                vector<int> ve1,ve2;
                for(int j=i+1;j<v1.size();j++)
                {
                    ve1.push_back(v1[j]);
                }
                for(int j=i+1;j<v2.size();j++)
                {
                    ve2.push_back(v2[j]);
                }
                for(int j=v1[i]+1;j<v2[i];j++)
                {
                    if(j!=a&&b!=j)
                    {
                        res+=dp1(b,j,v1.size()-i+(b!=10));
                    }
                }
                if(ve1.size()>0)
                {
                    if(v1[i]!=b&&v1[i]!=a)
                    {
                        res+=dp2(ve1,b,v1[i]);
                    }
                }
                if(ve2.size()>0)
                {
                    if(v2[kr]!=b&&v2[kr]!=a)
                    {
                        res+=dp3(ve2,b,v2[kr]);
                    }
                }
                break;
            }
        }
    }

    int a=10,b=10;
    int c1=1;
    int c2=1;
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]==a||v1[i]==b)
        {
            c1=0;
            break;
        }
        a=b,b=v1[i];

    }
    a=10,b=10;
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]==a||v2[i]==b)
        {
            c2=0;
            break;
        }
        a=b,b=v2[i];

    }
    if(s1==s2)
    {
        if(c1==1)
            res++;
    }
    else
    {
        res+=c1;
        res+=c2;
    }
    cout<<res<<endl;
    return 0;
}