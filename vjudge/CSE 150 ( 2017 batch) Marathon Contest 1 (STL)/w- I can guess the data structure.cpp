#include<bits/stdc++.h>

using namespace std;

int main()
{

    int che=3, n, c, x;
    while(cin>>n)
    {
        stack<int> st;
        queue<int>q;
        priority_queue<int>pq;
        int sc=1, qc=1, pqc=1;
        int fl=1;
        che=3;

        while(n--)
        {
            cin>>c>>x;
            if(c==1)
            {
                st.push(x);
                q.push(x);
                pq.push(x);
            }
            else if(c==2){
                if(sc==1&&!st.empty()&&x!=st.top())
                {
                    sc=0;
//                    cout<<st.empty();
                }
                if(qc==1&&!q.empty()&&x!=q.front())
                {
                    qc=0;
//                    cout<<q.empty();
                }
                if(pqc==1&&!pq.empty()&&x!=pq.top())
                {
                    pqc=0;
//                    cout<<pq.empty();
                }
                if(pq.empty()&&q.empty()&&st.empty())
                {
//                    cout<<"impossible"<<endl;
                    fl=0;

                }

                if(!pq.empty()&&x!=pq.top()&&
                   !q.empty()&&x!=q.front()&&
                   !st.empty()&&x!=st.top())
                {
//                    cout<<"impossible"<<endl;

                    fl=0;
                }

                if(sc==1&&!st.empty()&&st.top()==x) st.pop();
                if(pqc==1&&!pq.empty()&&pq.top()==x) pq.pop();
                if(qc==1&&!q.empty()&&q.front()==x) q.pop();

            }
        }
        che=sc+qc+pqc;
        if(fl==0) cout<<"impossible"<<endl;
        else if(fl==1&&che==0) cout<<"impossible"<<endl;
        else if(fl==1&&che>1) cout<<"not sure"<<endl;
        else if(fl==1&&sc==1) cout<<"stack"<<endl;
        else if(fl==1&&qc==1) cout<<"queue"<<endl;
        else if(fl==1&&pqc==1) cout<<"priority queue"<<endl;

    }

    return 0;
}

/**
1
1 1

2
1 2
2 1

2
1 2
2 2

4
2 1
1 3
1 4
2 2

10
2 1
1 3
2 4
1 6
1 7
1 8
2 8
2 7
2 6
2 3

6
1 2
1 3
1 1
2 1
2 3
2 2

6
1 2
1 3
2 3
1 4
2 4
2 2

8
1 5
1 3
2 3
1 8
1 4
2 4
2 8
2 5

*/

