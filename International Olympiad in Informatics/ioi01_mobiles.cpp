#include <algorithm>
#include <cstdio>
#include <iostream>
int bit[1030][1030];
int n;
void updatey(int x,int y,int val)
{
    if(!y)
    {
        bit[x][y]+=val;
        return;
    }
    while(y<n)
    {
        bit[x][y]+=val;
        y+=(y&-y);
    }
}
void update(int x,int y,int val)
{

    if(!x)
    {
        updatey(x,y,val);
        return;
    }

    while(x<n)
    {
        updatey(x,y,val);
        x+=(x&-x);
    }
}
int queryy(int x,int y)
{
    if(y<0) 
        return 0;
    int brojac;
    brojac=bit[x][0];
    while(y)
    {
        brojac+=bit[x][y];
        y-=(y&-y);
    }
    return brojac;
}
int query(int x,int y1,int y2)
{
    if(x<0)
        return 0;
    int brojac;
    brojac=queryy(0,y2)-queryy(0,y1-1);
    while(x)
    {
        brojac+=queryy(x,y2)-queryy(x,y1-1);
        x-=(x&-x);
    }
    return brojac;
}
int main()
{
    int typ,x1,x2,y1,y2,val;
    scanf("%d%d",&typ,&n);
    scanf("%d",&typ);
    while(typ<3)
    {
        if(typ==1)
        {
            scanf("%d%d%d",&x1,&y1,&val);
            update(x1,y1,val);
        }
        else
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%d\n",query(x2,y1,y2)-query(x1-1,y1,y2));
        }
        scanf("%d",&typ);
    }
    return 0;
}