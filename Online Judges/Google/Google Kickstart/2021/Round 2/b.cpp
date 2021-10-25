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

const int maxn = 1000000;

int ans[maxn + 10];
void solve(int cur, int last, int step) {
	ans[cur] = max(ans[cur], step);
	// printf("ans[%d]: %d\n", cur, ans[cur]);
	for(int i=last*2;(i+cur)<=maxn;i+=last) {
		// printf("cur: %d coba: %d step: %d\n", cur, cur+i, step+1);
		solve(cur + i, i, step+1);
	}
}

int main(){
	
	// int last[maxn + 10];
	// memset(ans, 0, sizeof ans);
	// for(int i=3;i<=maxn;i++){
	// 	last[i] = i;
	// }
	// for(int i=3;i<=maxn;i++){
	// 	int cur = i;
	// 	int step = 1;
	// 	ans[i] = max(ans[i], 1);
	// 	printf("i: %d\n", i);
	// 	// printf("i: %d cur: %d\n", i, ans[i]);
	// 	for(int j=i*2;(i + j)<=maxn;j+=i){
	// 		printf("j: %d\n", j);
	// 		if((ans[i] + 1) > ans[i+j]) {
	// 			ans[i+j] = ans[i] + 1;
	// 			last[i+j] = j;
	// 			printf("last[%d]: %d\n", i+j, j);
	// 		}
	// 		printf("tambah biasa, current ans[%d]: %d\n", i+j, ans[i+j]);
	// 	}

	// 	for(int j=last[i]*2;(i + j) <= maxn;j+=last[i]) {
	// 		printf("sekarang j: %d\n", j);
	// 		if((ans[i] + 1) > ans[i + j]) {
	// 			ans[i+j] = ans[i] + 1;
	// 			last[i+j] = j;
	// 			printf("last[%d]: %d\n", i+j, j);
	// 		}
	// 		printf("tambah last, current ans[%d]: %d\n", i+j, ans[i+j]);
	// 	}
	// }
	for(int i=3;i<=maxn;i++){
		if(ans[i] == 0) {
			solve(i, i, 1);	
		}
		
	}
	int tc,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		printf("%d\n", ans[n]);
	}
	// for(int i=3;i<=50;i++){
	// 	printf("ans[%d]: %d\n", i, ans[i]);
	// }
	
	return 0;
};