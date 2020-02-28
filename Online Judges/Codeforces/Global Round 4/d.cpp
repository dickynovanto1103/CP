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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[1000001];
int prime[1000000];
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
	int n,i,j;

	int maks = 1000*999/2;
	memset(isprime, true, sizeof isprime);
	sieve(maks);
	int cnt = 0;
	for(i=0;i<=maks;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	scanf("%d",&n);
	vii edge;
	for(i=1;i<n;i++){
		edge.pb(ii(i, i+1));
	}
	edge.pb(ii(1,n));
	int banyak = n;
	int idx = lower_bound(prime, prime+cnt, banyak) - prime;
	int prima = prime[idx];
	int selisih = prima - banyak;
	// int kiri = 2, kanan = n-1;
	for(i=1;i<=n;i+=4){
		if(!selisih){break;}
		edge.pb(ii(i,i+2));
		selisih--;
		if(!selisih){break;}
		edge.pb(ii(i+1, i+3));
		selisih--;
		if(!selisih){break;}
	}
	printf("%d\n",(int)edge.size());
	for(i=0;i<edge.size();i++){
		printf("%d %d\n",edge[i].first, edge[i].second);
	}
	// for(i=0;i<(cnt-1);i++){
	// 	int jarak = prime[i+1] - prime[i];
	// 	int tambah = prime[i]/2 - 1;

	// 	if(jarak > tambah){
	// 		printf("jarak: %d tambah: %d\n",jarak, tambah);
	// 		printf("prime[%d]: %d\n",i,prime[i]);
	// 	}else{
	// 		// printf("jarak: %d prime: %d tambah: %d\n",jarak, prime[i], tambah);
	// 	}
	// }
	return 0;
};