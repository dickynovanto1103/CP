/*
ID: dickyno1
LANG: C++14
TASK: prefix
*/

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

int dp[200010];

int main(){
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);

	vector<string> vs;
	string s;
	while(cin>>s && s != ".") {
		vs.pb(s);
	}

	s = "";
	string temp;
	while(cin>>temp) {
		s += temp;
	}

	int n = s.size();

	for(int i=0;i<n;i++){
		if(i > 0 && dp[i-1] == 0) continue;
		for(string st: vs) {
			int sisa = n - i;
			int len = st.size();
			if(sisa >= len) {
				string sub = s.substr(i, len);
				if(sub == st) {
					dp[i + len - 1] = 1;
				}
			}
		}
	}

	int maks = 0;
	for(int i=0;i<n;i++){
		// cout<<dp[i]<<endl;
		if(dp[i]){
			maks = max(maks, i+1);
		}
	}
	
	printf("%d\n", maks);

	return 0;
};
