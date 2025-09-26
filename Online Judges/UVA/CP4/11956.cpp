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

void solve(int tt){
	printf("Case %d:", tt);
	char s[100001];
	scanf("%s",s);
	int ans[100] = {0};
	int idx = 0;
	int len = strlen(s);
	for(int i=0;i<len;i++){
		if(s[i] == '>'){
			idx++;
			if(idx >= 100){idx -= 100;}
		}else if(s[i] == '<') {
			idx--;
			if(idx < 0) {idx += 100;}
		}else if(s[i] == '+') {
			ans[idx]++;
			if(ans[idx] >= 256){ans[idx]-=256;}
		}else if(s[i] == '-'){
			ans[idx]--;
			if(ans[idx] < 0) {ans[idx] += 256;}
		}
	}

	for(int i=0;i<100;i++){
		printf(" %3.2X", ans[i]);
	}
	puts("");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		solve(tt);
	}

	return 0;
};