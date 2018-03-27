#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int x0;
int y_first;
bool is_red(int x,int y)
{
	if(x>n||y>n||x<1||y<1)
		return 0;
	bool check=0;
	string ss;
	cout<<"examine "<<x<<" "<<y<<endl;
	cin>>ss;
	if(ss=="true")
		check=1;
	return check;
}
int find_first_white(int dx,int dy)
{
	int i=0;
	int num=1;
	int a=(x0+(num*dx)-dx);
	int b=(y_first+(num*dy)-dy);
	while(is_red(a,b))
	{
		i++;
		num*=2;
		a=(x0+(num*dx)-dx);
		b=(y_first+(num*dy)-dy);
	}
	int l=((num/2)-1);
	int r=(num-1);
	while((l+1)<r)
	{
		int mid=(l+r)/2;
		a=x0+(mid*dx);
		b=y_first+(mid*dy); 
		if(is_red(a,b))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	return r;
}
int main()
{
	cin>>n>>x0>>y_first;
	int left=find_first_white(0,-1);
  	int right=find_first_white(0,1);
  	int up=find_first_white(-1,0);
    int side_length=right+left-1;
    int squares_left=find_first_white(0,-2*side_length);
    int squares_right=find_first_white(0,2*side_length);
    int squares_up=find_first_white(-2*side_length, 0);
    int edge_left=y_first-left+1-(squares_left-1)*2*side_length;
    int edge_up=x0-up+1-(squares_up-1)*2*side_length;
    if(squares_left+squares_right-1!=3) 
    {
      edge_left-=side_length;
      edge_up-=side_length;
    }
    int X=edge_up+5*side_length/2;
    int Y=edge_left+5*side_length/2;
    cout<<"solution "<<X<<" "<<Y<<endl;
	return 0;
}