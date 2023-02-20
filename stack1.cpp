#include<iostream>
#include<stack>
using namespace std;

class stack
{
public:
    int siz;
    int* arr;
    int top;

    stack(int siz)
    {
        this->siz = siz;
        arr = new int(siz);
        top = -1;
    }

    void push(int d)
    {
        if(siz - top > 1)
        {
            top++;
            arr[top] = d;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop()
    {
        if(top>= 0)
        {
            cout<<"stack underflow"<<endl;
        }
        else{
            top--;
        }
    }


};

int main()
{


    return 0;
}
