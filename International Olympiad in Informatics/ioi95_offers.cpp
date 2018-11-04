#include<iostream>
#include<cstring>
using namespace std;
int dp[6][6][6][6][6];
int n,m;
int nn;
int cod[1001];
int kolku[6];
struct node
{
    int niza[6];
    int cena;
}v[200];
int code(int n)
{
    if (!cod[n])
	{
		nn++;
		cod[n]=nn;
	}
    return cod[n];
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
		int t;
        cin>>t;
        for(int j=0;j<t;j++)
        {
			int bb;
            cin>>bb;
            cin>>v[i].niza[code(bb)];
        }
        cin>>v[i].cena;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int bb;
		cin>>bb;
        int cd=code(bb);
        cin>>kolku[cd];
        cin>>v[n+i].cena;
        v[n+i].niza[cd]=1;
    }
    memset(dp,127,sizeof(dp));
    dp[0][0][0][0][0]=0;
    for(int i=0;i<n+m;i++)
    {
        int n1=v[i].niza[1];
        int n2=v[i].niza[2];
        int n3=v[i].niza[3];
        int n4=v[i].niza[4];
        int n5=v[i].niza[5];
        for(int j=0;j+n1<=kolku[1];j++)
		{
			for(int k=0;k+n2<=kolku[2];k++)
			{
				for(int l=0;l+n3<=kolku[3];l++)
				{
					for(int jj=0;jj+n4<=kolku[4];jj++)
					{
						for(int kk=0;kk+n5<=kolku[5];kk++)
						{
							if(dp[j+n1][k+n2][l+n3][jj+n4][kk+n5]>dp[j][k][l][jj][kk]+v[i].cena)
								dp[j+n1][k+n2][l+n3][jj+n4][kk+n5]=dp[j][k][l][jj][kk]+v[i].cena;
						}
					}
				}
			}
		}
    }
    cout<<dp[kolku[1]][kolku[2]][kolku[3]][kolku[4]][kolku[5]]<<endl;
    return 0;
}