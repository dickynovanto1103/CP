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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 50000;
bool isprime[maxn + 5];
int prime[maxn];

void sieve(int n) {
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++) {
		if(isprime[i]) {
			for(j=i*2;j<=n;j+=i) {
				isprime[j] = false;
			}
		}
	}
}

int main(){
	int i,j;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++) {
		if(isprime[i]) {
			prime[cnt] = i;
			cnt++;
		}
	}

	int t, tc = 0;
	scanf("%d", &t);

	while (t--) {
		int lp = 2;
		int n;
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) {
			if (isprime[i]) {
				lp = i;
			}
		}
		printf("Case #%d: %d\n", ++tc, lp);
	}

	return 0; 
};