#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void getDes(char far *d)
{
char far *temp=d;
d=d+2;
*d='|';
d+=4;
*d='|';
d=temp+160;
temp=d;
*d='-';
d+=4;
*d='-';
d+=4;
*d='-';
d=temp+160;
temp=d;
d=d+2;
*d='|';
d+=4;
*d='|';
d=temp+160;
temp=d;
*d='-';
d+=4;
*d='-';
d+=4;
*d='-';
d=temp+160;
temp=d;

d=d+2;
*d='|';
d+=4;
*d='|';

}

void insert(char far *val,int i,int j,char r)
{
char far *t=val+320*i+4*j;
*t=r;
}

int check(int i,int j,int arr[3][3])
{
int f=0;
i--;
j--;

if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][1]!=0)
f=1;
if(arr[0][j]==arr[1][j] && arr[1][j]==arr[2][j] && arr[1][j]!=0)
f=1;

if(i==j)
{
	if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[1][1]!=0)
	f=1;
}
if(i+j==2)
{
	if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[1][1]!=0)
	f=1;
}
return f;

}

int verify(int i,int j,int arr[3][3])
{
int f=1;
i--;
j--;
if(i>2 || j>2)
f=0;
if(i<0 || j<0)
f=0;
if(arr[i][j]!=0)
f=0;

return f;
}

int main()
{
char far *vid=0XB8000000;
char far *val=vid+320;
int i,j,p=0,k,l,count=0;
int f=0;
int arr[3][3]={0};
int validate;

while(f!=1 && count<9)
{
clrscr();


getDes(vid+320);

for(k=0;k<3;k++)
{
for(l=0;l<3;l++)
{
if(arr[l][k]==1)
insert(val,l,k,'X');
if(arr[l][k]==2)
insert(val,l,k,'O');
}
}

scanf("%d%d",&i,&j);
validate=verify(i,j,arr);

if(validate==0)
continue;

count++;

if(p==0)
{
arr[i-1][j-1]=1;
p=(p+1)%2;
}
else
{
arr[i-1][j-1]=2;
p=(p+1)%2;
}
f=check(i,j,arr);

}
clrscr();
getDes(vid+320);

for(k=0;k<3;k++)
{
for(l=0;l<3;l++)
{
if(arr[l][k]==1)
insert(val,l,k,'X');
if(arr[l][k]==2)
insert(val,l,k,'O');
}
}
if(count==9 && f==0)
printf("Match Draw");
else if(p==1)
printf("Player 1 Wins");
else if(p==0)
printf("Player 2 wins");



getch();

return 0;
}