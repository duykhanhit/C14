#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
void nhapchuoi(char s[225])
{
    cout<<"\nNhap chuoi :";
    fflush(stdin);
    gets(s);
    cout<<"\nChuoi ban vua nhap:"<<s<<endl;
}

void dem(char s[225])
{
    int demthuong=0, demhoa=0, demso=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]>='a' && s[i]<='z')
            demthuong++;
        if(s[i]>='0' && s[i]<='9')
            demso++;
        if(s[i]>='A' && s[i]<='Z')
            demhoa++;
    }
    cout<<"\nSo chu cai in thuong trong chuoi la :"<<demthuong<<endl;
    cout<<"\nSo chu so trong chuoi la :"<<demso<<endl;
    cout<<"\nSo chu cai in hoa trong chuoi la :"<<demhoa<<endl;
}
void hoanvi(char &x, char &y)
{
    int temp=x;
    x=y;
    y=temp;
}
void STRREV(char s[225])  //dao nguoc chuoi
{
    for(int i=0; i<=(strlen(s)/2)-1; i++)
    {
        hoanvi(s[i], s[strlen(s)-i-1]);//doi vi tri cap ki tu cho nhau
    }
}
void chen(char s[], char c[], int a)
{
    int m=strlen(c);
    int n=strlen(s);
    for(int i=n-1; i>a; i--)
    {
        s[i+m-1]=s[i];
    }
    for(int i=0; i<m; i++)
        s[i+a]=c[i];
    s[m+n-1]='\0';
}
void thaythe(char s[225])
{
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]=='1')
            chen(s,"mot",i);
        else if(s[i]=='2')
            chen(s,"hai",i);
        else if(s[i]=='3')
            chen(s,"ba",i);
        else if(s[i]=='4')
            chen(s,"bon",i);
        else if(s[i]=='5')
            chen(s,"nam",i);
        else if(s[i]=='6')
            chen(s,"sau",i);
        else if(s[i]=='7')
            chen(s,"bay",i);
        else if(s[i]=='8')
            chen(s,"tam",i);
        else if(s[i]=='9')
            chen(s,"chin",i);
        else if(s[i]=='0')
            chen(s,"khong",i);
    }
}
int main()
{
    char s[225];
    nhapchuoi(s);
    cout<<"\nTHUC HIEN DEM";
    dem(s);
    cout<<"\n========================================"<<endl;
    STRREV(s);
    cout<<"\nChuoi sau khi dao nguoc la :"<<s;
    STRREV(s);
    thaythe(s);
    cout<<"\nChuoi sau khi thay the cac chu so la: "<<s<<endl;
    return 0;
}

