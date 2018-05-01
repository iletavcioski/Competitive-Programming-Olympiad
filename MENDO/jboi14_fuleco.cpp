#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int k;
    cin>>n>>k;
    string ss;
    cin>>ss;
    int min;
    int max;
    if(n<k)
    {
        min=n;
        max=k;
    }
    else
    {
        min=k;
        max=n;
    }
    bool visited[1000000];
    memset(visited, false,sizeof(visited));
    int brojac=0;
    int temp;
    int krajna;
    for(int i=min;i<max;i++)
    {
        if(ss[i]=='U')
        {
            temp=i;
            break;
        }
    }
    krajna=temp;
    for(int  i=min;i<max;i++)
    {
        if(ss[i]=='D'&&visited[i]==false)
        {
            visited[i]=true;
            brojac++;
        }
        else if(ss[i]=='U'&&visited[i]==false)
        {
            temp=krajna;
            for(int j=temp;j<max;j++)
            {
                if(ss[j]=='D'&&visited[j]==false)
                {
                    visited[i]=true;
                    visited[j]=true;
                    krajna=j;
                    break;
                }
            }
            if((ss[i]=='U')&&(visited[i]==false))
            {
            brojac++;
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}