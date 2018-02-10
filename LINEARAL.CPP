#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,n;
cout<<"Enter the dimension of a square matrix ";
cin>>n;
int *ar=new int[n*n];
for(i=0;i<n;i++)
{
cout<<"Enter elements in row:"<<i+1<<endl;
for(j=0;j<n;j++)
{
cout<<"Enter element in column "<<j+1<<" ";
cin>>ar[n*i+j];       //ar[i][j]=ar[sizeofarray*i+j]
}
}

for(i=0;i<n;i++)     //display
{
 for(j=0;j<n;j++)
 {
 cout<<ar[n*i+j]<<" ";
 }
cout<<endl;
}
cout<<"\nReduction to echelon form: ";
cout<<endl;
int k,t;
int LCM(int,int);
for(k=0;k<n;k++)
{
 for(i=1;i<n;i++)
 {

  if(i+k>=n)
  {
  break;
  }
  else
  {
  if(ar[n*k+k]==0)
  {
  int a;
  for(int x=0;x<n;x++)
  {
  a=ar[n*k+x];
  ar[n*k+x]=ar[n*(k+1)+x];
  ar[n*(k+1)+x]=a;
  }
  }
  t=ar[n*(i+k)+k];
   for(j=0;j<n;j++)
   {
   if(t!=0)
   {
   ar[n*(i+k)+j+k]=(ar[n*(i+k)+j+k]*(LCM(ar[n*k+k],t)/t)-(LCM(ar[n*k+k],t)/ar[n*k+k])*ar[n*k+j+k]);
   }
   else break;
   }
  }
 }
}
for(i=0;i<n;i++)     //display
{
 for(j=0;j<n;j++)
 {
 cout<<ar[n*i+j]<<" ";
 }
cout<<endl;
}


delete ar;
getch();
}
int LCM(int a,int b)
{
if(a<0)
{
a=-a;
}
if(b<0)
{
b=-b;
}
if(a==0||b==0)
{
cout<<"\nFAIL";
return 0;
}
int q,w,l,m;
q=(a<b?a:b);
w=(a>b?a:b);
int r=w;
for(l=1,m=2; ;l++)
{
if(l*q==r)
{
return r;
}
else if(l*q>r)
{
r=w*m;
m++;
}
}
}
