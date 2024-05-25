#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int p,d[10],r2,r3;
double i;

//checking middle value
void middle(int u,int g)
{r2=0;
//return;
for(int f=0;f<u;f++)
{
if (d[f]==g)
{ r2=1;
return;
}
}
r3=0;
}



//Checking Jump

int jump()
{

for (int j=0;j<(p-1);j++)
{
if (d[j]==1)
{
if (d[j+1]==3) middle(j,2);
if (d[j+1]==7) middle(j,4);
if (d[j+1]==9) middle(j,5);
} 

else if (d[j]==3)
{
if (d[j+1]==1) middle(j,2);
if (d[j+1]==7) middle(j,5);
if (d[j+1]==9) middle(j,6);
} 

else if (d[j]==7)
{
if (d[j+1]==1) middle(j,4);
if (d[j+1]==3) middle(j,5);
if (d[j+1]==9) middle(j,8);
} 

else if (d[j]==9)
{
if (d[j+1]==3) middle(j,6);
if (d[j+1]==7) middle(j,8);
if (d[j+1]==1) middle(j,5);
} 

else if (d[j]==2 && d[j+1]==8) 
middle(j,5);

else if (d[j]==4 && d[j+1]==6) 
middle(j,5);

else if (d[j]==6 && d[j+1]==4)
middle(j,5);

else if (d[j]==8 && d[j+1]==2)
middle(j,5);

}
return 1;
}



//Repetition Check

int rep()
{int b=i,rr;
for (int j=0;j<p;j++)
{

if(d[j]==0)
return 0;
for ( int k=(j+1);k<p;k++)
{
if(d[j]==d[k])
return 0;
}
}
rr=jump();
return rr;
}

//main
int main()
{
int m=0,r;

for(int x=4;x<10;x++)
{
int n=0;
p=x;

for (i=round(pow(10,(p-1)));i<round(pow(10,p));i++)
{
int a=i;
r2=1;r3=1;
//asignment
for (int j=p-1;j>=0;j--)
{
d[j]=a%10;
a=a/10;
}
r=rep();

if (r==1 && r2==1 && r3==1)
{
n++;
cout.setf(ios::fixed);
cout<<setprecision(0)<<"\n"<<i;
}
}
//cout<<p<<"="<<n<<"\n";
m+=n;
}
//cout<<"total="<<m<<"\n";
return 0;
}