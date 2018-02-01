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

const int maxn = 4e5;
int prime[33900];
bool isprime[maxn+10];

void sieve(ll n){
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

int main(){
	int n,m,i,j;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=1;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	
	scanf("%d %d",&n,&m);
	//if(n==2){printf("2 2\n1 2 2\n"); return 0;}
	int sisa = n-2;
	int idx = lower_bound(prime,prime+cnt,sisa) - prime;
	int lanjut;
	if(prime[idx]==sisa){idx++; lanjut = prime[idx]-sisa; }
	else{lanjut = prime[idx]-sisa;}
	int mst = sisa + lanjut;
	printf("%d %d\n",mst,mst);
	for(i=1;i<=n-2;i++){
		printf("%d %d %d\n",i,i+1,1);
	}
	printf("%d %d %d\n",n-1,n,lanjut);
	sisa = m-(n-1);
	if(sisa==0){return 0;}
	for(i=1;i<=n;i++){
		for(j=i+2;j<=n;j++){
			printf("%d %d %d\n",i,j,1000000000);
			sisa--;
			if(sisa==0){return 0;}
		}
	}
	return 0;
};