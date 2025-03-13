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

vector<vi> digits, tempOutput;

void putIntoDigits(int idx, int v) {
	int idxPlace = 10;
	while(v) {
		int digit = v%10;
		digits[idx][idxPlace--] = digit;
		v /= 10;
	}
}

void stableSortDigits(int n) {
	tempOutput.assign(n+1, vi(11, 0));
	//process dari idx ke 10 sampe ke 0
	for(int idx=10;idx>=0;idx--){
		//do counting sort
		int cnt[11] = {};
		for(int i=0;i<n;i++){
			cnt[digits[i][idx]]++;
		}

		for(int i=1;i<10;i++){
			cnt[i] = cnt[i] + cnt[i-1];
		}

		for(int i=n-1;i>=0;i--){
			int placedIdx = --cnt[digits[i][idx]];
			tempOutput[placedIdx] = digits[i];
		}

		for(int i=0;i<n;i++){
			digits[i] = tempOutput[i];
		}
	}
}

void solve(){
	int n;
	scanf("%d",&n);
	int a[100];
	digits.assign(n+1, vi(11, 0));
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		putIntoDigits(i, a[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++){
			printf("%d ", digits[i][j]);
		}
		puts("");
	}

	stableSortDigits(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++){
			printf("%d ", digits[i][j]);
		}
		puts("");
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