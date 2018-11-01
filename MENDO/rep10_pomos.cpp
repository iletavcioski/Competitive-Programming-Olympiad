#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<string> ime;
    vector<int> v1;
    vector<int> v2;
    int kkkk=n;
    for(int i=0;i<k;i++)
    {
        string ss;
        cin>>ss;
        int bb;
        cin>>bb;
        ime.push_back(ss);
        v1.push_back(bb);
        int bbb;
        cin>>bbb;
        v2.push_back(bbb);
    }
    long long maxi=99999999999;
    string kraj;
    for(int i=0;i<ime.size();i++)
    {
        long long brojac=0;
        bool kkk=true;
        n=kkkk;
        while(n>=0)
        {
            if(n-((n+1)/2)>=m)
            {
                if(((n+1)/2)*v1[i]>=v2[i])
                {
                    brojac+=v2[i];
                    n-=((n+1)/2);
                }
                else
                {
                    brojac+=((n+1)/2)*v1[i];
                    n-=((n+1)/2);
                }
            }
            else
                break;
        }
        brojac+=(n-m)*v1[i];
        if(brojac<maxi)
        {
            maxi=brojac;
            kraj=ime[i];
        }
    }
    cout<<kraj<<" "<<maxi<<endl;
    return 0;
}