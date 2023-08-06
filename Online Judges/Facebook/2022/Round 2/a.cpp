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

int pref[1000001][27];

void createPrefSum(string s) {

	for(int i=0;i<s.size();i++){
		pref[i][s[i] - 'a'] = 1;
		for(int j=0;j<26;j++){
			pref[i][j] += (i == 0 ? 0: pref[i-1][j]);
		}
	}
}

void resetPrefSum(int n) {
	for(int i=0;i<=n;i++){
		for(int j=0;j<26;j++){
			pref[i][j] = 0;
		}
	}
}

vector<int> compute(int l, int r) {
	vi res = vi(26);
	for(int j=0;j<26;j++){
		res[j] = pref[r][j] - (l == 0 ? 0 : pref[l-1][j]);
	}
	return res;
}

bool isProbablyCorrect(vi res) {
	int cntOdd = 0;
	for(int i=0;i<res.size();i++){
		if(res[i] % 2 == 1) cntOdd++; 
	}

	assert(cntOdd >= 1);

	return cntOdd == 1;
}

bool isHalf(vi orig, vi temp) {
	assert(orig.size() == temp.size());
	for(int i=0;i<orig.size();i++){
		if(temp[i] != orig[i] / 2) return false;
	}

	return true;
}

bool isAlmostPerfect(int l, int r) {
	if(l == r) return true;

	vi resAll = compute(l, r);

	if(!isProbablyCorrect(resAll)) return false;

	//probably correct
	int selisih = r - l + 1;

	vi resDepan = compute(l, l + (selisih / 2) - 1);
	if(isHalf(resAll, resDepan)) return true;

	vi resBelakang = compute(r - (selisih / 2) + 1, r);
	if(isHalf(resAll, resBelakang)) return true;

	return false;
}

int main(){
	int tc;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		string s;
		cin>>s;

		resetPrefSum(s.size());
		createPrefSum(s);
		
		int q;
		scanf("%d",&q);
		int ans = 0;
		while(q--){
			int a, b;
			scanf("%d %d",&a,&b);
			a--; b--;
			if((b-a+1) % 2 == 0) continue;

			if(isAlmostPerfect(a, b)) {
				ans++;
			}
		}

		printf("%d\n", ans);
	}
	
	return 0;
};