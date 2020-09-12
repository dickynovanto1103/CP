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

int a[100001];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);

		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a, a+n);
		vi listPos, list0, listNeg;
		int cnt0 = 0;
		for(i=0;i<n;i++){
			if(a[i] < 0){listNeg.pb(a[i]);}
			else if(a[i] > 0){listPos.pb(a[i]);}
			else {cnt0++;}
		}
		
		if(n == 5){
			ll ans = 1;
			for(i=0;i<n;i++){
				ans *= a[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		//ambil 5 positif

		//ambil 3 positif 2 negatif

		//ambil 1 positif 4 negatif

		//ambil 5 negatif

		//klo 2 positif, berarti ada at least 4 negatif

		//klo 1 positif, berarti ada at least 5 negatif

		//klo 4 positif, berarti at least ada 2 negatif
		reverse(listPos.begin(), listPos.end());
		ll maks = -1LL*(ll)inf*inf;
		// printf("%lld\n",maks);
		if(listPos.size() >= 5) {
			ll ans = 1;
			for(i=0;i<5;i++){
				ans *= listPos[i];
			}
			maks = max(maks, ans);
		} 

		if(listPos.size() >= 3) {
			//ambil 2 negatif terkecil, ambil 3 positif terbesar
			if(listNeg.size() >= 2){
				ll ans = listNeg[0] * listNeg[1];
				for(i=0;i<3;i++){
					ans *= listPos[i];
				}
				maks = max(maks, ans);
			}
		}

		if(listPos.size() >= 1) {
			//ambil 4 negatif terkecil, ambil 1 positif
			if(listNeg.size() >= 4) {
				ll ans = listPos[0];
				for(i=0;i<4;i++){
					ans *= listNeg[i];
				}
				maks = max(maks, ans);
			}
			

		}

		if(listPos.size() >= 0) {
			// printf("halo maks; %lld\n",maks);
			//ambil 5 negatif terkecil
			if(cnt0){maks = max(maks, 0LL);}
			else{
				if(listNeg.size() >= 5){
					ll ans = 1;
					reverse(listNeg.begin(), listNeg.end());
					for(i=0;i<5;i++){
						ans *= listNeg[i];
					}
					maks = max(maks, ans);
				}	
			}
			
		}
		printf("%lld\n",maks);
	}
	
	return 0;
};