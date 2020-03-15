#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
//    cin>>t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        int w, h;
        char ar[21][21];
//        cin>>w>>h;
        scanf("%d%d%*c%*c", &w, &h);
        cout<<w<<h<<endl;;
//        cin.ignore();
//        cin.ignore();
        pair<int, int> root;
        pair<int, int> x;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
//                char ch;
//                cin>>ar[i][j];
                scanf("%c", &ar[i][j]);
//                cout<<ar[i][j];
//                printf("%c", ar[i][j]);
//                cin.ignore();
                if(ar[i][j]=='@')
                  root=make_pair(i, j);
            }
            scanf("%*c%*c");
        }

        int cnt=0;
        queue<pair<int, int> > q;

        q.push(root);

        map<pair<int, int> , int> mp;

        while(!q.empty())
        {
            x=q.front();
//            if(mp[x]==1) continue;
            mp[x]=1;
            int i=x.first;
            int j=x.second;
            q.pop();
            cnt++;
//            mp[make_pair(1, 1)]=1;

//            cout<<i<<j<<ar[i][j]<<endl;
            if(mp[make_pair(i, j+1)]!=1&&(j+1)<=w&&ar[i][j+1]=='.'){ q.push(make_pair(i, j+1)); mp[make_pair(i, j+1)]=1 ;
//             cout<<i<<j+1<<".."<<ar[i][j+1]<<endl;
             }
            if(mp[make_pair(i, j-1)]!=1&&(j-1)>=1&&ar[i][j-1]=='.') {q.push(make_pair(i, j-1));mp[make_pair(i, j-1)]=1 ;
//            cout<<i<<j-1<<".."<<ar[i][j-11]<<endl;
            }
            if(mp[make_pair(i+1, j)]!=1&&(i+1)<=h&&ar[i+1][j]=='.') {q.push(make_pair(i+1, j));mp[make_pair(i+1, j)]=1 ;
//             cout<<i+1<<j<<".."<<ar[i+1][j]<<endl;
             }
            if(mp[make_pair(i-1, j)]!=1&&(i-1)>=1&&ar[i-1][j]=='.') {q.push(make_pair(i-1, j));mp[make_pair(i-1, j)]=1 ;
//             cout<<i-1<<j<<".."<<ar[i-1][j]<<endl;
             }
        }
//        cout<<"Case "<<i<<": "<<cnt<<endl;
        printf("Case %d: %d\n", i, cnt);

    }

    return 0;
}
/**
4

6 9

....#.

.....#

......

......

......

......

......

#@...#

.#..#.

11 9

.#.........

.#.#######.

.#.#.....#.

.#.#.###.#.

.#.#..@#.#.

.#.#####.#.

.#.......#.

.#########.

...........

11 6

..#..#..#..

..#..#..#..

..#..#..###

..#..#..#@.

..#..#..#..

..#..#..#..

7 7

..#.#..

..#.#..

###.###

...@...

###.###

..#.#..

..#.#..
*/
