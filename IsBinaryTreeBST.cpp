#include <iostream>
int a[15]={0};
static int i=0;
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    
    public:
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void inordertraversal(Node *root)
{
    int val;
    if(root == NULL)
    return;
    else{
        inordertraversal(root->left);
        cout<<root->data<<" ";
        a[i]=root->data;
        i++;
        inordertraversal(root->right);
    }
}

bool arraysort(int a[], int n)
{
    for(int j=0;j<n;j++)
    {
        
        if((a[j]!=0) && (a[j+1]!=0) &&(a[j]>a[j+1])){
        return false;
        break;
        }
    }
    return true;

}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(12);
    root->left->left=new Node(3);
    root->left->right=new Node(6);
    root->right->left=new Node(11);
    root->right->right=new Node(15);
    inordertraversal(root);
    bool checkbst=false;
    int n = sizeof(a) / sizeof(a[0]);
    checkbst=arraysort(a,n);
    
    if(checkbst == false)
    cout<<"not a BST"<<endl;
    else
    cout<<"BST"<<endl;
    
}
