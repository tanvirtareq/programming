#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
            stack<string>backstack, forwardtstack, empty;

            string current_page, comnd;

        current_page="http://www.lightoj.com/";

        cout<<"Case "<<i<<":"<<endl;

        while(cin>>comnd)
        {
            if(comnd=="QUIT") break;

            if(comnd=="VISIT")
            {
                  backstack.push(current_page);

                cin>>current_page;

                cout<<current_page<<endl;

                forwardtstack=empty;



            }

            if(comnd=="BACK")
            {
                if(backstack.empty()) cout<<"Ignored"<<endl;

                else
                {
                    forwardtstack.push(current_page);


                    current_page=backstack.top();
                    cout<<current_page<<endl;

                    backstack.pop();


                }

            }

            if(comnd=="FORWARD")
            {
                if(forwardtstack.empty()) cout<<"Ignored"<<endl;

                else
                {
                    backstack.push(current_page);

                    current_page=forwardtstack.top();
                    cout<<current_page<<endl;

                    forwardtstack.pop();

                }

            }
        }

//        backstack=empty;

//        forwardtstack=empty;


    }

    return 0;
}
