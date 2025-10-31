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

bool isLowerCase(char c) {
	return c >= 'a' && c <= 'z';
}

void solve(){
	string s1, s2;
	while(getline(cin, s1)) {
		getline(cin, s2);

		int cnt1[256] = {0}, cnt2[256] = {0};
		for(char c: s1) {
			assert(isLowerCase(c));
			cnt1[c]++;
		}

		for(char c: s2) {
			assert(isLowerCase(c));
			cnt2[c]++;
		}

		string ans;
		for(int i=0;i<256;i++){
			int minim = min(cnt1[i], cnt2[i]);
			for(int j=0;j<minim;j++){
				ans += (char)i;
			}
		}

		cout<<ans<<endl;
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