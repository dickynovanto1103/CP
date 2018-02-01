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

const int maxn = 3e5  +10;
ll sum[maxn];

void cetakKurung(int n){
	int i;
	for(i=0;i<n;i++){printf("(");}
	for(i=0;i<n;i++){printf(")");}
}

int main(){
	ll n,k;
	
	scanf("%lld %lld",&n,&k);

	for(ll i=0;i<=n;i++){
		sum[i] = (((i)*(i-1))/2);
		
	}
	// printf("sum:\n");
	// for(int i=1;i<=n;i++){
	// 	printf("%lld\n",sum[i]);
	// }
	vi listAngka;
	int i;
	
	int sisa = n;
	int sisa1 = n;
	
	for(i=n;i>=0;i--){
		//printf("sum[%d]: %lld\n",i,sum[i]);
		if(sisa1<i){continue;}
		while(sum[i]<=k){
			//printf("k: %lld sum[%d]: %lld\n",k,i,sum[i]);
			k-=sum[i]; listAngka.pb(i);
			sisa1-=i;
			if(sisa1<=0){break;}
			if(k<=0){break;}
		}
		
	}
	if(k>0){printf("Impossible\n"); return 0;}
	if(sisa1<0){printf("Impossible\n"); return 0;}
	for(i=0;i<listAngka.size();i++){
		if(sisa==0){break;}
		cetakKurung(listAngka[i]);

		sisa-=listAngka[i];
	}
	while(sisa>0){
		cetakKurung(1);
		sisa--;
	}
	printf("\n");
	return 0;
};