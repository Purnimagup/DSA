#include<iostream>
using namespace std;

void sort012(int a[],int n)
{
    int c0 =0,c1=0,c2=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            c0++;
        }
        else if(a[i]==1)
        {
            c1++;
        }
        else{
            c2++;
        }
    }
    int k=0;
    while(k<n)
    {
    for(int i=0;i<c0;i++)
    {
        a[k++] = 0;
    }

     for(int i=0;i<c1;i++)
    {
        a[k++] = 1;
    }
     for(int i=0;i<c2;i++)
    {
        a[k++] = 2;
    }
    }
    //return a;
}
void movenegative(int a[],int n)
{
    int i =-1;
    int j;
    while(j<n)
    {
        if(a[i]<0)
        {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i]  = temp;
        }
        j++;
    }
}

void reversearr(int arr[],int n)
{
    int s= 0;
    int e = n-1;
    while(s<e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e]  = temp;
        s++;
        e--;
    }
}

void maxandmin(int arr[],int n)
{
    int mx = -11;
    int mn = 1e5;
    for(int i=0;i<n;i++)
    {
        mn = min(arr[i],mn);
        mx = max(arr[i],mx);
    }
   cout<<mx<<" and "<<mn<<endl;
}

int main()
{

    int n ;
    cout<<"Enter the size and element in array"<<endl;
    cin>>n;
    int arr[n] ;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //reversearr(arr,n);
    cout<<"max and min element in array  is   ";
    maxandmin(arr,n);
   // sort012(arr,n);
    movenegative(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
