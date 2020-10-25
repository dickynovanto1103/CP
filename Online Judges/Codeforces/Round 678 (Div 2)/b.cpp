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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5;

bool isprime[maxn + 4];
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

int main(){
	int tc,i,j,n;
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	// printf("%d\n",cnt);
	scanf("%d",&tc);
	int a[102][102];

	while(tc--){
		scanf("%d",&n);

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j] = 1;
			}
		}
		if(!isprime[n]){
			int jawab = -1;
			for(i=0;i<cnt;i++){
				int p = prime[i];
				if(p < n) {
					continue;
				}
				int selisih = p - (n-1);
				if(!isprime[selisih]){
					jawab = selisih;
					break;
				}
			}

			assert(jawab != -1);
			for(i=0;i<n;i++){
				a[i][i] = jawab;
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}

		
	}
	
	return 0;
};