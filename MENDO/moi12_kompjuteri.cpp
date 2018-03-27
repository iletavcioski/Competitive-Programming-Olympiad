#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<double> rooms;
vector<double> teachers;
int n,m;
double dp[101][1<<14];
double traveling_salesman_problem(int x,int bitmask)
{
    if(dp[x][bitmask]==1e9)
    {
        for(int i=0;i<m;i++)
        {
            if(!(bitmask&(1<<i)))
            {
                double brojac=rooms[x]/teachers[i];
                for(int j=x;j<n;j++)
                {
                    if(j!=x)
                        brojac+=rooms[j]/teachers[i];
                    if(brojac>dp[x][bitmask])
                        break;
                    dp[x][bitmask]=min(dp[x][bitmask],max(brojac,traveling_salesman_problem(j+1,bitmask|(1<<i))));
                }
            }
        }
    }
        return dp[x][bitmask];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        rooms.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        double a;
        cin>>a;
        teachers.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            dp[i][j]=1e9;
            dp[n][j]=0;
        }
    }
    cout<<fixed<<setprecision(6);
    cout<<traveling_salesman_problem(0,0)<<endl;
    return 0;
}