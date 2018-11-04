#include<iostream>
#include<queue>
#include<string>
using namespace std;
int niza1x[]={-1,-1,-1,0,0,1,1,1};
int niza1y[]={-1,0,1,-1,1,-1,0,1};
int niza2x[]={-1,-2,-2,-1,1,2,2,1};
int niza2y[]={-2,-1,1,2,-2,-1,1,2};
int mat[40][40][40][40];
int n,m;
void bfs(int bx,int by,int ei,int ej,int c)
{
	queue<int> qi;
	queue<int> qj;
	queue<int> qs;
	qi.push(ei);
	qj.push(ej);
	qs.push(0);
	int nizax[8];
	int nizay[8];
	if(!c)
	{
		for(int i=0;i<8;i++)
		{
			nizax[i]=niza1x[i];
			nizay[i]=niza1y[i];
		}
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			nizax[i]=niza2x[i];
			nizay[i]=niza2y[i];
		}
	}
	bool visited[40][40];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			visited[i][j]=false;
	}
	visited[ei][ej]=true;
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		int tops=qs.front();
		qs.pop();
		for(int i=0;i<8;i++)
		{
			if(topi+nizax[i]<n&&topi+nizax[i]>=0&&topj+nizay[i]<m&&topj+nizay[i]>=0&&!visited[topi+nizax[i]][topj+nizay[i]])
			{
				mat[bx][by][topi+nizax[i]][topj+nizay[i]]+=tops+1;
				if(c==1)
				mat[n+4][m+4][topi+nizax[i]][topj+nizay[i]]+=tops+1;
				qi.push(topi+nizax[i]);
				qj.push(topj+nizay[i]);
				qs.push(tops+1);
				visited[topi+nizax[i]][topj+nizay[i]]=true;
			}
		}
	}
}
int main()
{
  n=8;
  m=8;
	for(int i=0;i<n+5;i++)
	{
		for(int j=0;j<m+5;j++)
		{
			for(int k=0;k<n+5;k++)
			{
				for(int l=0;l<m+5;l++)
				{
					mat[i][j][k][l]=0;
				}
			}
		}
	}
	int ki,kj;
	char a;
	int b;
	string ss;
	cin>>ss;
	a=ss[0]-'A';
	b=ss[1]-'0';
	vector<int> vi,vj;
	bfs(n+3,m+3,a,b-1,0);
	ki=a;
	kj=b;
	kj--;
	for(int i=2;i<ss.size();i+=2)
	{
		a=ss[i];
	    b=ss[i+1];
		a-='A';
		b-='0';
		b--;
		vi.push_back(a);
		vj.push_back(b);
		bfs(a,b,a,b,1);
		
	}

	bfs(n+2,m+2,ki,kj,2);

	int maxi=10000000;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		    int brojac=mat[n+4][m+4][i][j]+mat[n+3][m+3][i][j];
			int broj=mat[n+4][m+4][i][j];
			for(int k=0;k<vi.size();k++)
			{
				brojac=min(brojac,((broj-mat[vi[k]][vj[k]][i][j])+mat[n+2][m+2][i][j]+mat[vi[k]][vj[k]][ki][kj]));
				brojac=min(brojac,((broj-mat[vi[k]][vj[k]][i][j])+mat[n+3][m+3][vi[k]][vj[k]]+mat[vi[k]][vj[k]][i][j]));
			}
			maxi=min(brojac,maxi);
		}
	}
	
	cout<<maxi<<endl;
	return 0;
}