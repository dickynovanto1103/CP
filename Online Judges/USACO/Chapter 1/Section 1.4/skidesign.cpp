/*
ID: dickyno1
LANG: C++14
TASK: skidesign
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

int main(){
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	int a[1010];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a, a+n);
	int diff = a[n-1] - a[0];
	if(diff <= 17){
		puts("0");
		return 0;
	}


	int jawab = inf;
	for(i=0;i<=100-17;i++) {
		int minim = i;
		int maks = i + 17;
		int ans = 0;
		for(j=0;j<n;j++){
			if(a[j] < minim) {
				int selisih = minim - a[j];
				// printf("selisih sama minim: %d\n", selisih);
				ans += (selisih*selisih);
			}
			if(a[j] > maks) {
				int selisih = a[j] - maks;
				// printf("selsiih sama maks: %d\n", selisih);
				ans += (selisih * selisih);
			}
		}
		// printf("minim: %d maks: %d ans: %d\n", minim, maks, ans);
		jawab = min(jawab, ans);
	}

	printf("%d\n", jawab);
	
	return 0;
};