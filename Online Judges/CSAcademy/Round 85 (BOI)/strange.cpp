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

const int maxn = 100000;
bool isprime[maxn + 4];
int prime[10000];

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

int cnt[4];
bool isValid;

void factorize(ll n){
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf*pf<=n){
		while(n%pf==0){
			n/=pf;
			cnt[pf]++;
		}
		pf_idx++;
		pf = prime[pf_idx];
	}
	if(n!=1){
		if(n==2 || n==3){
			cnt[n]++;
		}else{
			isValid = false;
		}
	}
}

struct pasangan{
	int bil, jumlah2, jumlah3;
};

bool cmp(pasangan a, pasangan b){
	if(a.jumlah2 == b.jumlah2){return a.jumlah3 < b.jumlah3;}
	return a.jumlah2 > b.jumlah2;
}

int main(){
	memset(isprime, true, sizeof isprime);
	int cntPrime = 0;
	sieve(maxn);
	int i,j;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cntPrime] = i;
			cntPrime++;
		}
	}

	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	memset(cnt, 0, sizeof cnt);
	isValid = true;
	factorize(a);

	int jumlah2[55], jumlah3[55];
	jumlah2[0] = cnt[2]; jumlah3[0] = cnt[3];

	memset(cnt, 0, sizeof cnt);
	factorize(b);
	jumlah2[1] = cnt[2]; jumlah3[1] = cnt[3];
	pasangan pas[55];
	int arr[51];
	for(i=0;i<n;i++){
		int idx = i+2;
		scanf("%d",&arr[i]);
		memset(cnt, 0, sizeof cnt);
		factorize(arr[i]);
		jumlah2[idx] = cnt[2]; jumlah3[idx] = cnt[3];
		pas[i].bil = arr[i]; pas[i].jumlah2 = jumlah2[idx]; pas[i].jumlah3 = jumlah3[idx];
	}

	// for(i=0;i<n+2;i++){
	// 	printf("jumlah2[%d]: %d jumlah3[%d]: %d\n",i,jumlah2[i],i,jumlah3[i]);
	// }

	if(n==0){
		if(!isValid){printf("-1\n"); return 0;}

		if(a == b){isValid = false;}
		else{
			if(jumlah2[0] >= jumlah2[1] && jumlah3[0] <= jumlah3[1]){
				printf("%d",a);
				int node = a;
				int selisih2 = abs(jumlah2[0] - jumlah2[1]), selisih3 = abs(jumlah3[1] - jumlah3[0]);
				// printf("selisih2: %d selisih3: %d\n",selisih2,selisih3);
				while(selisih2>0){
					printf(" %d",node/2);
					node/=2;
					selisih2--;
				}
				while(selisih3>0){
					printf(" %d",node*3);
					node*=3;
					selisih3--;
				}
				printf("\n");
				return 0;
			}else{
				isValid = false;
			}
			
		}
	}else{
		sort(pas, pas+n, cmp);

		if(a == pas[0].bil){isValid = false;}
		else{
			if(jumlah2[0] >= pas[0].jumlah2 && jumlah3[0] <= pas[0].jumlah3){

			}else{
				isValid = false;
			}
		}

		if(b == pas[n-1].bil){isValid = false;}
		else{
			if(jumlah2[1] <= pas[n-1].jumlah2 && jumlah3[1] >= pas[n-1].jumlah3){

			}else{
				isValid = false;
			}
		}

		// for(i=0;i<n;i++){
		// 	printf("pas[%d].bil: %d pas[%d].jumlah2: %d pas[%d].jumlah3: %d\n",i,pas[i].bil,i,pas[i].jumlah2,i,pas[i].jumlah3);
		// }

		for(i=0;i<(n-1);i++){
			if(pas[i].bil == pas[i+1].bil){isValid =false;}
			else{
				if(pas[i].jumlah2 >= pas[i+1].jumlah2 && jumlah3[i] <= pas[i+1].jumlah3){

				}else{
					isValid = false;
				}
			}
		}	
	}

	

	if(!isValid){printf("-1\n"); return 0;}
	else{
		pas[n].bil = b; pas[n].jumlah2 = jumlah2[1]; pas[n].jumlah3 = jumlah3[1];
		// printf("awal pas[%d].jumlah2: %d pas[%d].jumlah3: %d\n",n,pas[n].jumlah2,n,pas[n].jumlah3);
		printf("%d",a);
		int node = a;

		int selisih2 = abs(pas[0].jumlah2 - jumlah2[0]), selisih3 = abs(pas[0].jumlah3 - jumlah3[0]);
		// printf("selisih2: %d selisih3: %d\n",selisih2,selisih3);
		while(selisih2>0){
			printf(" %d",node/2);
			node/=2;
			selisih2--;
		}
		while(selisih3>0){
			printf(" %d",node*3);
			node*=3;
			selisih3--;
		}

		for(i=0;i<n;i++){
			selisih2 = abs(pas[i].jumlah2 - pas[i+1].jumlah2), selisih3 = abs(pas[i].jumlah3 - pas[i+1].jumlah3);
			// printf("i: %d selisih2: %d selisih3: %d\n",i,selisih2,selisih3);
			while(selisih2>0){
				printf(" %d",node/2);
				node/=2;
				selisih2--;
			}
			while(selisih3>0){
				printf(" %d",node*3);
				node*=3;
				selisih3--;
			}
			
		}
		printf("\n");	
	}


	return 0;
};