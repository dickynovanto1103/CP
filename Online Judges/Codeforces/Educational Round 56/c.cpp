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

const int maxn = 2e5 + 5;

ll b[maxn];
ll a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n/2;i++){
		scanf("%lld",&b[i]);
	}

	int kiri = n/2 - 1, kanan = kiri+1;
	ll elemen = b[n/2-1];
	a[kiri] = elemen/2LL;
	if(elemen%2LL == 1){
		a[kanan] = elemen/2LL + 1LL;
	}else{
		a[kanan] = elemen/2LL;
	}
	// printf("a[%d]: %lld a[%d]: %lld\n",kiri,a[kiri], kanan, a[kanan]);
	ll lastKiri = a[kiri], lastKanan = a[kanan];
	kiri--; kanan++;
	for(i=n/2-2;i>=0;i--){
		ll elemen = b[i];
		ll bilanganKiri = lastKiri, bilanganKanan = elemen-lastKiri;
		if(bilanganKiri <= lastKiri && bilanganKanan >= lastKanan){
			a[kiri] = bilanganKiri;
			a[kanan] = bilanganKanan;
			lastKiri = a[kiri]; lastKanan = a[kanan];
			kiri--; kanan++;
			continue;
		}
		bilanganKanan = lastKanan;
		bilanganKiri = elemen - bilanganKanan;
		if(bilanganKiri <= lastKiri && bilanganKanan >= lastKanan){
			a[kiri] = bilanganKiri;
			a[kanan] = bilanganKanan;
			lastKiri = a[kiri]; lastKanan = a[kanan];
			kiri--; kanan++;
			continue;
		}
		
		kiri--; kanan++;
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%lld",a[i]);
	}
	printf("\n");
	return 0;
};