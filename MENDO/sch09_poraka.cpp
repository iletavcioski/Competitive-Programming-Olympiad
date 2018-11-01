#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int nn;
    cin>>nn;
    vector<string> vk;
     
    for(int i=0;i<nn;i++)
    {
        string ss;
        cin>>ss;
        string s1;
        cin>>s1;
        int j=0;
        while(1)
        {
            int jj=0;
            while(1)
            {
                if(j==ss.size())
                    break;
                if(jj==s1.size())
                    break;
                else if(ss[j]==s1[jj])
                    j++,jj++;
                else
                    jj++;
                 
            }
            if(j==ss.size())
                vk.push_back("DA");
            else
                vk.push_back("NE");
            break;
        }
    }
    for(int i=0;i<vk.size();i++)
        cout<<vk[i]<<endl;
    return 0;
}