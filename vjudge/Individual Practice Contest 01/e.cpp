#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(ll i=a;i<=b;i++)
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

struct node
{
	int endmark;
	node* next[30];
	node()
	{
		endmark=0;
		for(int i=0;i<30;i++){
			next[i]=NULL;
		}
	}
}*root;

string s;

int Insert(string str)
{
	node* cur=root;
	for(int i=0;i<str.size();i++){
		int id=str[i]-'a';
		if(cur->next[id]==NULL){
			cur->next[id]=new node();
		}
		cur=cur->next[id];
	}
	cur->endmark++;
	return cur->endmark-1;
}

void prn(node * cur)
{
	for(int i=1;i<cur->endmark;i++)
	{
		cout<<s<<endl;
	}

	for(int id=0;id<26;id++)
	{
		if(cur->next[id]!=NULL)
		{
			s.push_back((char)('a'+id));
			prn(cur->next[id]);
			s.pop_back();
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	root=new node();
	vector<string> v;
	int f=0;
	while(n--)
	{
		string s;
		cin>>s;
		if(Insert(s)) f++;

	}
	if(f==0)
	{
		cout<<"SAFO"<<endl;
	}
	else
	{
		cout<<f<<endl;
		prn(root);
	}

	return 0;
}