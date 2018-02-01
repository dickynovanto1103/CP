#include <bits/stdc++.h>

using namespace std;
#define inf 1000000;
typedef long long ll;

int main(){
	int tc,i;
	ll n;
	map<ll,int> mapper;
	map<ll,int>::iterator it;
	scanf("%d",&tc);
	/*for(i=0; i<=1000;i++){
		//jalanin formula
		int temp = i;

		double hasilRoot = sqrt((double)temp);
		ll hasil = (ll)floor((hasilRoot - floor(hasilRoot))*1000000000.0);
		printf("hasil: %lld i: %d\n",hasil,i);
		//if(hasil==n){printf("%d\n",i); break;}
	}*/
	while(tc--){
		scanf("%lld",&n);
		//cari nilai x make binsearch
		double frac = (double)n / 1000000000000000000.0;
		double test;
		for(i=1;i<=1000000000;i++){
			int temp = i;
			test = frac+(double)temp;
			printf("test: %lf\n",test);
			double kuad = test*test;
			printf("kuad: %lf\n",kuad);
			ll coba = (ll)round(kuad);
			printf("coba: %lld\n",coba);
			ll cobalagi = coba;
			double hasilRoot = sqrt((double)cobalagi);
			ll hasil = (ll)floor((hasilRoot - floor(hasilRoot))*1000000000000000000);
			printf("hasil: %lld n: %lld\n",hasil,n);
			//printf("hasil: %lld\n",hasil);
			if(hasil==(ll)n){
					printf("ketemu hasilnya:\n");
					printf("%lld\n",coba); break;	
				
				
			}
		}
		
	}
		
		

	
	return 0;
}
/*
0
983866769
622776601
606961258
#include <bits/stdc++.h>

using namespace std;
#define inf 1000000;
typedef long long ll;

int main(){
	int tc,i;
	ll n;
	map<ll,int> mapper;
	map<ll,int>::iterator it;
	scanf("%d",&tc);
	/*for(i=0; i<=1000;i++){
		//jalanin formula
		int temp = i;

		double hasilRoot = sqrt((double)temp);
		ll hasil = (ll)floor((hasilRoot - floor(hasilRoot))*1000000000.0);
		printf("hasil: %lld i: %d\n",hasil,i);
		//if(hasil==n){printf("%d\n",i); break;}
	}*/
	/*while(tc--){
		scanf("%lld",&n);
		//cari nilai x make binsearch
		it= mapper.find(n);
		if(it!=mapper.end()){
			printf("%d\n",mapper[n]);
		}else{
			for(i=1; i<=1000000000;i++){
			//jalanin formula
				int temp = i;

				double hasilRoot = sqrt((double)temp);
				ll hasil = (ll)floor((hasilRoot - floor(hasilRoot))*1000000000.0);
				//printf("hasil: %lld\n",hasil);
				it = mapper.find(hasil);
				if(it==mapper.end()){mapper[hasil] = i;}
				if(hasil==n){
					if(i!=0){
						printf("%d\n",i); break;	
					}
					
				}
			}	
		}
		
	}
		
		

	
	return 0;
}
*/