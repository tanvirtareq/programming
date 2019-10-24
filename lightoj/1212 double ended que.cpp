#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, m, n;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        deque<int>d;

        cout<<"Case "<<i<<":"<<endl;

        cin>>n>>m;

        while(m--)
        {
            string cmnd;

            int x;

            cin>>cmnd;

            if(cmnd=="pushLeft")
            {
                cin>>x;
                if(d.size()>=n)
                {
                    cout<<"The queue is full"<<endl;
                }

                else
                {
                    d.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }

            }



            else if(cmnd=="pushRight")
            {

                cin>>x;
                if(d.size()>=n)
                {
                    cout<<"The queue is full"<<endl;
                }

                else
                {
                    d.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }

            }


            else if(cmnd=="popLeft")
            {
                if(d.size()<=0)
                {
                    cout<<"The queue is empty"<<endl;
                }

                else
                {

                    cout<<"Popped from left: "<<d.front()<<endl;
                    d.pop_front();
                }

            }


            else if(cmnd=="popRight")
            {
                if(d.size()<=0)
                {
                    cout<<"The queue is empty"<<endl;
                }

                else
                {

                    cout<<"Popped from right: "<<d.back()<<endl;
                    d.pop_back();
                }

            }


        }

    }

    return 0;
}
