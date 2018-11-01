#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v;
    vector<int> v1,v2;
    string s1,s2;
    cin>>s1>>s2;
    if(s2.size()>s1.size())
        swap(s2,s1);
        reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++)
        v1.push_back(s1[i]-'0');
        for(int i=0;i<s2.size();i++)
        v2.push_back(s2[i]-'0');
        while(v2.size()<v1.size())
            v2.push_back(0);
        int prenos=0;
        int brojac=0;
        for(int i=0;i<v1.size();i++)
        {
            int brojce=prenos+v1[i]+v2[i];
            if(brojce>=10){
                brojce-=10,brojac++;
            prenos=1;
            }
            else
                prenos=0;
            v.push_back(brojce);
        }
        cout<<brojac<<endl;
    return 0;
}