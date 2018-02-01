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

const int maxn = 100001;

bool isprime[maxn];
int prime[9600];
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

int main(){
	int n,i,j,tc;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	scanf("%d",&tc);
	int ans=0;
	while(tc--){
		scanf("%d",&n);
		ans=0;
		for(i=0;i<cnt;i++){
			if(prime[i]<=n){
				//printf("yang diambil: %d\n",prime[i]);
				ans++;
			}
		}
		if(ans%2==0){printf("Bob\n");}
		else{printf("Alice\n");}
	}
	return 0;
};