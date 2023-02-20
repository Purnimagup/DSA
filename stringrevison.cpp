#include<iostream>
using namespace std;

char tolower(char ch)
{
    if(ch>='a' && ch<= 'z')
    {
        return ch;
    }
    else
    {
     char temp = ch -'A'+'a';
    return temp;
    }
}
string toLower(char ch[],int n){
   // char c[n];
for(int i=0 ;i<n;i++)
{
    ch[i] = toupper(ch[i]);
}
return ch ;
}
char toupper(char ch)
{
    if(ch>='A' && ch<= 'Z')
    {
        return ch;
    }
    else
    {
     char temp = ch -'a'+'A';
    return temp;
    }
}
void reverses(char ch[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
    int temp  = ch[s];
        ch[s] = ch[e];
        ch[e] = temp;
        s++;
        e--;
    }
}

int main()
{
    char ch[10];

    cout<<"enter your name"<<endl;
    cin>>ch;
    //ch[2] ='\0';

    cout<<"your name is "<<endl;
    cout<<ch;
    int len =0;
    cout<<endl;
    for(int i=0;ch[i]!='\0';i++)
    {
        len++;
    }
    cout<<"length of string is "<<len<<endl;
   // reverses(ch,len);
    cout<<ch<<endl;

    cout<<"character is "<<tolower('P')<<endl;
  cout<<"character is "<<toupper('p')<<endl;;
   cout<<toLower(ch,len);


   string str = "purnima gupta";
   cout<<str.length()<<endl;
   cout<<str<<endl;

    return 0;
}
