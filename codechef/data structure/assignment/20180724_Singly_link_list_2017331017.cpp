/**
* Implement all the functions under Singly Linked List as
* per instruction.
*/
#include <iostream>
using namespace std;

struct node{
    int val;
    node *next=NULL;
};

struct SinglyLinkedList{
    node *head, *tail;
    /**
    * Implement the constructor to initialize head and tail
    */
    SinglyLinkedList();
//    ~SinglyLinkedList();
    /**
    * A value would be provided, you have to insert it as the
    * last element.
    */
    void insertVal(int val);
    /**
    * A value would be provided, you have to insert it as the
    * second last element, that means the inserted value would
    * be the second element from last.
    */
    void insertValBeforeTail(int val);
    /**
    * A value would be provided, you have to insert it as the
    * first element.
    */
    void insertAtHead(int val);
    /**
    * A value would be provided, you have to insert it as the
    * second element.
    */
    void insertAfterHead(int val);
    /**
    * A value and a position would be provided, you have to
    * insert the value in the provided position from first.
    */
    void insertAtPos(int val, int pos);
    /**
    * A value would be provided, you have to find the position
    * of its first occurrence from first.
    */
    int findVal(int val);
    /**
    * A position would be provided, you have to find the value
    * of the corresponding position from first.
    */
    int findValAtPos(int pos);
    /**
    * Print all the values in the list from first to last.
    */
    void traverse();
    /**
    * A value would be provided, delete all occurrence
    * of the value from the list.
    */
    void deleteVal(int val);
    /**
    * A value would be provided, delete the first occurrence
    * of the value from first.
    */
    void deleteOne(int val);
    /**
    * A value would be provided, delete the value at
    * position pos.
    */
    void deletePos(int pos);
    /**
    * Delete all elements of the list.
    */
    void deleteAll();
    /**
    * Delete the first element of the list.
    */
    void deleteHead();
    /**
    * Delete the last element of the list.
    */
    void deleteTail();

    node *find_befo_tail();
    node *find_bef_pos(int pos);
    node *find_befo_val(int val);
};

SinglyLinkedList::SinglyLinkedList(){
        head = tail = NULL;
    }
void SinglyLinkedList::insertVal(int val)
{
    node *x=new node;
    x->val=val;
    if(head==NULL)
    {
        head=x;
        tail=x;
    }
    else
    {
        tail->next=x;
        tail=x;
    }
    return;
}

node *SinglyLinkedList::find_befo_tail()
{
    node *x;
    x=head;
    while(x!=tail)
    {
        if(x->next==tail) break;
        x=x->next;
    }
    return x;
}

void SinglyLinkedList::insertValBeforeTail(int n)
{
    node *beft, *cur=new node;
    beft=find_befo_tail();

    cur->val=n;
    cur->next=tail;
    beft->next=cur;
    return;

}

void SinglyLinkedList::traverse()
{
    node *x;
    x=head;
    while(x!=tail)
    {
        cout<<x->val<<endl;
        x=x->next;
    }
    cout<<tail->val<<endl;

    return;
}

void SinglyLinkedList::insertAtHead(int val)
{
    node *now=new node;
    now->val=val;
    now->next=head;
    head=now;

    return;
}

void SinglyLinkedList::insertAfterHead(int val)
{
    node *now=new node;
    now->val=val;
    now->next=head->next;
    head->next=now;

    return;
}
node *SinglyLinkedList::find_bef_pos(int pos)
{
    node *b, *x;
    int i=1;
    x=head;
    while(x!=tail&&i<pos-1)
    {
        i++;
        x=x->next;
    }
    return x;

}

void SinglyLinkedList::insertAtPos(int val, int pos)
{
    node *now=new node;

    now->val=val;
    node *p=find_bef_pos(pos);
    now->next=p->next;
    p->next=now;


    return;
}

int SinglyLinkedList::findVal(int Val)
{
    node *x;
    int pos=0;
    x=head;
    while(x!=NULL)
    {
        pos++;
        if(x->val==Val) return pos;
        x=x->next;
    }
    return 0;
}

int SinglyLinkedList::findValAtPos(int pos)
{
    node *x;
    x=head;
    pos--;
    while(x!=tail&&pos--)
    {
        x=x->next;
    }
    return x->val;

}

node *SinglyLinkedList::find_befo_val(int val)
{
    node *x;
    x=head;
    while(x!=NULL)
    {
        if(x->next->val==val) return x;
        x=x->next;
    }
    return x;
}

void SinglyLinkedList::deleteOne(int val)
{
    node *b;
    b=find_befo_val(val);
    if(b->next!=NULL)
    {
        node *t=b->next;
        b->next=t->next;
        delete t;
    }
    return;

}

void SinglyLinkedList::deleteHead()
{
        node *t=head;
        head=head->next;
        delete t;
        return;
}

void SinglyLinkedList::deletePos(int pos)
{
    node *b=find_bef_pos(pos);
    if(pos==1)
    {
        deleteHead();

    }

    if(b->next!=NULL)
    {
        node *t=b->next;
        b->next=t->next;
        delete t;

    }
    return;

}

void SinglyLinkedList::deleteTail()
{
    node *b=find_befo_tail(), *x;
    x=tail;
    tail=b;
    delete x;

    return;
}



int main()
{
    SinglyLinkedList *wow = new SinglyLinkedList;

    delete wow;
    return 0;
}
