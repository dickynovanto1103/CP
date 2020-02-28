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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int maxRepOpt1(string text) {
	vector<vector<int> > adj;
	adj.assign(26, vector<int>() );
	for(int i=0;i<text.length();i++){
		char kar = text[i];
		adj[kar-'a'].push_back(i);
	}
	vector<pair<int,int> > v;
	int ans = 0;
	int i,j;
	for(i=0;i<26;i++){
		// printf("i: %d\n",i);
		if(adj[i].size() == 0){continue;}
		int cur = adj[i][0];
		int first = cur;
		v.push_back(pair<int,int>(cur, cur));
		for(j=1;j<adj[i].size();j++){
			int idx = adj[i][j];
			if(idx == (cur+1)){
				v.pop_back();
				v.push_back(pair<int,int>(first, idx));
			}else{
				v.push_back(pair<int,int>(idx, idx));
				first = idx;
			}
			cur = idx;
		}
		int sz = v.size();
		if(sz == 1){
			ans = max(ans, v[0].second - v[0].first + 1);
		}
		for(j=0;j<sz-1;j++){
			// printf("j: %d\n",j);
			pair<int,int> now = v[j], next = v[j+1];
			int ukuran1 = now.second - now.first + 1;
			int ukuran2 = next.second - next.first + 1;
			ans = max(ans, ukuran1); ans = max(ans, ukuran2);

			if(next.first - now.second <= 2){
				// printf("halo\n");
				ans = max(ans, ukuran1 + ukuran2);
				if((j + 2) < sz){
					ans = max(ans, ukuran1 + ukuran2 + 1);
				}
			}else{
				// printf("ukuran1: %d ukuran2: %d\n", ukuran1, ukuran2);
				ans = max(ans, ukuran1 + 1);
				ans = max(ans, ukuran2 + 1);

			}
		}

		for(j=sz-1;j>=1;j--){
			pair<int,int> now = v[j], next = v[j-1];
			// printf("now: %d %d next: %d %d\n",now.first, now.second, next.first, next.second);
			int ukuran1 = now.second - now.first + 1;
			int ukuran2 = next.second - next.first + 1;
			ans = max(ans, ukuran1); ans = max(ans, ukuran2);

			if(now.first - next.second <= 2){
				// printf("halo\n");
				ans = max(ans, ukuran1 + ukuran2);
				if((j - 2) >=0){
					ans = max(ans, ukuran1 + ukuran2 + 1);
				}
			}else{
				// printf("ukuran1: %d ukuran2: %d\n", ukuran1, ukuran2);
				ans = max(ans, ukuran1 + 1);
				ans = max(ans, ukuran2 + 1);

			}
		}
		
		v.clear();
	}
	return ans;
}
   

int main(){
	string s;
	cin>>s;
	printf("%d\n",maxRepOpt1(s));
	return 0;
};