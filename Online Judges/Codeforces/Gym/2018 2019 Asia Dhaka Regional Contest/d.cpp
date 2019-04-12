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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int cnt[30];
bool isprime[100010];
int prime[100000];

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

void factorize(int bil) {
	ll idx = 0, pf = prime[idx];
	while(pf*pf <= bil){
		while(bil % pf == 0){
			bil /= pf;
			cnt[pf]++;
		}
		pf = prime[++idx];
	}
	if(bil != 1){
		cnt[bil]++;
	}
}

int main(){
	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(100000);
	int con = 0;
	for(i=1;i<=100000;i++){
		if(isprime[i]){
			prime[con++] = i;
		}
	}
	for(i=2;i<=27;i++){
		printf("%c -> %d\n",i-2 + 'a', i);
	}
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ",tt);
		memset(cnt, 0, sizeof cnt);
		string kata;
		cin>>kata;
		int n = kata.length();
		for(i=0;i<n;i++){
			char kar = kata[i];
			int bil = kar - 'a' + 2;
			for(j=bil;j>=2;j--){
				factorize(j);
			}
		}
		for(i=2;i<=27;i++){
			printf("%c -> %d\n",i-2 + 'a', cnt[i]);
		}
		printf("\n");
		for(i=2;i<=27;i++){
			for(j=0;j<cnt[i];j++){
				printf("%c",i-2 + 'a');
			}
		}
		printf("\n");

	}
	return 0;
};