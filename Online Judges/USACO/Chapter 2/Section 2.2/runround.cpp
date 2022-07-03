/*
ID: dickyno1
LANG: C++14
TASK: runround
*/

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

bool isRunAroundNum(int num) {
	vi digits;
	int numDigit = 0;
	bool vis[10];
	memset(vis, false, sizeof vis);
	while(num) {
		int mod = num % 10;
		if(mod == 0){
			return false;
		}
		if(vis[mod]) {
			return false;
		}
		vis[mod] = true;
		digits.pb(mod);
		numDigit++;
		num /= 10;
	}
	reverse(digits.begin(), digits.end());
	
	memset(vis, false, sizeof vis);
	int curIdx = 0;
	int bil = digits[0];
	int numVis = 1;
	vis[0] = true;
	while(true) {
		int next = (curIdx + bil);
		while(next >= numDigit) {
			next -= numDigit;
		}
		if(vis[next]){
			return next == 0 && numVis == numDigit;
		}
		vis[next] = true;
		bil = digits[next];
		curIdx = next;
		numVis++;
	}
	return false;
}

int n;

vi convertNumToDigits(int num) {
	vi ans;
	while(num) {
		int mod = num % 10;
		ans.pb(mod);
		num /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void generateNum(int numDigit, int bil, bool vis[10]) {
	if(numDigit == 0){
		if(bil <= n) {
			return;
		}
		if(isRunAroundNum(bil)) {
			printf("%d\n", bil);
			exit(0);
		}
	}

	for(int i=1;i<=9;i++){
		if(!vis[i]) {
			vis[i] = true;
			generateNum(numDigit - 1, bil * 10 + i, vis);
			vis[i] = false;
		}
	}
}

int main(){
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	//142
	//1
	//4

	// int cntNum = 0;
	// int maksNum = 999999999;
	// // int maksNum = 81362;
	// int pangkat = 0;
	// for(int i=1;i<=maksNum;i++){
	// 	if(i % 1000000 == 0){
	// 		printf("i: %d\n", i);
	// 	}
	// 	if(isRunAroundNum(i)){
	// 		printf("%d\n", i);
	// 		cntNum++;
	// 	}
	// }

	scanf("%d",&n);
	vi v = convertNumToDigits(n);
	int numDigits = v.size();

	bool vis[10];
	memset(vis, false, sizeof vis);
	for(int i=numDigits;i<=8;i++) {
		generateNum(i, 0, vis);
	}
	
	return 0;
};