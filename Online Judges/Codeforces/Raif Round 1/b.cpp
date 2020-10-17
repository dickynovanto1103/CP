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

vector<vi> adj;


int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;

		bool bisa[n+1];
		
		adj.assign(n+1, vi());
		memset(bisa, false, sizeof bisa);
		for(i=0;i<n;i++){
			int next = (i + 1) % n;
			if(s[i] == '-'){
				bisa[i] = true;
				bisa[next] = true;
				adj[i].pb(next); adj[next].pb(i);
			}else if(s[i] == '<'){
				adj[next].pb(i);
			}else{
				adj[i].pb(next);
			}
		}
		int bil = 0;
		for(i=0;i<n;i++){
			if(s[i] == '-'){continue;}
			else if(s[i] == '<'){
				bil |= 1;
			}else{
				bil |= 2;
			}
		}
		if(bil == 3){
			int ans = 0;
			for(i=0;i<n;i++){
				if(bisa[i]){
					ans++;
				}
			}
			printf("%d\n",ans);
		}else{
			printf("%d\n",n);
		}
	}
	
	return 0;
};