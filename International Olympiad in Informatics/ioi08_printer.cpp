#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
string najgolem="";
vector<char> v;
bool kraj=false;
int zbir=0;
struct trie
{
    int zbor;
    trie *node[26];
    trie()
    {
        zbor=0;
        for(int i=0;i<26;i++) {
            node[i] = NULL;
        }
    }
};
void insert(int i,trie &t)
{
    if(i==s.size())
    {
        zbir++;
        t.zbor++;
        return;
    }
    if(t.node[s[i]-'a']!=NULL)
    {
        insert(i+1,*t.node[s[i]-'a']);
    }
    else
    {
        zbir+=2;
        t.node[s[i]-'a']=new trie();
        insert(i+1,*t.node[s[i]-'a']);
    }
}
void dfs(trie &t,int j)
{
    if(kraj)
        return;
    if(t.zbor)
    {
        printf("%c\n",'P');
        t.zbor--;
    }
    bool cc=false;
    char a1=najgolem[j];
    int b=a1-'a';
    if(j==najgolem.size())
    {
        kraj=true;
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(b==i) {
            cc=true;
            continue;
        }
        if(t.node[i]!=NULL)
        {
            char a=i+'a';
            printf("%c\n",a);
            dfs(*t.node[i],-1);
        }
    }
    if(cc) {
        printf("%c\n",a1);
        dfs(*t.node[b],j+1);
        if(j==najgolem.size()-1)
        {
            kraj=true;
            return;
        }
    }
    if(!kraj) {
        printf("%c \n",'-');
    }
    return;
}
int main()
{

    int n;
    cin>>n;
    trie koren;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s.size()>najgolem.size()) {
            najgolem = s;
        }
        insert(0,koren);
    }
    zbir-=najgolem.size();
    cout<<zbir<<endl;
    dfs(koren,0);
    return 0;
}