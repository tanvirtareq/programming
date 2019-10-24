#include<bits/stdc++.h>


using namespace std;

void find_lps(string pattern, int lps[])
{
    int i=1, j=0;

    lps[0]=0;

    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j])
        {
            j++;

            lps[i]=j;
            i++;
        }

        else if(j!=0)
        {
            j=lps[j-1];
        }

        else
        {
            lps[i]=0;
            i++;
        }

    }
    return ;
}

int kmpSearch(string text, string pattern, int lps[])
{
    int i=0, j=0, numberOfOccurance=0;

    while(i<text.size())
    {

        if(text[i]==pattern[j])
        {
            i++;
            j++;

            if(j>=pattern.size())
            {
                numberOfOccurance++;
                j=lps[j-1];

            }


        }

        else if(j!=0)
        {
            j=lps[j-1];

        }
        else i++;



    }

    return numberOfOccurance;


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        string text, pat;

        cin>>text>>pat;

        int lps[1000010];

        memset(lps, 0, sizeof lps);

        find_lps(pat, lps);

        cout<<"Case "<<i<<": "<<kmpSearch(text, pat, lps)<<endl;

    }

    return 0;
}

