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
	string s;
	cin>>s;
	stack<char> st;
	st.push(s[0]);
	set<char> setChar;
	set<char>::iterator it;
	unordered_map<char, vector<char>> adj;

	for(int i=1;i<s.size();i++){
		setChar.insert(s[i]);
		if(st.top() == s[i]) {
			st.pop();
			continue;
		}
		char top = st.top();
		adj[top].pb(s[i]);
		adj[s[i]].pb(top);
		st.push(s[i]);
	}

	vector<char> v;
	for(it=setChar.begin();it!=setChar.end();it++){
		v.pb(*it);
	}

	for(char c: v) {
		printf("%c = %d\n", c, adj[c].size());
	}
}

int main(){
	int tc = 1;
	int tt = 1;
	scanf("%d",&tc);
	while(tc--){
		printf("Case %d\n", tt++);
		solve();
	}

	return 0;
};