#include <iostream>
using namespace std;
int visi[101][101];
int brojac;
 int mat[101][101];
 int n,m;
void dfs(int x,int y)
{
    if(visi[x][y])
    return;
    visi[x][y]=brojac;
    if(y>0){
    if((mat[x][y]&1)==0)
    {
        dfs(x,y-1);
    }
     }
     if(y<(m-1))
     {
         if((mat[x][y]&4)==0){
            dfs(x,y+1);
         }
     }
     if(x>0){
    if((mat[x][y]&2)==0){
        dfs(x-1,y);
    }
     }
     if(x<(n-1))
     {
         if((mat[x][y]&8)==0){
            dfs(x+1,y);
         }
     }

}
int main()
{
//ifstream fin("castle.in");
//ofstream fout("castle.out");
   cin>>m>>n;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        cin>>mat[i][j],visi[i][j]=0;
   }
   brojac=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(!visi[i][j])
           {
               brojac++;
               dfs(i,j);
           }
       }
   }
   cout<<brojac<<endl;
   int v[3003];
   for(int i=0;i<3003;i++)
    v[i]=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           v[visi[i][j]]++;
       }
   }
   int maxi=0;
   for(int i=1;i<=brojac;i++)
    maxi=max(maxi,v[i]);
   cout<<maxi<<endl;
   int maxxi=0;
   int x1=-1;
   int y1=-1;
   char s;
   for(int j=0;j<m;j++)
   {
       for(int i=n-1;i>=0;i--)
       {
 if((mat[i][j]&2)&&i>0)
           {
               if(visi[i][j]!=visi[i-1][j]){
               if(maxxi<v[visi[i][j]]+v[visi[i-1][j]])
               {
                   maxxi=v[visi[i][j]]+v[visi[i-1][j]];
                   x1=i+1;
                   y1=j+1;
                   s='N';
               }
               }
           }
           if((mat[i][j]&4)&&j<m-1)
           {
               if(visi[i][j]!=visi[i][j+1]){
               if(maxxi<v[visi[i][j]]+v[visi[i][j+1]])
               {
                   maxxi=v[visi[i][j]]+v[visi[i][j+1]];
                   x1=i+1;
                   y1=j+1;
                   s='E';
               }
               }
           }
          
       }
   }
   cout<<maxxi<<endl;
   cout<<x1<<" "<<y1<<" "<<s<<endl;
  
    return 0;
}