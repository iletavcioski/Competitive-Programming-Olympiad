#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct Broj
{
    int num;
    int numm;
};
int main()
{
    int n;
    Broj g;
    vector<Broj> vec;
    int brojce=0;
    int max=100000;
    int brojac=0;
    vector<int> v;
    vector<int> niza;
    cin>>n;
    int br;
    for(int i=0;i<n;i++)
    {
        cin>>br;
        niza.push_back(br);
    }
    sort(niza.begin(),niza.end());
    do{
        brojce=0;
        for(int i=0;i<n;i++)
        {
            double k=n-i-1;
            int p=pow(10.0,k)+0.00000001;
            brojce=brojce+(niza[i]*p);
        }
        brojac=0;
        double c;
        c=brojce;
        int koren=sqrt(c)+0.00000001;
              
               
            if(koren*koren==brojce)
            {
               for(int i=1;i<koren;i++)
                {
                    if(brojce%i==0)
                    {
                        brojac+=2;
                    }
                }
               brojac++;
            }
            else
            {
               for(int i=1;i<=koren;i++)
                {
                    if(brojce%i==0)
                    {
                        brojac+=2;
                    }
                }
            }
            if(brojac<max)
            {
                max=brojac;
            }
            g.num=brojce;
            g.numm=brojac;
            vec.push_back(g);
                 
    }while(next_permutation(niza.begin(),niza.end()));
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].numm==max)
        {
            v.push_back(vec[i].num);
        }
    }
    sort(v.begin(),v.end());
    cout<<max<< endl ;
   
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}