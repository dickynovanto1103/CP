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
		bool isExtended = true;
		for(int i=1;i<s.size();i++){
			if(s[i] < s[i-1]) {
				isExtended = false;
				break;
			}
		}

		if(isExtended){
			puts("Yes");
		}else{
			puts("No");
		}
	}
}

string deduplicate(string s) {
	char prevChar = 'a';
	string res = "";
	for(int i=0;i<s.size();i++){
		if(prevChar == s[i]) {
			continue;
		}

		res += s[i];
		prevChar = s[i];
	}

	return res;
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};