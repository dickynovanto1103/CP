#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[1<<15 + 1];
int prime[3520];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main() {
	int n=1<<15, i;
	memset(isprime,true,sizeof isprime);
	sieve(n);
	int cnt = 0;
	for(i=0;i<=n;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	while(scanf("%d",&n),n){
		int ans = 0;
		for(i=0;prime[i]<=n/2;i++){
			int bil = n-prime[i];
			if(isprime[bil]){ans++;}
		}
		printf("%d\n",ans);
	}
	return 0;
}