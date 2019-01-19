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

const int maxn = 2e6;

bool isprime[maxn+6];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int cnt[maxn + 5];

int main(){
	int i,j,q;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	for(i=1;i<=maxn;i++){
		if(!isprime[i]){
			for(j=i;j<=maxn;j+=i){
				cnt[j]++;
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		printf("%d\n",cnt[n]);
	}
	return 0;
};