#include<iostream>
using namespace std;

struct node
{
    int val;
    node *next;
}*front,*rear;

void enqueue(int x)
{
    node *current=new node;
    current->val=x;
    current->next=NULL;
    if(front==rear&&front==NULL)
    {
        front=rear=current;
        cout<<x<<" enqueued successful!\n";
        return;
    }
    rear->next=current;
    rear=rear->next;
    cout<<x<<" enqueued successful!\n";
}

int dequeue()
{
    if(front==rear&&front==NULL)
    {
        cout<<"Underflow!"<<endl;
        return -1;
    }
    node *temp=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    int ret=temp->val;
    delete temp;
    cout<<ret<<" dequeued successful!\n";
    return ret;
}

int main()
{
    front=rear=NULL;
    enqueue(3);
    enqueue(6);
    enqueue(1);
    dequeue();
    dequeue();
    dequeue();
    enqueue(19);
    enqueue(4);
    enqueue(46);
    enqueue(50);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
