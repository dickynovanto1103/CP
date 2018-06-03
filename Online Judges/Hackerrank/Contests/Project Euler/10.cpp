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

const int maxn = 2000000;

bool isprime[maxn + 10];
ll sum[maxn + 10];
vi prime;

void sieve(int n) {
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


int main(){
	int i,j;
	// printf("test\n");
	memset(isprime,true,sizeof isprime);

	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime.pb(i);
			cnt++;
		}
	}
	
	memset(sum,0,sizeof sum);
	for(i=0;i<=maxn;i++){
		if(isprime[i]){sum[i] = i;}
	}
	for(i=1;i<=maxn;i++){
		sum[i] = sum[i] + sum[i-1];
	}
	// for(i=0;i<=maxn;i++){
	// 	printf("%d %lld\n",i,sum[i]);
	// }
	// printf("\n");
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",sum[n]);
	}

	return 0;
};