#include<iostream>

using namespace std;

struct v{
int numb;
v *prev=NULL, *nxt=NULL;
}*rear, *curr=NULL, *front;

void push(int n)
{
    v *nw=new v;

    nw->numb=n;
    nw->prev=curr;
    if(curr!=NULL)
    {
        curr->nxt=nw;
    }
    curr=nw;
    if(curr->prev==NULL)
    {
        front=nw;
    }
    cout<<curr->numb<<endl;
    rear=nw;

    return;
}

void travers()
{
    v *crnt;
    crnt=front;
//    cout<<crnt->numb<<endl;
    while(crnt!=NULL)
    {
        cout<<crnt->numb<<endl;
        crnt=crnt->nxt;
    }
    return;
}

void reverse_travers()
{
    v *crnt=rear;
    while(crnt!=NULL)
    {
        cout<<crnt->numb;
        crnt=crnt->prev;
    }
    return;
}

v *find_by_ln_search(int n)
{
    v *it=NULL, *i;
    i=front;
    while(i!=NULL)
    {
        if(i->numb==n)
        {
            it=i;
            break;
        }
        i=i->nxt;
    }
    return it;
}

void pop(v *x)
{
    v *prv, *nx;
    if(x!=NULL)
    {
        prv=x->prev;
        nx=x->nxt;
        prv->nxt=nx;
        nx->prev=prv;
        delete x;
    }


}
void pop(int n)
{
    v *x;
    x=find_by_ln_search(n);
    pop(x);
}

void push_after_n(int p, int n)
{
    v *x, *cr=new v, *nx;
    x=find_by_ln_search(n);
    nx=x->nxt;
    cr->numb=p;
    x->nxt=cr;
    cr->prev=x;
    cr->nxt=nx;
    return;

}

int main()
{
    for(int i=0;i<10;i++)
    {
        push(i);
    }
    cout<<endl;
    travers();
    cout<<endl;
    reverse_travers();
    cout<<endl;
    v *x;
    x=find_by_ln_search(4);
    cout<<x->nxt->numb<<endl;
    pop(x);
    travers();
    cout<<endl;
    pop(4);
    travers();
    cout<<endl;
    push_after_n(4, 3);
    travers();

    return 0;
}
