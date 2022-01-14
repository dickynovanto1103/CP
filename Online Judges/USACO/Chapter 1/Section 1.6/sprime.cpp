/*
ID: dickyno1
LANG: C++14
TASK: sprime
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

// const int maxn = 1e8;

// bool isprime[maxn + 1];

// void sieve(int n) {
// 	isprime[0] = isprime[1] = false;
// 	for(int i=2;i*i<=n;i++){
// 		if(!isprime[i]) continue;
// 		for(int j=i*i;j<=n;j+=i){
// 			isprime[j] = false;
// 		}
// 	}
// }

// bool isSpecial(int n) {
// 	while(n) {
// 		if(!isprime[n]){
// 			return false;
// 		}
// 		n /= 10;
// 	}

// 	return true;
// }

// int cntDigit(int n){
// 	int cnt = 0;
// 	while(n){
// 		cnt++;
// 		n /= 10;
// 	}
// 	return cnt;
// }

vector<vi> adj(10);

int main(){
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	// memset(isprime, true, sizeof isprime);

	// sieve(maxn);
	// int cnt = 0;
	// for(int i=1;i<=maxn;i++){
	// 	if(isprime[i]){
	// 		if(isSpecial(i)){
	// 			adj[cntDigit(i)].pb(i);
	// 		}
	// 		cnt++;
	// 	}
	// }

	// for(int i=1;i<=8;i++){
	// 	printf("digit %d\n", i);
	// 	for(int j=0;j<adj[i].size();j++){
	// 		printf("%d,", adj[i][j]);
	// 	}
	// 	puts("");
	// }
	adj[1] = {2,3,5,7};
	adj[2] = {23,29,31,37,53,59,71,73,79};
	adj[3] = {233,239,293,311,313,317,373,379,593,599,719,733,739,797};
	adj[4] = {2333,2339,2393,2399,2939,3119,3137,3733,3739,3793,3797,5939,7193,7331,7333,7393};
	adj[5] = {23333,23339,23399,23993,29399,31193,31379,37337,37339,37397,59393,59399,71933,73331,73939};
	adj[6] = {233993,239933,293999,373379,373393,593933,593993,719333,739391,739393,739397,739399},
	adj[7] = {2339933,2399333,2939999,3733799,5939333,7393913,7393931,7393933};
	adj[8] = {23399339,29399999,37337999,59393339,73939133};

	int n;
	scanf("%d",&n);
	for(int i=0;i<adj[n].size();i++){
		printf("%d\n",adj[n][i]);
	}
	// printf("cnt: %d\n", cnt);
	
	return 0;
};