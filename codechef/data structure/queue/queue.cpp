#include<iostream>

using namespace std;

struct q{
    int val;
    q *next=NULL;
}*front=NULL, *rear=NULL;

void push(int n)
{
    q *cur=new q;
    cur->val=n;
    if(rear==NULL) rear=cur;
    else
    {
        rear->next=cur;
        rear=cur;
    }
    if(front==NULL) front=cur;

    return;

}

void pop()
{
    if(front==NULL)
    {
        cout<<"Can't pop"<<endl;
        return;
    }
    front=front->next;
    q *x;
    x=front;
    delete x;
}

void travers()
{
    q *crnt;
    crnt=front;
    while(crnt!=NULL)
    {
        cout<<crnt->val;
        crnt=crnt->next;
    }
    cout<<endl;
    return;
}

int main()
{
    int n=0;
    while(n--)
    {
        push(n);
    }
    travers();
    char x;
    while(cin>>x)
    {
        if(x!='p') break;

        pop();
        travers();
    }
    travers();
    return 0;
}
