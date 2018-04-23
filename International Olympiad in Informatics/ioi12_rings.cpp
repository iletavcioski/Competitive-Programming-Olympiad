#include <vector>
#include <iostream>
using namespace std;
int n;
bool cetvorka=0;
int broj_na_ciklusi=0;
int dolzina_na_ciklusot;
int krajni_tocki[4][1000001];
vector<vector<int> > graf;
int kriticni_cetvorka[4];
int stepen[4][1000001];
bool dali_e_linearno[4];
void Init(int k)
{
    n=k;
    vector<int> vec;
    graf.insert(graf.begin(),n+1,vec);
    for(int i=0;i<n;i++)
    {
        krajni_tocki[0][i]=i;
    }
}
void dodavanje_na_rebro_cetvorka(int x,int y)
 {
    for(int i=0;i<4;i++)
    {
        if(!dali_e_linearno[i])
            continue;
        if(x==kriticni_cetvorka[i]||y==kriticni_cetvorka[i])
            continue;
        stepen[i][x]++;
        stepen[i][y]++;
        if(stepen[i][x]==3||stepen[i][y]==3)
        {
            dali_e_linearno[i]=0;
            continue;
        }
        if(krajni_tocki[i][x]==y)
        {
            dali_e_linearno[i]=0;
            continue;
        }
        int a=krajni_tocki[i][x];
        int b=krajni_tocki[i][y];
        krajni_tocki[i][x]=-1;
        krajni_tocki[i][y]=-1;
        krajni_tocki[i][a]=b;
        krajni_tocki[i][b]=a;
    }
}
void cetvorki(int x)
{
    cetvorka=1;
    kriticni_cetvorka[0]=x;
    kriticni_cetvorka[1]=graf[x][0];
    kriticni_cetvorka[2]=graf[x][1];
    kriticni_cetvorka[3]=graf[x][2];
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<n;j++)
        {
            krajni_tocki[i][j]=j;
            stepen[i][j]=0;
        }
    }
    for(int i=0;i<4;i++)
    {
        dali_e_linearno[i]=1;
    }
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<graf[k].size();j++)
        {
            if(k<graf[k][j])
                dodavanje_na_rebro_cetvorka(k,graf[k][j]);
        }
    }
}
void Link(int xx,int yy)
 {
    int x=xx;
    int y=yy;
    if(cetvorka==0)
    {
        graf[x].push_back(y);
        graf[y].push_back(x);
        stepen[0][x]++;
        stepen[0][y]++;
        if(stepen[0][x]==3)
        {
            cetvorki(x);
            return;
        }
        if(stepen[0][y]==3)
        {
            cetvorki(y);
            return;
        }
        if(krajni_tocki[0][x]!=y)
        {
            int a=krajni_tocki[0][x];
            int b=krajni_tocki[0][y];
            krajni_tocki[0][x]=-1;
            krajni_tocki[0][y]=-1;
            krajni_tocki[0][a]=b;
            krajni_tocki[0][b]=a;
        }
        else
        {
            broj_na_ciklusi++;
            if(broj_na_ciklusi==1)
            {

                int dolzina=1;
                int prev=x;
                int current=graf[x][0];
                while(current!=x)
                {
                    int mozno=graf[current][0];
                    if(mozno==prev)
                        mozno=graf[current][1];
                    prev=current;
                    current=mozno;
                    dolzina++;
                }
                dolzina_na_ciklusot=dolzina;
            }
        }
    }
    else
    {
        dodavanje_na_rebro_cetvorka(x,y);
    }
}
int CountCritical()
{
    if(cetvorka==0)
    {
        if(broj_na_ciklusi==0)
            return n;
        else if(broj_na_ciklusi==1)
            return dolzina_na_ciklusot;
        else
            return 0;
    }
    else
    {
        int brojac=0;
        for(int i=0;i<4;i++)
        {
            if(dali_e_linearno[i])
             brojac++;
        }
        return brojac;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int broj;
    cin>>broj;
    Init(broj);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(a==-1)
            printf("%d\n",CountCritical());
        else
        {
            int b;
            cin>>b;
            Link(a,b);
        }
    }
    return 0;
}