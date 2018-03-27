#include <iostream>
#include <vector>
using namespace std;
struct trie
{
	char a;
	int d;
	trie* bukvi[26];
	trie* rod[20];
	trie(char bukva,int dlabocina,trie* p)
	{
		this->a=bukva;
		this->d=dlabocina;
		for(int i=0;i<26;i++)
			bukvi[i]=NULL;
		for(int i=0;i<20;i++)
			rod[i]=NULL;
		rod[0]=p;
		for(int i=1;i<20;i++)
		{
			if(rod[i-1]!=NULL)
				rod[i]=rod[i-1]->rod[i-1];
		}
	}
};
trie* v[1000001];
trie* dodaj(trie* t,char bukva)
{
	if(t->bukvi[bukva-'a']==NULL)
	{
		t->bukvi[bukva-'a']=new trie(bukva,t->d+1,t);
	}
	return t->bukvi[bukva-'a'];
}
char najdi(trie* t,int pos)
{
	trie* t1=t;
	while(1)
	{
		if(t1->d==pos)
		{
			return t1->a;
		}
		for(int i=19;i>=0;i--)
		{
			if(t1->rod[i]!=NULL)
			{
				if(t1->rod[i]->d>=pos)
				{
					t1=t1->rod[i];
					break;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	trie t=trie(' ',0,NULL);
	v[0]=&t;
	int broj=0;
	for(int i=0;i<n;i++)
	{
		char a;
		scanf(" %c",&a);
		if(a=='U')
		{
			int bb;
			scanf("%d",&bb);
			v[broj+1]=v[broj-bb];
			broj++;
		}
		else if(a=='T')
		{
			char bb;
			scanf(" %c",&bb);
			v[broj+1]=dodaj(v[broj],bb);
			broj++;
		}
		else if(a=='P')
		{
			int b;
			scanf("%d",&b);
			char c=najdi(v[broj],b+1);
			printf("%c\n",c);
		}
	}
	return 0;
}