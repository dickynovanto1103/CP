#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define maxn 625000
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[maxn+10];
int prime[51000];

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
	memset(isprime,true,sizeof isprime);
	
	sieve(maxn);
	//printf("test\n");
	int cnt = 0,i;
	for(i=0;i<=maxn;i++){
		//printf("i:%d\n",i);
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	int n,k;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		int idx = k*i;
		printf("%d\n",prime[idx]);
	}
	return 0;
}