#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
ifstream fin("job.in"); 
ofstream fout("job.out");
const int MAX_N=1000,MAX_M1=30,MAX_M2=30;
int N,M1,M2,A[MAX_M1],Atime[MAX_M1],B[MAX_M2],Btime[MAX_M2]; 
int main()
{
    cin>>N;
	cin>>M1;
    for(int i=0;i<M1;i++)
		cin>>A[i];
	cin>>M2;
    for(int i=0;i<M2;i++) 
		cin>>B[i];
    vector<int> AfinishTimes;
    memset(Atime,0,sizeof(Atime));
    for(int i=0;i<N;i++)
	{
        int minTime=1e9,minPos=-1;
        for(int j=0;j<M1;j++)
		{
            if(Atime[j]+A[j]<minTime)
			{
                minTime=Atime[j]+A[j];
                minPos=j;
            }
        }
        Atime[minPos]=minTime;
        AfinishTimes.push_back(minTime);
    }
    int timeA=0;
    for(int i=0;i<M1;i++) 
		timeA=max(timeA,Atime[i]);
    sort(AfinishTimes.begin(),AfinishTimes.end());
    vector<int> BfinishTimes;
    memset(Btime,0,sizeof(Btime));
    for(int i=0;i<N;i++)
	{
        int minTime=1e9,minPos=-1;
        for(int j=0;j<M2;j++)
		{
            if(Btime[j]+B[j]<minTime)
			{
                minTime=Btime[j]+B[j];
                minPos=j;
            }
        }
        Btime[minPos]=minTime;
        BfinishTimes.push_back(minTime);
    }
    int timeB=0;
    for(int i=0;i<M2;i++) 
		timeB=max(timeB,Btime[i]); 
    sort(BfinishTimes.begin(),BfinishTimes.end());
    int maxTime=0;
    for(int i=0;i<N;i++)
	{
        maxTime=max(maxTime,AfinishTimes[i]+BfinishTimes[N-1-i]);
    }
    cout<<timeA<<endl;
	cout<<maxTime<<endl;
    return 0;
}