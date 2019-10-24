#include<bits/stdc++.h>
#define sz 5000010

typedef long long unsigned ull;

using namespace std;

//int c[sz/32];
//vector<int>p;
//int phi[sz];
//
//void seive()
//{
//    p.push_back(2);
//
//    for(int i=3;i<=sz;i+=2)
//    {
//        if((c[i/32]&(1<<(i%32)))==0)
//        {
//            p.push_back(i);
////            cout<<i<<endl;
//            for(int j=i*i;j<=sz;j=j+2*i)
//            {
//                c[j/32]|=1<<(j%32);
//            }
//        }
//
//    }
//    return;
//}
ull score[sz];
int ph[sz];

void seivephi()
{
    ph[0]=0;
    ph[1]=1;
    score[1]=1;
    score[0]=0;
    for(int i=1;i<=sz;i++)
    {
        ph[i]=i;
    }
    for(int i=2;i<=sz;i++)
    {
        if(ph[i]==i)
        {
            for(int j=i;j<=sz;j=j+i)
            {
               ph[j]=ph[j]/i*(i-1);
            }
        }
         score[i]= (ull) ph[i]*ph[i]+score[i-1];
    }
//    for(int i=2;i<=sz;i++)
//    {
//        score[i]= (llu) ph[i]*ph[i]+score[i-1];
////        cout<<i<<" "<<score[i]<<endl;
//    }
    return;
}

int main()
{
    seivephi();
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
//        cout<<"Case "<<i<<": "<<score[b]-score[a-1]<<endl;
        printf("Case %d: %llu\n", i, score[b]-score[a-1]);
    }

    return 0;
}
