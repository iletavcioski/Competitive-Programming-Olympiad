#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ll;
ll dp[16][26][5][5][5][5];
int main()
{
	int Ve,Vc,Ce,Cc;
	cin>>Ve>>Vc>>Ce>>Cc;
	string s;
	cin>>s;
	int n=s.size();
	if(s[0]=='*')
	{
		for(int i=0;i<26;i++)
		{
			if(i==0||i==4||i==8||i==14||i==20)
			{
				dp[0][i][1][1][0][0]=1;
			}
			else
			{
				dp[0][i][0][0][1][1]=1;
			}
		}
	}
	else
	{
		int ch=s[0]-'a';
		if(ch==0||ch==4||ch==8||ch==14||ch==20)
		{
			dp[0][ch][1][1][0][0]=1;
		}
		else
		{
			dp[0][ch][0][0][1][1]=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]=='*')
		{
			for(int j=0;j<26;j++)
			{
				if(j==0||j==4||j==8||j==14||j==20)
				{
					for(int k=0;k<26;k++)
					{
						if(k==0||k==4||k==8||k==14||k==20)
						{
							for(int ve=0;ve<=Ve;ve++)
							{
								for(int vc=0;vc<Vc;vc++)
								{
									if(j!=k)
										dp[i][j][vc+1][1][0][0]+=dp[i-1][k][vc][ve][0][0];
									else if(ve!=Ve)
										dp[i][j][vc+1][ve+1][0][0]+=dp[i-1][k][vc][ve][0][0];
								}
							}
						}
						else
						{
							for(int ce=0;ce<=Ce;ce++)
							{
								for(int cc=0;cc<=Cc;cc++)
								{
									dp[i][j][1][1][0][0]+=dp[i-1][k][0][0][cc][ce];
								}
							}
						}
					}
				}
				else
				{
					for(int k=0;k<26;k++)
					{
						if(k==0||k==4||k==8||k==14||k==20)
						{
							for(int ve=0;ve<=Ve;ve++)
							{
								for(int vc=0;vc<=Vc;vc++)
								{
									dp[i][j][0][0][1][1]+=dp[i-1][k][vc][ve][0][0];
								}
							}
						}
						else
						{
							for(int ce=0;ce<=Ce;ce++)
							{
								for(int cc=0;cc<Cc;cc++)
								{
									if(j!=k)
										dp[i][j][0][0][cc+1][1]+=dp[i-1][k][0][0][cc][ce];
									else if(ce!=Ce)
										dp[i][j][0][0][cc+1][ce+1]+=dp[i-1][k][0][0][cc][ce];
								}
							}
						}
					}
				}
			}
		}
		else
		{
			int j=s[i]-'a';
			if(j==0||j==4||j==8||j==14||j==20)
			{
				for(int k=0;k<26;k++)
				{
					if(k==0||k==4||k==8||k==14||k==20)
					{
						for(int ve=0;ve<=Ve;ve++)
						{
							for(int vc=0;vc<Vc;vc++)
							{
								if(j!=k)
									dp[i][j][vc+1][1][0][0]+=dp[i-1][k][vc][ve][0][0];
								else if(ve!=Ve)
									dp[i][j][vc+1][ve+1][0][0]+=dp[i-1][k][vc][ve][0][0];
							}
						}
					}
					else
					{
						for(int ce=0;ce<=Ce;ce++)
						{
							for(int cc=0;cc<=Cc;cc++)
							{
								dp[i][j][1][1][0][0]+=dp[i-1][k][0][0][cc][ce];
							}
						}
					}
				}
			}
			else
			{
				for(int k=0;k<26;k++)
				{
					if(k==0||k==4||k==8||k==14||k==20)
					{
						for(int ve=0;ve<=Ve;ve++)
						{
							for(int vc=0;vc<=Vc;vc++)
							{
								dp[i][j][0][0][1][1]+=dp[i-1][k][vc][ve][0][0];
							}
						}
					}
					else
					{
						for(int ce=0;ce<=Ce;ce++)
						{
							for(int cc=0;cc<Cc;cc++)
							{
								if(j!=k)
									dp[i][j][0][0][cc+1][1]+=dp[i-1][k][0][0][cc][ce];
								else if(ce!=Ce)
									dp[i][j][0][0][cc+1][ce+1]+=dp[i-1][k][0][0][cc][ce];
							}
						}
					}
				}
			}
		}
	}
	ll ways=0;
	for(int b=0;b<26;b++)
	{
		for(int i=0;i<=Vc;i++)
		{
			for(int j=0;j<=Ve;j++)
			{
				for(int k=0;k<=Cc;k++)
				{
					for(int l=0;l<=Ce;l++)
					{
						ways+=dp[n-1][b][i][j][k][l];
					}
				}
			}
		}
	}
	cout<<ways<<endl;
	return 0;
}