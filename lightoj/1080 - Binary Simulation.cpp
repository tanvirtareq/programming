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

    #define sz 100000

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

    void rev(int node,int l, int r,  int a, int b, int segtree[])
    {
        if(a<=l and b>=r){
                segtree[node]++;
        return;
        }

        if(b<l or a>r ) return;

        int lc=2*node;
        int rc=lc+1;

        int m=(l+r)/2;

        rev(lc, l, m, a, b, segtree);
        rev(rc, m+1, r, a, b, segtree);

        return;

    }


    int cnt(int node,int l, int r,  int a, int segtree[])
    {
        if(a<=l and a>=r)  return segtree[node];

        if(a<l or a>r ) return 0;

        int lc=2*node;
        int rc=lc+1;

        int m=(l+r)/2;

        int x=cnt(lc, l, m, a,  segtree);
        int y=cnt(rc, m+1, r, a,  segtree);

        return x+y+segtree[node];

    }


    int main()
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t;

        cin>>t;
        for(int i=1;i<=t;i++)
        {
            cout<<"Case "<<i<<":"<<endl;

            string x;

            cin>>x;

    //        cout<<x<<endl;

            int segtree[300000];

            memset(segtree, 0, sizeof segtree);

            int q;

            cin>>q;

            while(q--)
            {
                char ch;
                cin>>ch;

                if(ch=='I')
                {
                    int a, b;
                    cin>>a>>b;

                    rev(1,1, x.size(), a, b, segtree);
                }

                if(ch=='Q')
                {
                    int a;
                    cin>>a;

                    int b=cnt(1, 1, x.size(), a, segtree);

    //                cout<<x<<"afsgg"<<b<<endl;

                    if(b%2==0)
                    {
                        cout<<x[a-1]<<endl;
                    }
                    else{
                        int ans=(x[a-1]-'0');

                        if(ans==0) ans=1;
                        else ans=0;

                        cout<<ans<<endl;
                    }

                }

            }

    //        cout<<"completed"<<endl;

            x.clear();

        }

        return 0;
    }

    /**

    2
    0011001100

    6

    I 1 10

    I 2 7

    Q 2

    Q 1

    Q 7

    Q 5

    1011110111

    6

    I 1 10

    I 2 7

    Q 2

    Q 1

    Q 7

    Q 5

    */
