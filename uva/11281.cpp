#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin>>m;

    double pg[m+10];

    for(int i=1;i<=m;i++)
    {

        cin>>pg[i];
        pg[i]/=2.0;
    }
    int n;
    cin>>n;
//    cout<<n<<endl;

    for(int i=1;i<=n;i++)
    {
        double l[3];

        cin>>l[0]>>l[1]>>l[2];
        sort(l, l+3);

        double x=l[2]/(l[1]+l[0]);

        double d=l[1]*x-l[2]/2.0;

        double s=(l[0]+l[1]+l[2])/2.0;

        double area=sqrt(s*(s-l[0])*(s-l[1])*(s-l[2]));

        double h1=2.0*area/l[2];

        double bx=sqrt(l[1]*l[1]-h1*h1);

        d=bx-l[2]/2.0;
//        cout<<h1<<endl;

        vector<int> v;

        for(int j=1;j<=m;j++)
        {
            double r=pg[j];

            if(l[2]>=l[1]+l[0])
            {
                if(l[2]<=2*r) v.push_back(j);

                continue;

            }
            if(r<(l[2]/2.0) || r<d) continue;
            double h2=sqrt(r*r-l[2]*l[2]/4.0)+ sqrt(r*r-d*d);

//            cout<<h2<<endl;

            if(h2>=h1) v.push_back(j);



        }

        if(v.size()>0)
		{
			cout<<"Peg "<<(char)('A'+i-1)<<" will fit into hole(s):";
			for(int j=0;j<v.size();j++)
			{
				cout<<" "<<v[j];
			}
			cout<<endl;
		}

		else
		{
			cout<<"Peg "<<(char)('A'+i-1)<<" will not fit into any holes"<<endl;
		}

    }

    return 0;
}

/**
3
4.0 5.0 6.0
3
3.0 4.0 5.0
5.0 5.0 5.0
4.5 4.5 8.0

1
8.25
1
6 7 8
*/
