#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int r,p,s;
		scanf("%d %d %d",&r,&p,&s);
		
		string st;
		cin>>st;
		int cnt[3];
		memset(cnt, 0, sizeof cnt);
		vector<vi> adj;
		adj.assign(256, vi());
		for(i=0;i<n;i++){
			adj[st[i]].pb(i);
		}
		char ans[101];
		int tot = 0;
		for(i=0;i<n;i++){ans[i] = 'z';}
		for(i=0;i<adj['R'].size();i++){
			if(!p){break;}
			ans[adj['R'][i]] = 'P';
			tot++;
			p--;
		}

		for(i=0;i<adj['P'].size();i++){
			if(!s){break;}
			ans[adj['P'][i]] = 'S';
			tot++;
			s--;
		}

		for(i=0;i<adj['S'].size();i++){
			if(!r){break;}
			ans[adj['S'][i]] = 'R';
			tot++;
			r--;
		}
		bool valid = tot >= (n+1)/2;
		if(valid){
			printf("YES\n");
			for(i=0;i<n;i++){
				if(ans[i] == 'z'){
					if(r){ans[i] = 'R'; r--;}
					else if(p){ans[i] = 'P'; p--;}
					else if(s){ans[i] = 'S'; s--;}
				}
				printf("%c",ans[i]);
			}
			printf("\n");

		}else{
			printf("NO\n");
		}
		

	}
	return 0;
};