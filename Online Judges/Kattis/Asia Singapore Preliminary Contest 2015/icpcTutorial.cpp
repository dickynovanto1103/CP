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

int main(){
	ll m,n,t;
	scanf("%lld %lld %lld",&m,&n,&t);
	ll jumlah = 0;
	ll i,j;
	// printf("m: %lld n: %lld t: %lld\n", m,n,t);
	if(t==1){
		ll komputasi = 1;
		for(i=n;i>=1;i--){
			komputasi*=i;
			if(komputasi>m){printf("TLE\n"); return 0;}
		}
	}else if(t==2){
		ll komputasi = 1;
		for(i=n;i>=1;i--){
			komputasi*=2LL;
			if(komputasi>m){printf("TLE\n"); return 0;}
		}
	}else if(t==3){
		ll komputasi = 1;
		for(i=1;i<=4;i++){
			komputasi*=n;
			if(komputasi>m){printf("TLE\n"); return 0;}
		}
	}else if(t==4){
		ll komputasi = 1;
		for(i=1;i<=3;i++){
			komputasi*=n;
			if(komputasi>m){printf("TLE\n"); return 0;}
		}
	}else if(t==5){
		ll komputasi = 1;
		for(i=1;i<=2;i++){
			komputasi*=n;
			if(komputasi>m){printf("TLE\n"); return 0;}
		}
		// printf("komputasi: %lld\n",komputasi);
	}else if(t==6){
		double komputasi = (double)n*log(n)/log(2LL);
		if(komputasi>(double)m){printf("TLE\n"); return 0;}
	}else{
		if(n>m){printf("TLE\n"); return 0;}
	}
	printf("AC\n");
	
	
	return 0;
};