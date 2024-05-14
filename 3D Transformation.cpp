#include<iostream>
#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
int gm;
int gd=DETECT;
int x1,x2,x3,y1,y2,y3,z1,z2,z3,nx1,nx2,nx3,ny1,ny2,ny3,nz1,nz2,nz3,c;
int tx, ty, tz, sx, sy, sz, rx, ry, rz;
float theta_x, theta_y, theta_z, shear_xy, shear_xz, shear_yx, shear_yz, shear_zx, shear_zy;
initgraph(&gd,&gm,"c:\\tc\\bg:");
cout<<"\t Program for basic 3D transformations :";
cout<<"\n\t Enter the points of triangle (x, y, z):\n";
cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
cout<<("\n 1. Translation\n 2. Rotation\n 3. Scaling\n 4. Reflection\n 5. Shearing\n 6.
Exit");
cout<<"\nEnter your choice:";
cin>>c;
switch(c)
{
case 1:
cout<<"\n Enter the translation factors (tx, ty, tz): ";
cin>>tx>>ty>>tz;
nx1=x1+tx;
ny1=y1+ty;
nz1=z1+tz;
nx2=x2+tx;
ny2=y2+ty;
nz2=z2+tz;
nx3=x3+tx;
ny3=y3+ty;
nz3=z3+tz;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 2:
cout<<"\n Enter the rotation angles (theta_x, theta_y, theta_z): ";
cin>>theta_x>>theta_y>>theta_z;
theta_x = (theta_x * 3.14) / 180;
theta_y = (theta_y * 3.14) / 180;
theta_z = (theta_z * 3.14) / 180;
nx1 = x1*cos(theta_y)*cos(theta_z) +
x2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
x3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
ny1 = y1*cos(theta_y)*cos(theta_z) +
y2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
y3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
nz1 = z1*cos(theta_y)*cos(theta_z) +
z2*(sin(theta_x)*sin(theta_y)*cos(theta_z)-cos(theta_x)*sin(theta_z)) +
z3*(cos(theta_x)*sin(theta_y)*cos(theta_z)+sin(theta_x)*sin(theta_z));
nx2 = x1*cos(theta_y)*sin(theta_z) +
x2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
x3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
ny2 = y1*cos(theta_y)*sin(theta_z) +
y2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
y3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
nz2 = z1*cos(theta_y)*sin(theta_z) +
z2*(sin(theta_x)*sin(theta_y)*sin(theta_z)+cos(theta_x)*cos(theta_z)) +
z3*(cos(theta_x)*sin(theta_y)*sin(theta_z)-sin(theta_x)*cos(theta_z));
nx3 = x1*-sin(theta_y) + x2*sin(theta_x)*cos(theta_y) +
x3*cos(theta_x)*cos(theta_y);
ny3 = y1*-sin(theta_y) + y2*sin(theta_x)*cos(theta_y) +
y3*cos(theta_x)*cos(theta_y);
nz3 = z1*-sin(theta_y) + z2*sin(theta_x)*cos(theta_y) +
z3*cos(theta_x)*cos(theta_y);
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 3:
cout<<"\n Enter the scaling factors (sx, sy, sz): ";
cin>>sx>>sy>>sz;
nx1=x1*sx;
ny1=y1*sy;
nz1=z1*sz;
nx2=x2*sx;
ny2=y2*sy;
nz2=z2*sz;
nx3=x3*sx;
ny3=y3*sy;
nz3=z3*sz;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 4:
cout<<"\n Reflection about XY-plane";
nx1 = x1;
ny1 = y1;
nz1 = -z1;
nx2 = x2;
ny2 = y2;
nz2 = -z2;
nx3 = x3;
ny3 = y3;
nz3 = -z3;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 5:
cout<<"\n Shearing along X-axis: ";
cout<<"\n Enter the shearing factors (shear_xy, shear_xz): ";
cin>>shear_xy>>shear_xz;
nx1 = x1 + shear_xy * y1 + shear_xz * z1;
ny1 = y1;
nz1 = z1;
nx2 = x2 + shear_xy * y2 + shear_xz * z2;
ny2 = y2;
nz2 = z2;
nx3 = x3 + shear_xy * y3 + shear_xz * z3;
ny3 = y3;
nz3 = z3;
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
break;
case 6:
break;
default:
cout<<"Enter the correct choice";
}
getch();
closegraph()
/*double x1,x2,y1,y2;
void draw_cube(double edge[20][3]){
int i;
cleardevice();
for(i=0;i<19;i++){
x1=edge[i][0]+edge[i][2]*(cos(2.3562));
y1=edge[i][1]-edge[i][2]*(sin(2.3562));
x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
line(x1+320,240-y1,x2+320,240-y2);
}
line(320,240,320,25);
line(320,240,550,240);
line(320,240,150,410);
}
void translate(double edge[20][3]){
int a,b,c;
int i;
cout<<"Enter the Translation Factors : ";
cin>>a>>b>>c;
cleardevice();
for(i=0;i<20;i++){
edge[i][0]+=a;
edge[i][0]+=b;
edge[i][0]+=c;
}
draw_cube(edge);
}
void rotate(double edge[20][3]){
int n;
int i;
double temp,theta,temp1;
cleardevice();
cout<<" 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis \n";
cout<<"Enter your choice : ";
cin>>n;
switch(n){
case 1: cout<<" Enter The Angle ";
cin>>theta;
theta=(theta*3.14)/180;
for(i=0;i<20;i++){
edge[i][0]=edge[i][0];
temp=edge[i][1];
temp1=edge[i][2];
edge[i][1]=temp*cos(theta)-temp1*sin(theta);
edge[i][2]=temp*sin(theta)+temp1*cos(theta);
}
draw_cube(edge);
break;
case 2: cout<<" Enter The Angle ";
cin>>theta;
theta=(theta*3.14)/180;
for(i=0;i<20;i++){
edge[i][1]=edge[i][1];
temp=edge[i][0];
temp1=edge[i][2];
edge[i][0]=temp*cos(theta)+temp1*sin(theta);
edge[i][2]=-temp*sin(theta)+temp1*cos(theta);
}
draw_cube(edge);
break;
case 3: cout<<" Enter The Angle ";
cin>>theta;
theta=(theta*3.14)/180;
for(i=0;i<20;i++){
edge[i][2]=edge[i][2];
temp=edge[i][0];
temp1=edge[i][1];
edge[i][0]=temp*cos(theta)-temp1*sin(theta);
edge[i][1]=temp*sin(theta)+temp1*cos(theta);
}
draw_cube(edge);
break;
}
}
void reflect(double edge[20][3]){
int n;
int i;
cleardevice();
cout<<" 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis \n";
cout<<" Enter Your Choice : ";
cin>>n;
switch(n){
case 1: for(i=0;i<20;i++){
edge[i][0]=edge[i][0];
edge[i][1]=-edge[i][1];
edge[i][2]=-edge[i][2];
}
draw_cube(edge);
break;
case 2: for(i=0;i<20;i++){
edge[i][1]=edge[i][1];
edge[i][0]=-edge[i][0];
edge[i][2]=-edge[i][2];
}
draw_cube(edge);
break;
case 3: for(i=0;i<20;i++){
edge[i][2]=edge[i][2];
edge[i][0]=-edge[i][0];
edge[i][1]=-edge[i][1];
}
draw_cube(edge);
break;
}
}
void perspect(double edge[20][3]){
int n;
int i;
double p,q,r;
cleardevice();
cout<<" 1.X-Axis \n 2.Y-Axis \n 3.Z-Axis\n";
cout<<" Enter Your Choice : ";
cin>>n;
switch(n){
case 1: cout<<" Enter P : ";
cin>>p;
for(i=0;i<20;i++){
edge[i][0]=edge[i][0]/(p*edge[i][0]+1);
edge[i][1]=edge[i][1]/(p*edge[i][0]+1);
edge[i][2]=edge[i][2]/(p*edge[i][0]+1);
}
draw_cube(edge);
break;
case 2: cout<<" Enter Q : ";
cin>>q;
for(i=0;i<20;i++){
edge[i][1]=edge[i][1]/(edge[i][1]*q+1);
edge[i][0]=edge[i][0]/(edge[i][1]*q+1);
edge[i][2]=edge[i][2]/(edge[i][1]*q+1);
}
draw_cube(edge);
break;
case 3: cout<<" Enter R : ";
cin>>r;
for(i=0;i<20;i++){
edge[i][2]=edge[i][2]/(edge[i][2]*r+1);
edge[i][0]=edge[i][0]/(edge[i][2]*r+1);
edge[i][1]=edge[i][1]/(edge[i][2]*r+1);
}
draw_cube(edge);
break;
}
}
void main(){
clrscr();
int gdriver = DETECT , gmode , errorcode;
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
int n;
double
edge[20][3]={100,0,0,100,100,0,0,100,0,0,100,100,0,0,100,0,0,0,100,
0,0,
100,0,100,100,75,100,75,100,100,100,100,75,100,100,0,100,100,75,
100,75,100,75,100,100,0,100,100,0,100,0,0,0,0,0,0,100,100,0,100};
cout<<" 1.Draw Cube \n 2.Rotation \n 3.Reflection \n";
cout<<" 4.Translation \n 5.Perspective Projection \n";
cout<<" Enter Your Choice : ";
cin>>n;
switch(n){
case 1: draw_cube(edge);
break;
case 2: rotate(edge);
break;
case 3: reflect(edge);
break;
case 4: translate(edge);
break;
case 5: perspect(edge);
break;
default: cout<<" Invalid Choice\n ";
}
getch();
}*/

