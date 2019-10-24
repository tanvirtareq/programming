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
    void printTheSubTree(node* cur);
    void printTheBST();
};

void BinarySearchTree::insertInBST(int val)
{
    /**
     * Insert the provided value val in BST.
     * If the value already exists, then print
     * "The value x already exists!" in a line
     * without quotes and of course x would be
     * replace by the corresponding value.
     */

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
    /**
     * Delete the provided value val from BST.
     * If the value does not exists, then print
     * "The value x does not exist!" in a line
     * without quotes and of course x would be
     * replace by the corresponding value.
     */

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
    /**
     * Find the provided value val in BST.
     * If the value does not exists, then
     * just return NULL. Otherwise return
     * the pointer of that node.
     */

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

void BinarySearchTree::printTheSubTree(node *cur){
    if(cur==NULL){
        cout << "SubTree does not exists!\n";
        return;
    }
    cout << "Start - Current Tree Information\n";
    cout << "Root of the SubTree = "<cur->val <<"\n";
    printTheTree(cur);
    cout << "End - Current Tree Information\n";
}

void BinarySearchTree::printTheBST(){
    if(root==NULL){
        cout << "BST does not exists!\n";
        return;
    }
    cout << "Start - Current Tree Information\n";
    cout << "Root of the Tree = "<val <<"\n";
    printTheTree(root);
    cout << "End - Current Tree Information\n";
}

int main()
{
//    freopen("inp1.txt","r+",stdin);
//    freopen("out1.txt","w+",stdout);
    BinarySearchTree *bst = new BinarySearchTree;
    node *cur;
    int op,x;
    /**
     * 1 x - insert x in BST
     * 2 x - delete x from BST
     * 3 x - Find x in BST
     * 4 - Print the whole BST
     */
    while(~scanf("%d",&op))
    {
        switch (op)
        {
        case 1:
            scanf("%d",&x);
            bst->insertInBST(x);
            break;
        case 2:
            scanf("%d",&x);
            bst->deleteFromBST(x);
            break;
        case 3:
            scanf("%d",&x);
            cur = bst->findInBST(x);
            bst->printTheSubTree(cur);
            break;
        case 4:
            bst->printTheBST();
            break;
        default:
            break;
        }

    }
    return 0;
}
