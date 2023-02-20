#include<iostream>
//#include<queue>
using namespace std;

class queue
{
public:
    int *arr;
    int siz;
    int fron_t;
    int rea_r;

};

int main()
{
    queue<int> q;

    q.push(8);
    q.push(80);
    cout<<"front of queue "<<q.front()<<endl;
    cout<<"size of queue = "<<q.size()<<endl;
    q.pop();
    cout<<"size of queue = "<<q.size()<<endl;
     if(q.empty())
     {
        cout<<"queue is empty"<<endl;
     }
     else{
        cout<<"queue is  not empty"<<endl;
     }


    return 0;
}
