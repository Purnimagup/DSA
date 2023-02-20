#include<iostream>
using namespace std;

int main()
{
    cout<<"enter the size of matrix "<<endl;
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
   // transpose matrix
   /* for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            int temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //spiral order traversal
    int row_start=0;
    int row_end=n-1;
    int column_start=0;
    int column_end=m-1;
    while(row_start<=row_end&& column_start<=column_end)
    {
        for(int col=column_start;col<=column_end;col++)
        {
            cout<<a[row_start][col]<<" ";
        }
        row_start++;
        for(int row=column_end;row<=column_start;row++ )
        {
            cout<<a[row][column_end]<<" ";
        }
        column_end--;
        for(int col=column_end;col>=column_start;col--)
        {
            cout<<a[row_end][col]<<" ";
        }
        row_end--;
        for(int row =row_end;row>=row_start;row--)
        {
            cout<<a[row][column_start]<<" ";

        }
        column_start++;
    }
    return 0;
}
