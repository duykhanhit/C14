#include<iostream>
#include<string.h>
using namespace std;

void nhap(char a[], int &n)
{
	cout<<" Nhap chuoi ki tu tuy y:\n "; fflush(stdin);
	gets(a);
	n=strlen(a);
}


void daucuoi(char a[], int &n)
{
	int t=0,k=n;
	while(a[t]==' ')
	{
		for(int i=t;i<n;i++) a[i]=a[i+1];
		n--;
		a[n+1]='\0';
	}
	while(a[k]==' ')
	{
		for(int i=k;i>0;i--) a[i]=a[i-1];
		n--;
		a[n+1]='\0';
	}
}


void motcach(char a[], int &n)
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==' '&&a[i+1]==' ')
		{
			for(int j=i;j<n;j++) a[j]=a[j+1];
		    n--;
		    i--;
		}
		a[n+1]='\0';
	}
}

void trcsau(char a[], int &n)
{
	for(int i=0;i<n;i++)
	if(a[i]=='.'||a[i]==',')
	{
		if(a[i-1]==' ') 
		{
			for(int j=i-1;j<n;j++) a[j]=a[j+1];
			n--;
			i--;
		}
		if(a[i+1]!=' ')
		{
			n++;
			for(int j=n-1;j>i+1;j--) a[j]=a[j-1];
			a[i+1]=' ';
		}
		if(a[i+1]==' '&&a[i+2]==' ')
		{
			for(int j=i+1;j<n;j++) a[j]=a[j+1];
			n--;
			i--;
		}
	}
}


void viethoa(char a[], int n)
{
	strlwr(a);
	a[0]-=32;
	for(int i=0;i<n;i++)
	if(a[i]=='.'&&a[i+1]==' ') a[i+2]-=32;
}


int main ()
{
	char a[256];
	int n;
	nhap(a,n);
	daucuoi(a,n);
	motcach(a,n);
	trcsau(a,n);
	viethoa(a,n);
	cout<<"\n Chuoi sau khi chuan hoa:\n ";
	puts(a);
}
