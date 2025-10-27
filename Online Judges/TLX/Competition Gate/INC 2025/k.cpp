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
	while(cin>>s) {
		int cnt[26] = {0};
		for(char c: s) {
			cnt[c-'a']++;
		}

		// cout<<s<<endl;
		// for(int i=0;i<26;i++){
		// 	if(cnt[i] == 0) {
		// 		continue;
		// 	}
		// 	// printf("cnt[%c]: %d\n", i + 'a', cnt[i]);
		// }

		vector<char> oddChars, evenChars;
		for(int i=0;i<26;i++){
			if(cnt[i] == 0) {
				continue;
			}

			if(cnt[i] % 2 == 1) {
				oddChars.pb(i + 'a');
			}else{
				evenChars.pb(i + 'a');
			}
		}

		vector<string> ans;
		//get first, and end of even chars, get one oddChars, if exist
		string ansAwal, ansAkhir;
		for(int i=0;i<evenChars.size();i++){
			int cntChar = cnt[evenChars[i] - 'a'];
			for(int j=0;j<cntChar/2;j++) {
				ansAwal += evenChars[i];
			}
		}

		for(int i=evenChars.size() - 1;i>=0;i--){
			int cntChar = cnt[evenChars[i] - 'a'];
			for(int j=0;j<cntChar/2;j++) {
				ansAkhir += evenChars[i];
			}
		}

		string ansTengah;
		if(oddChars.size() > 0) {
			char c = oddChars.back(); oddChars.pop_back();
			int cntChar = cnt[c - 'a'];
			for(int i=0;i<cntChar;i++){
				ansTengah += c;
			}
		}

		ans.pb(ansAwal + ansTengah + ansAkhir);
		while(oddChars.size() > 0) {
			char c = oddChars.back(); oddChars.pop_back();
			int cntChar = cnt[c - 'a'];
			string str;
			for(int i=0;i<cntChar;i++){
				str += c;
			}

			ans.pb(str);
		}

		printf("%d\n", ans.size());
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<endl;
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