#include<iostream>

using namespace std;


struct node
{
    node *right, *left;
    int val;
};

class BinarySearchTree
{
    public:
    node *root;
    BinarySearchTree()
    {
        root=NULL;
    }

    void insertBst(int val);
    void DeleteFromBst(int val);
    node *FindInBst(int Val);

    void printTheTree(node *cur);



};

class MyClass1
{
public:
    BinarySearchTree t;

    node *insertBst(int val, node *root)
    {
        //cout<<"not "<<endl;
        if(root==NULL)
        {
           // cout<<"null"<<endl;
            root=new node;
            root->val=val;
            root->left=NULL;
            root->right=NULL;
            return root;
        }

        //cout<<"not null"<<endl;
        if(root->val>val)
        {
            root->left=insertBst(val, root->left);
        }
        if(root->val<val)
            root->right=insertBst(val, root->right);

        if(root->val==val)
            cout<<val<<" already exist"<<endl;

        return root;
    }

    node *FindInBst(int val, node *root)
    {
        if(root==NULL) return NULL;

        if(val==root->val) return root;

        if(val<root->val)
            return FindInBst(val, root->left);

        if(val>root->val)
            return FindInBst(val, root->right);

        return NULL;


    }

    node *FindAncestor(int val, node *root)
    {
        if(root==NULL) return NULL;

        if(val==root->left->val or val==root->right->val) return root;

        if(val<root->val)
            return FindInBst(val, root->left);

        if(val>root->val)
            return FindInBst(val, root->right);

        return NULL;
    }

};

void BinarySearchTree::insertBst(int val)
{
    if(root==NULL)
    {
        root=new node;
        //cout<<val<<endl;
        root->val=val;
//        cout<<"val inserted"<<endl;
        root->left=NULL;
        root->right=NULL;

//        cout<<"left and right are null"<<endl;
        return;
    }

    class MyClass
{
public:


    node *insertBst(int val, node *root)
    {
        //cout<<"not in"<<endl;
        if(root==NULL)
        {
            root=new node;
            root->val=val;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        if(root->val>val)
        {
            node *x;
            root->left=insertBst(val, root->left);
        }
        if(root->val<val)
        {
            root->right=insertBst(val, root->right);
        }

        if(root->val==val)
            cout<<val<<" already exist"<<endl;

        return root;
    }

};
    MyClass1 x;
    x.insertBst(val, root);
    return;

}

void BinarySearchTree::DeleteFromBst(int val)
{
    if(val==root->val)
    {

    }
    MyClass1 x;
    node *an=x.FindAncestor(val);
    if(an==NULL)
    {
        cout<<"no such value"<<endl;
        return;
    }

    node *cur;
    if(an->left->val==val)
    {
        cur=an->left;
    }

    if(an->right->val==val)
    {
        cur=an->right;
    }



}

node *BinarySearchTree::FindInBst(int val)
{
    MyClass1 m;
    node *cur=m.FindInBst(val, root);

    if(cur==NULL)
    {
        cout<<"no val find"<<endl<<endl;
    }

    cout<<"node = "<<cur->val<<endl;

    cout<<"left child = ";
    (cur->left==NULL)?cout<< "No child"<<endl :cout<<cur->left->val<<endl;
    cout<<"right child = ";
    (cur->right==NULL)?cout<< "No child"<<endl:cout<<cur->right->val<<endl;
    cout<<endl<<endl;

}

void BinarySearchTree::printTheTree(node *cur)
{
    if(cur==NULL) return;
    cout<<"node = "<<cur->val<<endl;

    cout<<"left child = ";
    (cur->left==NULL)?cout<< "No child"<<endl :cout<<cur->left->val<<endl;
    cout<<"right child = ";
    (cur->right==NULL)?cout<< "No child"<<endl:cout<<cur->right->val<<endl;
    cout<<endl<<endl;
    printTheTree(cur->left);

    printTheTree(cur->right);
}

int main()
{
    BinarySearchTree T;

    int a;

    while(cin>>a)
    {
        if(a==1)
        {
            int x;
            cin>>x;
            T.insertBst(x);
        }

        if(a==2)
        {
            int x;
            cin>>x;
            T.DeleteFromBst(x);
        }

        if(a==3)
        {
            int x;
            cin>>x;
            node *f=T.FindInBst(x);
        }

        if(a==4)
        {
            T.printTheTree(T.root);
        }

    }



    return 0;
}
