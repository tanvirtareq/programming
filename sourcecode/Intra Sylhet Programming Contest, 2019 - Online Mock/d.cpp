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



bool inline isleap(int a)
{
    if(a%4==0 and a%100!=0) return 1;
    if(a%4==0 and a%100==0 and a%400==0) return 1;

    else return 0;

}


int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int hh, mm, ss, dd, mo, yy, r;
        char ch;
//
        cin>>hh>>ch>>mm>>ch>>ss>>dd>>ch>>mo>>ch>>yy>>r;
//
        int x=hh+r;
//
        hh=x%24;
//
        int a=x/24;

//        cout<<r<<endl;
//
        x=dd+a;

//        cout<<hh<<endl;
//
        while(x>0)
        {

            if(mo==1)
            {
                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }

            }

            else if(mo==2)
            {
                if(!isleap(yy))
                {
                    if(x<=28)
                    {
                        dd=x;
                        x=0;
                    }

                    else
                    {
                        mo++;
                        x=x-28;
                    }

                }

                else
                {
                    if(x<=29)
                    {
                        dd=x;
                        x=0;
                    }

                    else
                    {
                        mo++;
                        x=x-29;
                    }

                }

            }

            else if(mo==3)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }

            }

            else if(mo==4)
            {

                if(x<=30)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-30;

                }


            }

           else if(mo==5)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }


            }

            else if(mo==6)
            {

                if(x<=30)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-30;

                }


            }

            else if(mo==7)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }


            }

            else if(mo==8)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }


            }

            else if(mo==9)
            {

                if(x<=30)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-30;

                }


            }

            else if(mo==10)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-31;

                }


            }

            else if(mo==11)
            {

                if(x<=30)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo++;
                    x=x-30;

                }


            }

           else  if(mo==12)
            {

                if(x<=31)
                {
                    dd=x;
                    x=0;
                }
                else{
                    mo=1;
                    x=x-31;

                    yy++;



                }


            }



        }
        cout<<hh<<" : "<<mm<<" : "<<ss<<endl;

//        cout<<hh<<" : "<<mm<<endl;
        cout<<dd<<" - "<<mo<<" - "<<yy<<endl;
//
    }

	return 0;
}

/**

*/




