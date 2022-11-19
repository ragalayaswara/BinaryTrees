#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

Node* newnode(int data)
{
    Node *node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int height(Node *n)
{
    if(n==NULL)
    return 0;
    else
    {
        int lh=height(n->left);
        int rh=height(n->right);
        
        if(lh>rh)
        return (lh+1);
        else
        return (rh+1);
    }
}

void printcurrentlevel(Node *n, int level )
{
    if(n==NULL)
        return;
    else if(level==1)
        cout<<n->data<<" ";
    else
    {
        printcurrentlevel(n->left,level-1);
        printcurrentlevel(n->right,level-1);
    }
}

void printtree(Node *n)
{
    cout<<"Printing level order traversal"<<endl;
    int h=height(n);
    int i;
    for(i=1;i<=h;i++)
    {
        printcurrentlevel(n,i);
    }
    cout<<endl;
}

void inordertraversal(Node *n)
{
    if (n==NULL)
    return;
    else
    {
        inordertraversal(n->left);
        cout<<n->data<<" ";
        inordertraversal(n->right);
    }
}

void preordertraversal(Node *n)
{
    if (n==NULL)
    return;
    else
    {
        cout<<n->data<<" ";
        preordertraversal(n->left);
        preordertraversal(n->right);
    }
}

void postordertraversal(Node *n)
{
    if (n==NULL)
    return;
    else
    {
        postordertraversal(n->left);
        postordertraversal(n->right);
        cout<<n->data<<" ";
    }
}

int main()
{
    Node *root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
    printtree(root);
    cout<<"Printing inorder traversal"<<endl;
    inordertraversal(root);
    cout<<endl<<"Printing preorder traversal"<<endl;
    preordertraversal(root);
    cout<<endl<<"Printing postorder traversal"<<endl;
    postordertraversal(root);
    
}
