#include <iostream>
#include <vector>
using namespace std;
bool visi[200002];
int A[200002];
int B[100001];
int main()
{
	int n;
	cin>>n;
	int maxi=2*n;
	int mini=0;
	visi[2*n]=true;
	visi[0]=true;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		B[i]=a;
	}
	visi[B[1]]=true;
	A[1]=B[1];
	for(int i=2;i<=n;i++)
	{
		if(B[i]==B[i-1])
		{
			while(visi[mini])
				mini++;
			while(visi[maxi])
				maxi--;
			visi[maxi]=true;
			visi[mini]=true;
			A[2*i-2]=mini;
			A[2*i-1]=maxi;
		}
		else if(B[i]>B[i-1])
		{
			if(!visi[B[i]])
			{
				A[2*i-2]=B[i];
				visi[B[i]]=true;
				while(visi[maxi])
					maxi--;
				visi[maxi]=true;
				A[2*i-1]=maxi;
			}
			else
			{
				while(visi[maxi])
					maxi--;
				visi[maxi]=true;
				A[2*i-2]=maxi;
				while(visi[maxi])
					maxi--;
				visi[maxi]=true;
				A[2*i-1]=maxi;
			}
		}
		else if(B[i]<B[i-1])
		{
			if(!visi[B[i]])
			{
				A[2*i-2]=B[i];
				visi[B[i]]=true;
				while(visi[mini])
					mini++;
				visi[mini]=true;
				A[2*i-1]=mini;
			}
			else
			{
				while(visi[mini])
					mini++;
				visi[mini]=true;
				A[2*i-2]=mini;
				while(visi[mini])
					mini++;
				visi[mini]=true;
				A[2*i-1]=mini;
			}
		}
	}
	for(int i=1;i<=2*n-1;i++)
	{
		if(i!=1)
			cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	return 0;
}