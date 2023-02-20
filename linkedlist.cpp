#include<iostream>
#include<map>
#include<set>
using namespace std;


class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if(this->next==NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout<<"memory is free with data i.e, "<<value<<endl;
    }
};
void insertathead(node* &head,int d)
{
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertattail(node* &tail,int d)
{
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertatposition(node* &head,node* &tail,int position ,int data)
{
    if(position==1)
    {
        insertathead(head,data);
    }
    node* temp = head;

    int cnt=0;
    while(cnt<position-1)
    {
        temp= temp->next;
        cnt++;
    }
    node* t = new node(data);
    if(temp->next == NULL)
    {
      insertattail(tail,data);
      return;
    }
    else{
    t->next = temp->next;
    temp->next = t;
    }
}
void deletenode(node* &head,node* &tail,int position)
{
    node* temp = head;
    if(position==1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* prev = NULL;
        node* curr = head;
        int cnt =0;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
        if(prev->next == NULL)
        {
            tail = prev;
        }
    }
}
node* reversell(node* &head)
{
    node* curr = head;
    node* prev = NULL;
    node* Forward = NULL;
    while(curr!= NULL)
    {
        Forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forward;
    }
    head = prev;
    return head;
}

int  fcd(node* &head)
{
    node* slow = head;
    node* fast = head;
    while(fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }
       if(slow == fast && slow!= head)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
            break;
        }
        else if(slow==fast)
        {
            node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        return slow->data;
    }

}
 void removeLoop(node* &head)
    {
        node* slow=head,*fast=head;
        node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast && slow!=head) {
                slow=head;
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
                fast->next=NULL;
                break;
            }

        else if(slow==fast){
           /* while(slow!=fast)
            {
                fast=fast->next;
            }
            fast->next=NULL;*/
                node* temp=head;
                while(temp->next!=head)
                {
                temp=temp->next;
                }
                temp->next=NULL;
            }

        }

    }
bool detectloop(node* &head)
{
    node* temp = head;
    map<node*,int> m;
    while(temp!= NULL)
    {
        if(m[temp]==1)
        {
            return 1;
        }
        m[temp] = 1;
        temp = temp->next;
    }
    return 0;
}
node* sortll(node* &head)
{
    node* curr = head;
    node* prev = curr;
    curr = curr->next;
    while(curr!= NULL)
    {
        if(prev->data >curr->data)
        {
            node* temp = prev;
            prev =curr;
            curr = temp;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
void removeduplicate(node* &head)
{
     map<int,bool> m;
     node* curr = head;
    node* prev = head;
    m[curr->data] =1;
    curr = curr->next;
    //node* curr = head;

    while(curr != NULL)
    {
        if(m[curr->data]==1)
        {
            prev->next = curr->next;
          //  delete curr;
        }
        else{
        m[curr->data] = 1;
        prev = prev->next;
    }
     curr = curr->next;
    }
    /*node* curr = head;
    set<node*> s;
    while(curr!=NULL)
    {
        s.insert(curr);
        curr = curr->next;
    }
    for(auto i:s)
    {
        cout<<i->data<<endl;
    }*/
}

node* reversegrp(node* &head,int k)
{
    node* curr = head;
    node* prev = NULL;
    node* Forward =NULL;
    int cnt=0;
    while(cnt<k &&curr!=NULL)
    {
        Forward= curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forward;
        cnt++;
    }
    if(Forward != NULL)
    {
        head->next = reversegrp(Forward,k);
    }
    head = prev;
    return head;
}
void addno(node* head)
{
    head = reversell(head);
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data ==9)
        {
            temp->data =0
        }
        else if(temp->data ==9 && temp ->next == NULL)
        {
            tem
        }
    }
}


void print(node* &head )
{
    node* temp = head;
    while(temp!=NULL)
    {
     cout<<temp->data<<"->";
     temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* node1 = new node(2);
    node* head = node1;
    node* tail = node1;
    head->next = new node(2);
    tail = head->next;
    cout<<"head :" <<head->data<<endl;
    cout<<"TAil :"<<tail->data<<endl;
    print(head);
    insertathead(head,89);
    insertattail(tail,90);
    insertatposition(head,tail,1,45);
    insertatposition(head,tail,5,78);
    insertatposition(head,tail,3,34);
    cout<<"head :" <<head->data<<endl;
    cout<<"TAil :"<<tail->data<<endl;
    print(head);

   /* deletenode(head,tail,3);
    deletenode(head,tail,6);
    deletenode(head,tail,1);
    cout<<"head :" <<head->data<<endl;
    cout<<"TAil :"<<tail->data<<endl;
    print(head);
    reversell(head);
    print(head);
    reversegrp(head,3);
    print(head);
    reversegrp(head,2);
    print(head);
    tail->next = head;
    cout<<detectloop(head)<<endl;
    cout<<fcd(head)<<endl;
     cout<<detectloop(head)<<endl;
     removeLoop(head);
      cout<<detectloop(head)<<endl;*/
   // sortll(head);
   removeduplicate(head);
    print(head);

    return 0;
}
