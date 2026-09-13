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
	scanf("%d",&n);
	string s;
	cin>>s;

	int sum = 0;
	for(int i=0;i<n;i++){
		sum += (s[i] == 'a' ? -1: 1);
	}

	unordered_map<int, int> mapper;
	int cur = 0;
	int ans = n;
	mapper[0] = -1;
	for(int i=0;i<n;i++){
		cur += (s[i] == 'a' ? -1: 1);
		mapper[cur] = i;
		if(mapper.find(cur - sum) != mapper.end()) {
			ans = min(ans, i - mapper[cur - sum]);
			continue;
		}

	}

	printf("%d\n", (ans == n ? -1 : ans));
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};