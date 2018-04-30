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

const int maxn = 106200;
bool isprime[maxn + 3];
int prime[10010];

void sieve(int n) {
	isprime[0] = isprime[1] = false;
	int i,j;
	for(i=2;i*i<=n;i++) {
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i) {
				isprime[j] = false;
			}
		}
	}
}

int main(){
	int tc,i,j,n;

	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
			// printf("cnt: %d i: %d\n",cnt,i);
		}
	}
	// printf("test\n");
	printf("%d\n",prime[10000]);
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		n--;
		printf("%d\n",prime[n]);
	}

	return 0;
};