#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    lldiv_t broj;
    int den;
    int mesec;
    int godina;
    int grupa;
    int ostatok;
    long long zbir;
    long long kolicnik;
    long long broevi;
    vector<int> v;
    vector<int>vgodina;
    for(int i=0;i<3;i++)
    {
    cin>>broevi;
    do{
        broj=lldiv(broevi, 10);
        v.push_back(broj.rem);
        broevi=broj.quot;
    }while(broj.quot>0);
    if(v.size()==7)
    {
        v.push_back(0);
        v.push_back(0);
    }
    reverse(v.begin(),v.end());
    den=v[0]*10+v[1];
    mesec=v[2]*10+v[3];
    godina=v[4]*100+v[5]*10+v[6];
    grupa=v[7];
    ostatok=v[8];
    vgodina.push_back(v[4]);
    vgodina.push_back(v[5]);
    vgodina.push_back(v[6]);
    zbir=v[0]*v[0]+v[1]*v[1]+v[2]*v[2]+v[3]*v[3]+v[4]*v[4]+v[5]*v[5]+v[6]*v[6]+v[7]*v[7];
    kolicnik=zbir/7;
    if(godina>=0&&godina<=599)
    {
        vgodina.push_back(2);
    }
    else if(godina>=600&&godina<=999)
    {
        vgodina.push_back(1);
    }
    godina=vgodina[0]*100+vgodina[1]*10+vgodina[2]*1+vgodina[3]*1000;
    if(den==29&&mesec==2&&((godina%4!=0||godina%4==0)&&godina%100==0)&&godina%400!=0)
    {
        cout<<"0"<<endl;
    }
    else if((den==0||den<=28)&&mesec==2&&(godina%400==0||(godina%4==0&&godina%100!=0)))
    {
        cout<<"0"<<endl;
    }
    else if(mesec==0||mesec>=13)
    {
        cout<<"0"<<endl;
    }
        
    else if(den==0||den>=32&&(mesec==1||mesec==3||mesec==5||mesec==7||mesec==8||mesec==10||mesec==12))
    {
        cout<<"0"<<endl;
    }
    else if((den==0||den>=31)&&(mesec==4||mesec==6||mesec==9||mesec==11))
    {
        cout<<"0"<<endl;
    }
    else if(grupa!=1&&grupa!=6&&grupa!=9)
    {
        cout<<"0"<<endl;
    }
    else if((ostatok+(kolicnik*7))!=zbir)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"1"<<endl;
    }
    v.clear();
    vgodina.clear();
    zbir=0;
    kolicnik=0;
    den=0;
    mesec=0;
    godina=0;
    grupa=0;
    ostatok=0;
    }
    return 0;
}