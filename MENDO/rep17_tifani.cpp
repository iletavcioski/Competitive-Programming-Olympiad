#include<iostream>
#include<string>
#include<set>
#include<algorithm>
int dp[2][4][4][4][4];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    //reverse(ss.begin(),ss.end());
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                for(int l=0;l<4;l++)
                    dp[0][i][j][k][l]=dp[1][i][j][k][l]=-1;
            }
        }
    }
    dp[0][0][0][0][0]=0;
    int a=0;
    int b;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        b=a+1;
        b%=2;
        for(int ii=0;ii<4;ii++)
        {
            for(int jj=0;jj<4;jj++)
            {
                for(int kk=0;kk<4;kk++)
                {
                    for(int ll=0;ll<4;ll++)
                    {
                        if(dp[a][ii][jj][kk][ll]!=-1)
                        {
                            maxi=max(maxi,dp[a][ii][jj][kk][ll]);
                            //cout<<ii<<" "<<jj<<" "<<kk<<" "<<ll<<" "<<endl;
                            //cout<<dp[a][ii][jj][kk][ll]<<endl;
                            int broj1=-1,broj2=-1;
                            int broj;
                            if(ii)
                            broj1=ii;
                            if(jj)
                            broj2=jj;
                            if(ss[i]=='R')
                                broj=1;
                            else if(ss[i]=='Y')
                                broj=2;
                            else
                                broj=3;
                            int brojac=1;
                            if(broj1!=-1&&broj2!=-1)
                            {
                            if(broj!=broj1&&broj!=broj2&&broj1!=broj2)
                                brojac=3;
                            else if(broj!=broj1||broj!=broj2||broj1!=broj2)
                                brojac=2;
                            }
                            else if(broj2!=-1)
                            {
                                if(broj!=broj2)
                                    brojac=2;
                            }
                              
                            dp[b][jj][broj][kk][ll]=max(dp[b][jj][broj][kk][ll],(dp[a][ii][jj][kk][ll]+brojac));
                             broj1=-1,broj2=-1;
                             broj;
                            if(kk)
                            broj1=kk;
                            if(ll)
                            broj2=ll;
                            if(ss[i]=='R')
                                broj=1;
                            else if(ss[i]=='Y')
                                broj=2;
                            else
                                broj=3;
                             brojac=1;
                            if(broj1!=-1&&broj2!=-1)
                            {
                            if(broj!=broj1&&broj!=broj2&&broj1!=broj2)
                                brojac=3;
                            else if(broj!=broj1||broj!=broj2||broj1!=broj2)
                                brojac=2;
                            }
                            else if(broj2!=-1)
                            {
                                if(broj!=broj2)
                                    brojac=2;
                            }
                            dp[b][ii][jj][ll][broj]=max(dp[b][ii][jj][ll][broj],(dp[a][ii][jj][kk][ll]+brojac));
                        }
                    }
                }
            }
        }
        a++;
        a%=2;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                for(int l=0;l<4;l++)
                    maxi=max(maxi,dp[b][i][j][k][l]);
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}