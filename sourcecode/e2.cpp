#include<bits/stdc++.h>

using namespace std;

typedef long long int llu;

llu power(llu b, llu p)
{
    llu temp;

    if(p==0) return 1;

    else if(p%2==0)
    {
        temp=power(b, p/2);
        return temp*temp;

    }
    else
    {
        temp=power(b, p/2);

        return b*temp*temp;

    }

}

llu number_of_digit_from_Nth_digit_numb_to_Mth_digit_numb(llu n, llu m)
{
   llu i, j, ans=0;

   for(i=n;i<=m;i++)
   {
       ans+=9*power(10,i-1);
//        cout<<ans<<endl;
   }

    return ans;
}

int main()
{
    llu a, b, t;

    cin>>t;
    while(t--)
    {
        cin>>a>>b;

        // number of digit  of a and b is nda, ndb

        llu nda, ndb;

        /** number of digit from a to b is
        number of digit from a to gretest number of nda digit+
        (all nda+1 digit number) +( all nda+2 digit number) + ...( all ndb-1 digit number)+
        number of digit from lowest number of ndb digit to b

        */

        /**
        number of digit from a to gretest number of nda is
         (nda-a+1)*nda

        greatest number of nda digit = 10^nda-1

        number of all digit of all i digit number =9*10^(i-1)

        number of digit from lowest number of ndb digit to b is
        (b-lowest number of ndb digit +1)*ndb

        */

        /**
        total digit of all number from Ith digit to Jth digit is
        (Jth digit highest number - Ith digit lowest number + 1)
        */

        cout<<number_of_digit_from_Nth_digit_numb_to_Mth_digit_numb(a, b)<<endl;



    }

    return 0;
}
