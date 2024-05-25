#include <iostream>
#include <cmath>
using namespace std;

int main()
{  int p,n=0;
   cout << "enter the no of points\n";
   cin>>p;
for (double i=round(pow(10,(p-1)));i<round(pow(10,p));i++)
{
int a=i;
int d[p];
for (int j=0;j<p;j++)
{
d[j]=a%10;
a=a/10;
if(d[j]==0)
goto nextno;
for ( int k=(j-1);k>=0;k--)
{
if(d[j]==d[k])
goto nextno;
}
}
n+=1;
cout<<i<<"\n";
nextno:
;
}
cout<<"no of possibilities for "<<p<<" points is "<<n;
return 0;
}