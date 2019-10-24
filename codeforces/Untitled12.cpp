#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *left, *right;
    int val;
};

struct BinarySearchTree
{
    node *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    void insertInBST(int val);
    void deleteFromBST(int val);
    node* findInBST(int val);
    void printTheTree(node* cur);
};

void BinarySearchTree::insertInBST(int val)
{
    node *prev=NULL,*temp,*cur = new node;
    cur->left = cur->right = NULL;
    cur->val = val;
    if(root == NULL)
    {
        root = cur;
        return;
    }
    temp = root;
    while(temp!=NULL)
    {
        prev = temp;
        if(val < temp->val)
            temp = temp->left;
        else if(val > temp->val)
            temp = temp->right;
        else{
            cout << "The value "<< val << " already exists!\n";
            delete cur;
            return;
        }
    }
    if(val < prev->val)
        prev->left = cur;
    else
        prev->right =  cur;
}

void BinarySearchTree::deleteFromBST(int val)
{
    node *prev = NULL, *cur = root, *temp;
    while(cur != NULL)
    {
        if(cur->val == val)
            break;
        prev = cur;
        if(val < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if(cur==NULL)
    {
        cout << "The value "<< val << " does not exist!\n";
        return;
    }
    /// Case 1: No child
    if(cur->left == NULL && cur->right == NULL)
    {
        if(prev->left == cur)
            prev->left = NULL;
        else
            prev->right = NULL;
        delete cur;
        return;
    }

    /// Case 2: One child
    if(cur->left == NULL || cur->right == NULL)
    {
        if(cur->left == NULL)
            temp = cur->right;
        else
            temp = cur->left;
        if(prev->left == cur)
            prev->left = temp;
        else
            prev->right = temp;
        delete cur;
        return;
    }

    /// Case 3: Two children
    node *inOrderSuccessor=cur->right;
    while(inOrderSuccessor->left!=NULL)
        inOrderSuccessor = inOrderSuccessor->left;
    int toDelete = inOrderSuccessor->val;
    deleteFromBST(toDelete);
    cur->val = toDelete;
}

node* BinarySearchTree::findInBST(int val)
{
    node *temp, *cur = root;
    if(root==NULL)
        return cur;
    temp = root;
    while(temp!=NULL)
    {
        if(temp->val == val)
            return temp;
        if(val < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

void BinarySearchTree::printTheTree(node *cur){
    if(cur==NULL) return;
    cout << "Node:" << cur->val <<"\n";
    cout << "Left child : ";
     if(cur->left==NULL)
        cout << "No child";
    else
        cout << cur->left->val;
    cout << "\n";

    cout << "Right child : ";
     if(cur->right==NULL)
        cout << "No child";
    else
        cout << cur->right->val;
    cout << "\n";

    if(cur->left!=NULL) printTheTree(cur->left);
    if(cur->right!=NULL) printTheTree(cur->right);
}

int main()
{
    int ar[]={10 , 6, 2, 7, 1, 9, 24, 1,5, 16};
    sort(ar, ar+9);
    for(int i=0;i<10;i++) cout<<ar[i]<<endl;

        return 0;
}
