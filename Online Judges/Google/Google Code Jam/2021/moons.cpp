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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii findGroupsOfQuestionMark(string s) {
	vii v;
	int awal = -1, akhir = -1;
	for(int i=0;i<s.length();i++){
		if(s[i] == '?') {
			if(awal == -1){
				awal = i;
			}
			akhir = i;
		}else{
			if(awal != -1){
				v.pb(ii(awal, akhir));
				awal = -1, akhir = -1;
			}
		}
	}
	if(awal != -1) {
		assert(akhir != -1);
		v.pb(ii(awal, akhir ));
	}
	return v;
}

string fillQuestionMarkWithChar(char c, string s, ii range) {
	for(int i=range.first; i <= range.second; i++){
		s[i] = c;
	}
	return s;
}

int calculateScore(int x, int y, string jadi) {
	if(jadi == "CJ") {
		return x;
	}else if(jadi == "JC") {
		return y;
	}
	return 0;
}

int getScoreAtEdgeOfRange(ii range, string s, int x, int y) {
	int a = range.first, b = range.second;
	int score = 0;
	if(a > 0){
		string jadi;
		jadi += s[a-1];
		jadi += s[a];
		// cout<<"jadi: "<<jadi<<endl;
		score += calculateScore(x, y, jadi);
	}

	if(b < (s.length() - 1)) {
		string jadi;
		jadi += s[b];
		jadi += s[b+1];
		score += calculateScore(x, y, jadi);
	}
	return score;

}

int main(){
	int tc,i,j;
	scanf("%d", &tc);
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d: ",tt);
		int x,y;
		scanf("%d %d",&x,&y);
		string s;
		cin>>s;
		vii groups = findGroupsOfQuestionMark(s);
		int ans = 0;
		for (int i=0;i<s.length()-1;i++){
			string jadi;
			jadi += s[i];
			jadi += s[i+1];
			ans += calculateScore(x, y, jadi);
		}
		for(ii range: groups) {
			s = fillQuestionMarkWithChar('C', s, range);
			int score1 = getScoreAtEdgeOfRange(range, s, x, y);
			s = fillQuestionMarkWithChar('J', s, range);
			int score2 = getScoreAtEdgeOfRange(range, s, x, y);
			ans += min(score1, score2);
		}
		printf("%d\n",ans);
	}
	
	return 0;
};