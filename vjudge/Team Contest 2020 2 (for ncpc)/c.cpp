#include<bits/stdc++.h>
using namespace std;

int n,p,x[2*10002];
pair<int,int>par[10002];

map<int,int>mp;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>par[i].first>>par[i].second;
    }
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>x[i];
        mp[x[i]]++;
    }
    sort(x,x+p);
    sort(par,par+n);

    int j=0;

    vector<int>ans;

    int peg[1002]={0};

    for(int i=0;i<n;i++){
        int ok=0;
        for(int j=0;j<p;j++){
            if(par[i].first<=x[j] && par[i].second>=x[j]){
                peg[i]++;
            }
        }
        if(peg[i]>2){
            cout<<"impossible\n";
            return 0;
        }
    }


    for(int i=0;i<n;i++){
        if(peg[i]==0){
            int y=par[i].first+1;
            while(mp.find(y)!=mp.end()){
                y++;
            }
            ans.push_back(y);
            if(peg[i+1]<2){
                int y=par[i].second;
                while(mp.find(y)!=mp.end()){
                    y--;
                }
                ans.push_back(y);
                if(y==par[i+1].first){
                    peg[i+1]++;
                }
            }else{
                int y=par[i].second-1;
                while(mp.find(y)!=mp.end()){
                    y--;
                }
                ans.push_back(y);
            }
        }else if(peg[i]==1){
            if(peg[i+1]<2){
                int y=par[i].second;
                while(mp.find(y)!=mp.end()){
                    y--;
                }
                ans.push_back(y);
                if(y==par[i+1].first){
                    peg[i+1]++;
                }
            }else{
                int y=par[i].second-1;
                while(mp.find(y)!=mp.end()){
                    y--;
                }
                ans.push_back(y);
            }
        }
    }

    cout<<ans.size()<<endl;
    cout<<ans[0];
    for(int i=1;i<ans.size();i++){
        cout<<' '<<ans[i];
    }
    cout<<endl;


}
