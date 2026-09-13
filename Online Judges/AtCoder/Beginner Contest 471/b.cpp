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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	while(scanf("%d",&n) != EOF) {
		string s;
		map<string, int> mapper;
			map<string, int>::iterator it;
		for(int i=0;i<n;i++){
			cin>>s;
			string newS;
			for(int i=0;i<s.size();i++){
				newS += tolower(s[i]);
			}
			
			mapper[newS]++;	
		}
		

		int ans = 0;
		for(it = mapper.begin();it != mapper.end();it++){
			ans = max(ans, it->second);
		}

		printf("%d\n", ans);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};