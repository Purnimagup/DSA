#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
         this->right=NULL;
    }

};
void reverselot(node* root)
{
    queue<node*> q;
    stack<node*> s;
    q.push(root);
   // q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        s.push(temp);
       if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
             if(temp->right)
            {
                q.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
            }

        }
    }
      while(!s.empty())
      {
          node* temp = s.top();
          cout<<temp->data<<" ";
          s.pop();
      }
}
void lot(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
void inorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(node* &root)
{
    if(root == NULL)
        return 0;

    int left  = height(root->left);
    int right = height(root->right);
    int mn = max(left,right)+1;
    return mn;
}

int diameter(node* root)
{
    if(root == NULL)
    {
        return 0 ;
    }
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = height(root->left)+height(root->right)+1;
    return max(d1,(d2,d3));
}

void mirror(node* &root)
{
    if(root == NULL)
    {
        return ;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left)
        {
            mirror(root->left);
        }
        if(root->right)
        {
            mirror(root->right);
        }
    }

node* buildtree(node* &root)
{
    cout<<"enter the data in root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"enter the data for  left->"<<data<<endl;
    node* left = buildtree(root->left);
    cout<<"enter the data in right-> "<<data<<endl;
    node* right = buildtree(root->right);
    return root;
}


int main()
{
    node* root = buildtree(root) ;
    lot(root);
    cout<<"reverse lot" <<endl;
    reverselot(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Height of b-tree "<<height(root)<<endl;
    cout<<"Diameter of b-tree "<<diameter(root)<<endl;
    mirror(root);
    lot(root);

    return 0;
}
