#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

template<class T>
void inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

    for(int i=x;i>=0;i--)
    {
        if(a&((T)1<<i))
        cout<<1;
        else cout<<0;

    }
    cout<<endl;

    return;

}

li inline power(li b, li p)
{
    if(b==2) return (li)1<<(p);

    if(p==0) return 1;

    if(p==1) return b;

    li x=power(b, p/2);

    if(p&1)
    {
        return b*x*x;
    }

    else return x*x;

}


/// for seive prime

#define sz 1000000

bool chk[sz+5];
vector<int> prime;

void seive()
{
    prime.push_back(2);

    for(int i=3;i*i<=sz;i+=2)
    {
        if(chk[i]==0) {

        for(int j=i+i;j<=sz;j+=i)
            chk[j]=1;

        }
    }


    for(int i=3;i<=sz;i+=2)
    {
        if(chk[i]==0){
            prime.push_back(i);
        }
    }

   // cout<< prime[0] <<endl;


}

#define m 999983


struct Hnode{
li value, number;

Hnode *next;

};

struct Hv{
    li val, number;

    Hnode *next;

}hasharr[m+10];

li stkTop=0;

bool vis[m+10];


li hashCreat(li x)
{
//    cout<<x<<endl;

    li idx=abs(x)%m;

    if(vis[idx]==0)
    {
//        if(x==79) cout<<"r"<<endl;

        vis[idx]=1;

        hasharr[idx].val=x;
        hasharr[idx].number=1;
        hasharr[idx].next=NULL;

    }

    else if(x==hasharr[idx].val)
    {
        hasharr[idx].number++;
    }

    else{
        Hnode *pre=NULL;

        Hnode *cur=hasharr[idx].next;

//        if(cur==NULL)

        while(cur!=NULL  and  cur->value!=x )
        {
            pre=cur;
            cur=cur->next;
        }

//        cout<<"r"<<endl;

        if(cur!=NULL and cur->value==x)
        {
//            if(x==79)
//            cout<<"r"<<endl;
            cur->number++;
        }

        else if(pre==NULL)
        {
            cur=new Hnode();
            hasharr[idx].next=cur;
            cur->value=x;
            cur->number=1;
            cur->next=NULL;

        }

        else
        {
            cur=new Hnode();
            pre->next=cur;
            cur->value=x;
            cur->number=1;
            cur->next=NULL;
        }

    }

//    if(x==79) cout<<"r"<<endl;

    return 0;

}

li hashSearch(li x)
{
    li idx=abs(x)%m;

    if(vis[idx]==0) return 0;

    if(hasharr[idx].val==x)
    {
        if(hasharr[idx].number>0)
        {

            return hasharr[idx].number;
        }

        return 0;
    }

    Hnode *cur, *pre;

    pre=NULL;

    cur=hasharr[idx].next;

    while(cur!=NULL and cur->value!=x)
    {
        pre=cur;
        cur=cur->next;
    }

    if(cur==NULL)
    {
        return 0;
    }

    if(cur->value==x)
    {
        if(cur->number>0)
        {

            return cur->number;
        }

        return 0;

    }



}

li dlt(Hnode *cur)
{
    if(cur==NULL) return 0;

    Hnode *x=cur->next;

    dlt(x);

    delete cur;

    return 0;

}

li del()
{
    for(li i=0;i<=m;i++)
    {
        if(vis[i]!=0)
        {
            Hnode *cur=hasharr[i].next;

            dlt(cur);

        }
    }

    return 0;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



//    cout<<prime[prime.size()-1]<<endl;

li f=0;

    li t;

    cin>>t;

    while(t--)
    {
        if(f==1) cout<<endl;

        f=1;
        li n;

        cin>>n;

        li a[n+10], b[n+10], c[n+10], d[n+10];

        memset(hasharr, 0, sizeof hasharr);
        memset(vis, 0, sizeof vis);

        for(li i=1;i<=n;i++)
        {

            cin>>a[i]>>b[i]>>c[i]>>d[i];

        }

//        cout<<"r"<<endl;

        li x=0;

        for(li i=1;i<=n;i++)
            for(li j=1;j<=n;j++)
                hashCreat(a[i]+b[j]);

//        cout<<"r"<<endl;

        for(li i=1;i<=n;i++)
            for(li j=1;j<=n;j++)
                x+=hashSearch(-c[i]-d[j]);


        cout<<x<<endl;

        del();


    }


	return 0;
}

/**

6
11 5 5 -19
0 19 -10 -5
-17 20 7 12
13 12 -3 20
-19 -13 5 11
20 9 20 15
*/

