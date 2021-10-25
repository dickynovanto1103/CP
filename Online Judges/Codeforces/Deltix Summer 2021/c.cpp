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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int a[1010];
	while(scanf("%d",&n) != EOF) {
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		ll ans = 0;
		
		for(i=0;i<(n-1);i+=2){
			vi list;

			debug printf("i: %d\n\n\n", i);

			for(j=i;j<(n-1);j+=2) {
				list.pb(a[j]);
				int numKurungTutup = a[j+1];

				debug printf("j: %d push: %d numKurungTutup: %d\n", j, a[j], numKurungTutup);
				bool done = false;

				while(numKurungTutup > 0 && list.size() > 0) {
					int numOfKurungBukaTerakhir = list.back();
					debug printf("numOfKurungBukaTerakhir: %d\n", numOfKurungBukaTerakhir);
					
					list.pop_back();
					
					int pengurangan = min(numKurungTutup, numOfKurungBukaTerakhir);
					numKurungTutup -= pengurangan;
					numOfKurungBukaTerakhir -= pengurangan;

					debug printf("pengurangan: %d numKurungTutup now: %d numOfKurungBukaTerakhir now: %d\n", pengurangan, numKurungTutup, numOfKurungBukaTerakhir);
					debug printf("len list: %d\n", list.size());

					if(list.size() == 1) {
						if(numOfKurungBukaTerakhir == 0) {
							ans++; //memperpanjang subsegment dari index i
							debug printf("ans now perpanjang segment: %lld\n", ans);
						}else{
							list.pb(numOfKurungBukaTerakhir);
						}
					}else if(list.size() == 0){
						ans += pengurangan;
						debug printf("ans now: %lld numKurungTutup: %d\n", ans, numKurungTutup);
						if(numKurungTutup > 0) {
							done = true;
							break; //cukup, ga bs lanjut karena ga bs bikin more subsegment dari index i
						}else{
							//berarti numOfKurungBukaTerakhir >= 0
							debug printf("push here?\n");
							list.pb(numOfKurungBukaTerakhir);
							
						}
					}else{
						if(numOfKurungBukaTerakhir > 0) {
							list.pb(numOfKurungBukaTerakhir);
						}
					}
				}

				if(done){
					break;
				}	
			}

			
		}

		printf("%lld\n", ans);
	}
	
	return 0;
};