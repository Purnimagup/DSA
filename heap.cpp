#include<iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int a[100];
    int siz ;

    heap()
    {
        a[0]=-1;
        siz = 0;
    }
    void insertmaxheap(int data)
    {
        siz = siz +1;
        int index = siz;
        a[index] = data;

        while(1<index)
        {
            int parent = index/2;
            if(a[parent]<a[index])
               {
                   swap(a[parent],a[index]);
                   index = parent;
               }
            else
            {
                return;
            }
        }
    }
    void insertminheap(int data)
    {
        siz = siz +1;
        int index = siz;
        a[index] = data;

        while(1<index)
        {
            int parent = index/2;
            if(a[parent]>a[index])
               {
                   swap(a[parent],a[index]);
                   index = parent;
               }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for(int i=1;i<= siz;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void deleteheap()
    {
        if(siz==0)
        {
            cout<<"nothing for deletion"<<endl;
            return;
        }

        a[1]=a[siz];
        siz--;

        int i=1;
        while(i<siz)
        {
            int leftchild = 2*i;
            int rightchild = 2*i+1;
            if(leftchild<siz && a[leftchild]>a[i])
            {
                swap(a[i],a[leftchild]);
                i = leftchild;
            }
            else if(rightchild<siz && a[rightchild]>a[i])
            {
                swap(a[i],a[rightchild]);
                i = rightchild;
            }
             else
             {
                 return;
             }
        }
    }
};

  void heapify(int a[],int n,int i)
    {
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left<=n && a[largest]<a[left])
        {
            largest = left;
        }
        if(right<=n && a[largest]<a[right])
        {
            largest = right;
        }
        if(largest!=i)
        {
            swap(a[largest],a[i]);
            heapify(a,n,largest);
        }
    }

    void heapsort(int arr[],int n)
    {

        while(1<n)
        {
            swap(arr[n],arr[1]);
            n--;
            heapify(arr,n,1);
        }
    }

int main()
{
    heap h;
    h.insertmaxheap(90);
    h.insertmaxheap(9);
    h.insertmaxheap(60);
    h.insertmaxheap(79);
    h.insertmaxheap(67);
    cout<<"max  heap"<<endl;
    h.print();
    cout<<endl;
   /*  h.insertminheap(90);
    h.insertminheap(9);
    h.insertminheap(60);
    h.insertminheap(79);
    h.insertminheap(67);
    cout<<"min   heap"<<endl;
    h.print();
    cout<<endl;*/
    h.deleteheap();
    cout<<"max  heap"<<endl;
    h.print();
    cout<<endl;
    int arr[6] ={-1,54 ,53 ,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--)
    {
       heapify(arr,n,i);
    }
    cout<<"print the heap"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
    cout<<"print the sorted heap"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    priority_queue<int> maxi;
    maxi.push(8);
    maxi.push(7);
    maxi.push(5);
    maxi.push(4);
     cout<<"element in maxi"<<endl;
     cout<<maxi.top()<<" ";
       maxi.pop();
    while(maxi.empty())
    {
       cout<<maxi.top()<<" ";
       maxi.pop();
    }

     priority_queue<int,vector<int>,greater<int>> mini;
    mini.push(8);
    mini.push(7);
    mini.push(5);
    mini.push(4);
     cout<<"element in maxi"<<endl;
      cout<<mini.top()<<endl;
       mini.pop();
    while(mini.empty())
    {
       cout<<mini.top()<<endl;
       mini.pop();
    }



    return 0;
}

