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

bool isAlphabet(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void solve(){
	string s;
	while(getline(cin, s)) {
		int freq[256] = {0};
		for(char c: s) {
			// printf("%c", c);
			if(isAlphabet(c)) {
				freq[c]++;	
				// printf("freq[%d]: %d\n", c, freq[c]);
			}
		}
		// puts("");
		string ans = "";
		int maksFreq = 0;
		for(int i=0;i<256;i++) {
			if(maksFreq < freq[i]) {
				ans = "";
				ans += (char)i;
				maksFreq = freq[i];
			}else if(maksFreq == freq[i]) {
				ans += (char)i;
			}
		}
		cout<<ans<<" "<<maksFreq<<endl;
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