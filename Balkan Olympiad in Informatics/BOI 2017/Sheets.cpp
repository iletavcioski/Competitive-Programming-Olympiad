#include <iostream>
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ii;
ii niza[32];
int main()
{
	int Q;
	scanf("%d",&Q);
	ii po=1;
	for(int i=0;i<=31;i++)
	{
		niza[i]=po;
		po*=2;
	}
	while(Q--)
	{
		int T;
		scanf("%d",&T);
		if(T==2)
		{
			int K;
			scanf("%d",&K);
			ll P;
			scanf("%lld",&P);
			ii i=1LL,j=1LL;
			ll broj=niza[K];
			ll h=1LL*broj*broj;
			ii sirina=1LL;
			ii dolzina=1LL;
			ll k=P;
			ii p=0;
			while(h!=1)
			{
				h/=2;
					if(k>h)
					{
						j=j+(2*(dolzina-j))+1;
						k=h-(k-h)+1LL;
					}
					dolzina*=2;
		       h/=2;
					if(k>h)
					{
						i=i+(2*(sirina-i))+1;
						k=h-(k-h)+1LL;
					}
					sirina*=2;
			}
			i--;
			ll brojac=i*broj+j;
			printf("%lld\n",brojac);
		}
		else
		{
			int K;
			scanf("%d",&K);
			ll X;
			scanf("%lld",&X);
			ii i=0,j=0;
			ll broj=niza[K];
			ll brojce=0;
			ii l=0,r=broj;
			while(l<=r) 
			{
				ii mid=(l+r)/2;
				if((ll)mid*broj>X)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
					i=max(i,mid);
				}
			}
			j=X-(i*broj);
			ll h=1LL;
			ll k=1LL;
			if(j!=0LL)
				i++;
			else
				j=(ii)broj;
			ii sirina=broj,dolzina=broj;
			while(h!=(broj*broj))
			{
				sirina/=2;
					if(i>sirina)
					{
						i=sirina-(i-sirina)+1;
						k=h-k+1LL;
						k+=h;
					}
					h*=2;
					dolzina/=2;
					if(j>dolzina)
					{
						j=dolzina-(j-dolzina)+1LL;
						k=h-k+1LL;
						k+=h;
					}
				h*=2;
			}
			printf("%lld\n",k);
		}
	}
	return 0;
}