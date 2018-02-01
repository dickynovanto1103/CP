#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1000010;
bool isprime[maxn];
int prime[78500];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main() {
	int i,j,n;
	memset(isprime,true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i;cnt++;}
	}
	while(scanf("%d",&n),n){
		bool found = false;
		int ans1,ans2;
		for(i=0;prime[i]*2<=n;i++){
			int bil1 = prime[i], bil2 = n-prime[i];
			if(isprime[bil2]){found = true; ans1 = bil1; ans2 = bil2; break;}
		}
		printf("%d:\n",n);
		if(!found){printf("NO WAY!\n");}
		else{printf("%d+%d\n",ans1,ans2);}
	}
	return 0;
}