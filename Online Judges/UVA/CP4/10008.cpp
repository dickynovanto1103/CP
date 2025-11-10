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
typedef pair<int, char> ic;
typedef vector<ii> vii;

bool isLowercase(char c) {
	return c >= 'a' && c <= 'z';
}

bool isUppercase(char c) {
	return c >= 'A' && c <= 'Z';
}

bool isAlphabet(char c) {
	return isLowercase(c) || isUppercase(c);
}

void solve(){
	int n;
	cin>>n;
	string dum;
	getline(cin, dum);
	int cnt[26] = {0};
	while(n--){
		string s;
		getline(cin, s);
		for(char c: s) {
			if(isAlphabet(c)) {
				if(isLowercase(c)) {
					cnt[c - 'a']++;
					// printf("adding char: %c\n", c);
				}else{
					cnt[c - 'A']++;
					// printf("adding char: %c\n", c);
				}
			}
		}
	}

	vector<ic> res;
	for(int i=0;i<26;i++){
		if(cnt[i]) {
			res.emplace_back(-cnt[i], i + 'A');
		}
	}

	sort(res.begin(), res.end());
	for(ic val: res) {
		cout<<val.second << " "<<-val.first<<endl;
	}
}

int main(){
	FastSlowInput;
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};