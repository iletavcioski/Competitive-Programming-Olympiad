#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int maxi=0;
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int brojac=0;
        int potrebno=m/n;
        if(i<(m%n))
            potrebno++;
         
        q.push(make_pair(a,i));
        while(!q.empty())
        {
            if((brojac+q.front().first)<=potrebno)
            {
                brojac+=q.front().first;
                maxi=max(maxi,(i-q.front().second));
                    q.pop();
                     
            }
            else
            {
                q.front().first-=(potrebno-brojac);
                break;
            }
            if(brojac==potrebno)
                break;
        }
    }
    cout<<maxi<<endl;
    return 0;
}