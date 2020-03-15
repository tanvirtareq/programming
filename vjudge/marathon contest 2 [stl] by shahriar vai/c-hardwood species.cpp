#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);

    freopen("input.txt", "r", stdin);

    map<string, int> wp;

    vector<string> v;

    char st[40];

    int t;

    cin>>t;

//    cout<<"t="<<t<<endl;

    cin.ignore();

    while(t--)
    {
        cout<<endl;

        wp.clear();

        v.clear();

//        cin.ignore();

        int total=0;

//        cout<<"total="<<total<<endl;

        while(gets(st)&&st[0]!=0)
        {
//            cout<<"st="<<st<<endl;
            if(wp[st]==0)
            {

                v.push_back(st);

//                cout<<"v size"<<v.size()<<endl;
            }


            wp[st]++;



            total++;

//            cout<<"wp[st]="<<wp[st]<<"\t total="<<total<<endl;



        }

//        cout<<"v size="<<v.size()<<endl;


        sort(v.begin(), v.end());

//        cout<<"v size="<<v.size()<<endl;

        for(int i=0;i<v.size();i++)
        {
//            cout<<"v["<<i<<"]="<<v[i]<<endl;

            double ans=(double)wp[v[i]]*100.0/total;

            cout<<v[i]<<" "<<fixed<<setprecision(4)<<ans<<endl;

        }

        cout<<endl;

    }





    return 0;

}
