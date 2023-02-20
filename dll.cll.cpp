#include<iostream>
using namespace std;

class dnode
{
public:
    int data;
    dnode* left;
    dnode* right ;

    dnode(int d)
    {
     this->data = d;
     this->left = NULL;
     this->right = NULL;
    }
};
dnode* reverseDLL(dnode * head)
{
    if(head==NULL || head->right==NULL)
    {
        return head;
    }
    dnode* curr = head;
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    head = curr;
    curr->right = curr->left;
    curr->left = NULL;
    curr = curr->right;
    while(curr->left!=NULL)
    {
        dnode* temp = curr->right;
        curr->right = curr->left;
        curr->left = temp;
        curr = curr->right;
    }
    curr->left = curr->right;
    curr->right = NULL;

    return head;
}

dnode* reversell(dnode* &head)
{
    dnode* curr = head;

    while(curr->right !=NULL)
    {
        curr = curr->right;
    }
    head = curr;
    curr->right = curr->left;
    curr->left = NULL;
    curr = curr->right;
    while(curr->left != NULL)
    {
        dnode* temp = curr->right;
        curr->right = curr->left;
        curr->left = temp;
        curr = curr->right;
    }
    curr->left = curr->right;
    curr->right = NULL;

    return head;
}

void print(dnode* &head)
{
    dnode* temp = head;
    cout<<"NULL->";
    while(temp != NULL)
    {
        cout<<temp->data<<"<->";
        temp =temp->right;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    dnode* node1 = new dnode(9);
    dnode* head = node1;
    head->right = new dnode(4);
    head->right->right = new dnode(8);
    head->right->right->right = new dnode(78);
    head->right->right->right->right = new dnode(2);
    head->right->right->right->right->right = new dnode(68);
//head->left = new dnode(7);
    //head = head->left;
    print(head);
    reverseDLL(head);
    print(head);

    return 0;
}
