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

const int maxn = 1e5 + 5;

int idx[1000010];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		for(j=i*i;j<=n;j+=i){
			if(isprime[i]){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	vi idx1;
	memset(idx, -1, sizeof idx);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 1){idx1.pb(i+1);}
		idx[a[i]] = i+1;
		// printf("idx[%d]: %d\n",a[i], i+1);
	}
	// printf("ukuran: %d\n",(int)idx1.size());
	if((int)idx1.size() >= 2){
		printf("%d %d\n",idx1[0], idx1[1]);
		return 0;
	}


	int fib[1000];
	fib[0] = 0; fib[1] = 1;
	for(i=2;i<=30;i++){
		fib[i] = fib[i-1] + fib[i-2];
		// printf("fib[%d]: %d\n",i,fib[i]);
	}

	for(i=2;i<=29;i++){
		// printf("fib[%d]: %d fib[%d]: %d\n",i,fib[i], i+1, fib[i+1]);
		if(idx[fib[i]] != -1 && idx[fib[i+1]] != -1){
			printf("%d %d\n",idx[fib[i]],idx[fib[i+1]]);
			return 0;
		}
	}
	printf("impossible\n");


	return 0;
};