#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const int mod=1000000007;
bool vis[53];
map<vector<int>, int> m;
vector<int> mask;
int decode(char c) 
{
    if(c>='a'&&c<='z')
    {
        return c-'a';
    }
    else 
    {
        return c-'A'+26;
    }
}
void addtomask(char c) 
{
    int decodedValue=decode(c);
    if(mask[decodedValue]==0) 
    {
        for(int i=0;i<52;i++) 
        {
            if(vis[i]&&i!=decodedValue)
            {
                mask[i]++;
            }
        }
    }
    else 
    {
        mask[decodedValue]--;
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++) 
    {
        if(!vis[decode(s[i])]) 
        {
            vis[decode(s[i])]=true;
        }
    }
    for(int i=0;i<52;i++) 
    {
        mask.push_back(0);
    }
    m[mask]=1;
    ll brojac=0;
    for(int i=0;i<n;i++) 
    {
        addtomask(s[i]);  
        brojac+=1LL*m[mask];
        m[mask]++;
    }
    cout<<brojac%mod<<endl;
    return 0;
}
