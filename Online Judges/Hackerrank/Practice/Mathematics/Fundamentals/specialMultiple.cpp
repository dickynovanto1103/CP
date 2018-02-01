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

bool isDivisibleByN(ll n, ll bil){
	vi listBil;
	ll i;
	
	for(i=0;;i++){
		if((1LL<<i)>bil){break;}
		if((1LL<<i)&bil){
			//printf("1\n");
			listBil.pb(9);
		}
		else{
			//printf("0\n");
			listBil.pb(0);
		}
	}
	int ukuran = listBil.size();
	ll angka = 0;
	// if(bil==1){
	// 	printf("n: %lld bil: %lld\n",n,bil);
	// 	printf("ukuran: %d\n",ukuran);	
	// }
	
	for(i=ukuran-1;i>=0;i--){
		angka*=10;
		angka+=listBil[i];
		angka%=n;
		//if(bil==1){printf("angka: %lld\n",angka);}
		//printf("angka sekarang: %d ukuran: %d bil: %lld",listBil[i],ukuran,bil);
	}
	//if(bil==1){printf("masuk sini dan angka: %lld\n",angka);}
	return angka==0;
}
void printAnswer(ll bil){
	int i;
	vi listBil;
	for(i=0;;i++){
		if((1LL<<i)>bil){break;}
		if((1LL<<i)&bil){
			//printf("1\n");
			listBil.pb(9);
		}
		else{
			//printf("0\n");
			listBil.pb(0);
		}
	}
	int ukuran = listBil.size();
	for(i=ukuran-1;i>=0;i--){
		printf("%d",listBil[i]);
	}
	printf("\n");
}

int main(){
	ll tc,n,i,j;
	ll ans[501];
	
	for(i=1;i<=500;i++){
		//printf("i: %lld\n",i);
		for(j=1;;j++){
			if(isDivisibleByN(i,j)){ans[i] = j; break;}
		}
	}
	scanf("%lld",&tc);
	while(tc--){
		scanf("%lld",&n);
		
		printAnswer(ans[n]);
		
	}
	return 0;
};