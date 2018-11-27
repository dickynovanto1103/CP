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

const int maxn = 1e9;

bitset<maxn+10> isprime, grun;
int prime[50900000];
int cnt = 0;

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			// printf("i: %d\n",i);
			prime[cnt] = i; cnt++;
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
	for(i=i;i<=n;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
}

int main(){
	isprime.set();
	printf("halo1\n");
	sieve(maxn);
	printf("cnt: %d\n",cnt);
	int i,j;
	for(i=0;i<=maxn;i++){
		if(!grun[i]){
			printf("%d\n",i);
			for(j=0;j<cnt;j++){
				int next = i + prime[j]	-1;
				if(next > maxn){break;}
				grun[next] = true;
			}
		}
	}
	return 0;
};