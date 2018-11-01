#include<iostream>
#include<vector>
#include<queue>
using namespace std;
   
int main()
{
    vector<int> v1,v2,v3;
    int n;
    cin>>n;
    int arr[21][3];
    for(int i=0;i<n;i++)
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    int brojac=9999999;
    for(int i=0;i<3;i++)
    {
        queue<int>qi;
        qi.push(i);
        queue<int>qs;
        qs.push(arr[0][i]);
        queue<int>qd;
        qd.push(0);
           
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int tops=qs.front();
            qs.pop();
            int topd=qd.front();
            qd.pop();
            if(topd==n-1)
                brojac=min(brojac,tops);
            if(topd<n-1){
                if(topd==n-2)
                {
                    if(topi==0)
                    {
                        if(i!=1)
                        {
                            qi.push(1);
                qs.push(tops+arr[topd+1][1]);
                qd.push(topd+1);
                        }
                        if(i!=2)
                        {
                            qi.push(2);
                qs.push(tops+arr[topd+1][2]);
                qd.push(topd+1);
                        }
                    }
                    else if(topi==1)
                    {
                        if(i!=0)
                        {
                            qi.push(0);
                qs.push(tops+arr[topd+1][0]);
                qd.push(topd+1);
                        }
                        if(i!=2)
                        {
                            qi.push(2);
                qs.push(tops+arr[topd+1][2]);
                qd.push(topd+1);
                        }
                    }
                    else if(topi==2)
                    {
                        if(i!=1)
                        {
                            qi.push(1);
                qs.push(tops+arr[topd+1][1]);
                qd.push(topd+1);
                        }
                        if(i!=0)
                        {
                            qi.push(0);
                qs.push(tops+arr[topd+1][0]);
                qd.push(topd+1);
                        }
                    }
                }
            else if(topi==0)
            {
                qi.push(1);
                qs.push(tops+arr[topd+1][1]);
                qd.push(topd+1);
                qi.push(2);
                qs.push(tops+arr[topd+1][2]);
                qd.push(topd+1);
            }
            else if(topi==1)
            {
                qi.push(0);
                qs.push(tops+arr[topd+1][0]);
                qd.push(topd+1);
                qi.push(2);
                qs.push(tops+arr[topd+1][2]);
                qd.push(topd+1);
            }
            else if(topi==2)
            {
                qi.push(1);
                qs.push(tops+arr[topd+1][1]);
                qd.push(topd+1);
                qi.push(0);
                qs.push(tops+arr[topd+1][0]);
                qd.push(topd+1);
            }
            }
        }
    }
     cout<<brojac<<endl;
    return 0;
}