/*
ID: dickyno1
LANG: C++14
TASK: combo
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

bool isClose(int a, int b, int n) {
	if(a > b){
		swap(a, b);
	}
	return abs(a - b) <= 2 || abs(a + n - b) <= 2;
}

int main(){
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	int a[10];
	for(i=0;i<6;i++){scanf("%d",&a[i]);}

	int cnt = 0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if((isClose(i, a[0], n) && isClose(j, a[1], n) && isClose(k, a[2], n)) || (isClose(i, a[3], n) && isClose(j, a[4], n) && isClose(k, a[5], n))) {
					// printf("i: %d j: %d k: %d\n", i,j,k);
					cnt++;
				}
				// if(isClose(k, a[2], n) || isClose(k, a[5], n)) {
				// 	printf("close: i: %d j: %d k: %d\n", i,j,k);
				// 	cnt++;
				// }
			}
		}
	}

	printf("%d\n", cnt);
	
	return 0;
};