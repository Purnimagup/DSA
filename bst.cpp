#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node*  right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void lot (Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        }
    }

}

Node* createBST(Node* &root,int d)
{

    if(root == NULL)
    {
         root = new Node(d);
        return root;
    }
   // cout<<"enter the data in left->"<<root->data<<endl;
    if(d <root->data)
    {
     //cout<<"enetr the data in left->"<<root->data<<endl;
       root->left =  createBST(root->left,d);
    }
    else{
   //  cout<<"enter the data in right->"<<root->data<<endl;
      root->right =  createBST(root->right,d );
    }
    return root;


}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);


}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
  preorder(root->right);
}
Node* minval(Node* root)
{
    Node* temp = root;
    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root , int x)
{

    if(root == NULL)
    {

        return NULL;
    }

    if(root->data == x )
    {
     if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
    if( root->left != NULL && root->right == NULL)
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    if( root->left == NULL && root->right != NULL)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    if( root->left != NULL && root->right != NULL)
    {
    int mini = minval(root->right)->data;
       root->data = mini;
       root->right = deleteNode(root->right,mini);
       return root;
    }

    }
    else if(root->data>x)
    {
        root->left = deleteNode(root->left,x);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right,x);
        return root;
    }
}

void postorder(Node* root)
{

    if(root==NULL)
    {
        return ;
    }

    postorder(root->left);
   preorder(root->right);
     cout<<root->data<<" ";
}
void takeinput(Node* &root)
{

    int data;
    cin>>data;

    while(data != -1)
    {
        createBST(root,data);
        cin>>data;
    }
}


int main()
{
    Node* root = NULL;

    cout<<"enter the data in bst tree"<<endl;
    //createBST(root);
    takeinput(root);
    cout<<"print the BST"<<endl;
    lot(root);

    cout<<"print inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"print preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"print postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"after deletion"<<endl;
    deleteNode(root,34);
    lot(root);
    return 0;
}

