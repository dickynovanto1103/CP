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

string s;

int getLastIdxOfSentenceStartingAtIdx(int startIdx) {
	if(startIdx == -1) {
		return -1;
	}
	if(startIdx >= s.size()) {
		return -1;
	}

	char c = s[startIdx];
	if(c >= 'p' && c <= 'z') {
		return startIdx;
	}

	if(c == 'N') {
		return getLastIdxOfSentenceStartingAtIdx(startIdx + 1);
	}

	if(c == 'C' || c == 'D' || c == 'E' || c == 'I') {
		int lastIdx = getLastIdxOfSentenceStartingAtIdx(startIdx + 1);
		if(lastIdx == -1) {
			return -1;
		}
		return getLastIdxOfSentenceStartingAtIdx(lastIdx + 1);
	}

	return -1;
}

void solve(){
	while(cin>>s) {
		int lastIdx = getLastIdxOfSentenceStartingAtIdx(0);
		if(lastIdx == s.size() - 1) {
			puts("YES");
		}else{
			puts("NO");
		}
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