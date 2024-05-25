#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<snap.h>
#include<graphics.h>
#include<string.h>



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
{int rr;
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

int pline(double h,int p)
{
int f,s,a,x[10],y[10],b=180;
double i;char t[20]={"c:\\TC\\capture\\"},u[10]={".jpg"},e[20],o[20];
int gdriver=DETECT,gmode;
//clrscr();

i=h;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
//printf("%lf \n",i);
x[5]=getmaxx()/2;
y[5]=getmaxy()/2;
setcolor(RED);
setfillstyle(1,RED);
circle(x[5],y[5],6);floodfill(x[5],y[5],RED);
//printf("%d %d \n",x[5],y[5]);
x[1]=x[5]-b;y[1]=y[5]-b;circle(x[1],y[1],6);floodfill(x[1],y[1],RED);
x[2]=x[5];y[2]=y[5]-b;circle(x[2],y[2],6);  floodfill(x[2],y[2],RED);
x[3]=x[5]+b;y[3]=y[5]-b;circle(x[3],y[3],6);floodfill(x[3],y[3],RED);
x[4]=x[5]-b;y[4]=y[5];circle(x[4],y[4],6);  floodfill(x[4],y[4],RED);
x[6]=x[5]+b;y[6]=y[5];circle(x[6],y[6],6);  floodfill(x[6],y[6],RED);
x[7]=x[5]-b;y[7]=y[5]+b;circle(x[7],y[7],6);floodfill(x[7],y[7],RED);
x[8]=x[5];y[8]=y[5]+b;  circle(x[8],y[8],6);floodfill(x[8],y[8],RED);
x[9]=x[5]+b;y[9]=y[5]+b;circle(x[9],y[9],6);floodfill(x[9],y[9],RED);
a=fmod(i,10);
i=i-a;i=i/10;
//printf("%d %lf",a,i);
f=a;
e[p]='\0';
//setbkcolor(4);
setlinestyle(0,0,3);
setcolor(10);
circle(x[f],y[f],20);
for(int j=1;j<p;j++)
{
e[p-j]=a+48;
 a=fmod(i,10);
i=i-a;i=i/10;
s=a;
setcolor(10);
circle(x[s],y[s],20);
//printf("\n%d %d %d %d",x[f],y[f],x[s],y[s]);
setcolor(6);
line(x[f],y[f],x[s],y[s]);
f=s;
 }e[0]=s+48;
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy((getmaxx()/2)-10,450,e);
 strcpy(o,t);
strcat(o,e);strcat(o,u);
//printf("\n%s",e);
//printf("\n%s",o);

capture(o);cleardevice();
//getch();
closegraph();

return 0;
}

//main
int main()
{
int m=0,r;

for(int x=9;x<10;x++)
{
int n=0;
p=x;

for (i=412356789/*pow(10,(p-1))*/;i<600000000/*pow(10,p)*/;i++)
{
double a=i;
r2=1;r3=1;
//asignment
for (int j=p-1;j>=0;j--)
{
d[j]=fmod(a,10);
a=a-d[j];a=a/10;
}
r=rep();

if (r==1 && r2==1 && r3==1)
{
n++;
pline(i,p);
//cout<<setprecision(0)<<"\n"<<i;
}
}
//cout<<"possibilities of"<<p<<"="<<n<<"\n";
m+=n;
}
//cout<<"total no of possibilities ="<<m<<"\n";
return 0;
}