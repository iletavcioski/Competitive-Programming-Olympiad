#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int niza[100000];
    string ss1;
    string ss2;
    memset(niza,0,sizeof(niza));
    int max=0;
    for(int i=0;i<n;i++)
    {
        cin>>ss1>>ss2;
           
            int broj=0;
            int broj1=0;
            broj=((ss1[7]-'0')*1)+((ss1[6]-'0')*10)+((ss1[4]-'0')*60)+((ss1[3]-'0')*600)+((ss1[1]-'0')*3600)+((ss1[0]-'0')*36000);
            broj1=((ss2[7]-'0')*1)+((ss2[6]-'0')*10)+((ss2[4]-'0')*60)+((ss2[3]-'0')*600)+((ss2[1]-'0')*3600)+((ss2[0]-'0')*36000); 
            for(int j=broj;j<=broj1;j++)
            {
                niza[j]++;
                if(niza[j]>max)
                {
                    max=niza[j];
                }
            }
           
    }
    cout<<max<<endl;
    return 0;
}