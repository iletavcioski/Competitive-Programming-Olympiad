#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
typedef long long ll;
using namespace std;
  
//DON'T EDIT THIS FUNCTION, AS IT'S HERE TO SUPPORT
//THE COMMUNICATION WITH THE INTERACTIVE GRADER
int count(string expression) {
    cout << expression << endl;
      
    int matchingRecords;
    cin >> matchingRecords;
    return matchingRecords;
}
  
  
//YOUR SOLUTION STARTS HERE
int findMoney(int N) {
    ll l=1,r=2000000000;
    ll money=0;
    int val=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        string ss="";
        int p=mid;
        if(p==0)
            ss+='0';
        while(p>0)
        {
            int t=p%10;
            ss+=(t+'0');
            p/=10;
        }
        reverse(ss.begin(),ss.end());
        string sk="name != bidik || money < ";
        sk+=ss;
        val=count(sk);
        if(val==N)
            r=mid-1;
        else{
            l=mid+1;
        money=max(money,mid);
        }
    }
    return money;
}
  
int main(){
    int n;
    cin >> n;
  
    cout << findMoney(n) << endl;
    return 0;
}