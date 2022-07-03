/*
ID: dickyno1
LANG: C++14
TASK: hamming
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

vi v;
vi ans;
bool found = false;

bool isDistanceAtLeastD(int a, int b, int d, int numBit) {
	int cnt = 0;
	for(int i=0;i<numBit;i++){
		int bit1 = (1<<i) & a;
		int bit2 = (1<<i) & b;
		if(bit1 != bit2) {
			cnt++;
		}
	}

	return cnt >= d;
}

// void solve_slow(int cur, int n, int maks, int d, int numBit) {
// 	// printf("cur: %d n: %d\n", cur, n);
// 	printf("maks: %d\n", maks);
// 	if(found){
// 		return;
// 	}
// 	if(cur >= maks) {
// 		if(n > 0) {
// 			return;
// 		}
// 	}
// 	if(n == 0) {
// 		found = true;
// 		ans = v;
// 		return;
// 	}
// 	for(int i=cur;i<=maks;i++) {
// 		if(v.size() == 0) {
// 			v.pb(i);
// 			printf("first time push: %d sisa: %d\n", i, n-1);
// 			solve(i+1, n-1, maks, d, numBit);
// 			v.pop_back();
// 		}else{
// 			bool ok = true;
// 			for(int j=0;j<v.size();j++){
// 				if(!isDistanceAtLeastD(i, v[j], d, numBit)) {
// 					ok = false;
// 					break;
// 				}
// 			}
// 			if(ok) {
// 				v.pb(i);
// 				printf("ok push: %d sisa: %d\n", i, n-1);
// 				solve(i+1, n-1, maks, d, numBit);
// 				v.pop_back();
// 			}
// 		}
// 	}
// }

void solve(int cur, int n, int maks, int d, int numBit) {
	v.pb(0);
	for(int i=1;i<=maks;i++){
		bool ok = true;
		for(int j=0;j<v.size();j++){
			if(!isDistanceAtLeastD(i, v[j], d, numBit)) {
				ok = false;
				break;
			}
		}
		if(ok){
			v.pb(i);
			if(v.size() == n) {
				break;
			}
			// printf("pushed: %d\n", i);
		}
	}


	// printf("v size: %d\n", v.size());
	assert(v.size() == n);
}

int main(){
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	int n,b,d;
	scanf("%d %d %d",&n,&b,&d);
	solve(0, n, (1<<b) - 1, d, b);
	// assert(found == true);
	for(int i=0;i<v.size();i++){
		if(i%10 > 0) {printf(" ");}
		if(i%10 == 0 && i != 0) {
			puts("");
		}
		printf("%d", v[i]);
	}
	puts("");
	
	return 0;
};