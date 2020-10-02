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

// string numToBinary(int n, int digits) {
// 	string s;
// 	while(n){
// 		int bil = n % 2;
// 		n /= 2;
// 		s += (bil + '0');
// 	}
// 	while(s.size() < digits){
// 		s += '0';
// 	}
// 	reverse(s.begin(), s.end());
// 	return s;
// }

ll computeInv(const vi& a) {
	int sz = a.size();
	int suff[sz+1],i;
	suff[sz] = 0;
	for(i=sz-1;i>=0;i--){
		suff[i] = suff[i+1];
		if(a[i] == 0){suff[i]++;}
	}

	ll ans = 0;
	for(i=0;i<sz;i++){
		if(a[i] == 1){
			ans += suff[i+1];
		}
	}
	return ans;
}

void cetak(const vi& a){
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int n,i,j;
	int a[300001];
	while(scanf("%d",&n)!=EOF){
		// printf("HALOOO\n\n\n\n\n");
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);	
		}
		vii groups;
		groups.pb(ii(0, n-1));
		ll sor = 0;
		ll numInv = 0;
		for(i=31;i>=0;i--){
			ll invXor = 0;
			ll invOri = 0;
			for(j=0;j<groups.size();j++){
				ii range = groups[j];
				int awal = range.first, akhir = range.second;
				vi inv, asli;
				for(int k=awal;k<=akhir;k++){
					if((1LL<<i) & a[k]) {
						asli.pb(1); inv.pb(0);
					}else{
						asli.pb(0); inv.pb(1);
					}
				}
				// printf("awal: %d akhir: %d i: %d j: %d\n",awal, akhir, i, j);
				// printf("asli\n");
				// cetak(asli);
				// printf("inv\n");
				// cetak(inv);

				// printf("computeInv asli: %d\n", computeInv(asli));
				// printf("computeInv inv: %d\n", computeInv(inv));
				invOri += computeInv(asli);
				invXor += computeInv(inv);
			}
			//if invXor < invOri, then do inverse, else, don't do inverse

			if(invXor < invOri){
				sor += (1LL<<i);
				
				for(j=0;j<n;j++){
					a[j] ^= (1LL<<i);
				}

				numInv += invXor;
			}else{
				numInv += invOri;
			}

			vii newGroups;
			for(j=0;j<groups.size();j++){
				ii range = groups[j];
				int awal = range.first, akhir = range.second;
				// printf("awal: %d akhir: %d\n",awal, akhir);
				int cur = -1;
				int start = awal, end = awal;
				for(int k=awal;k<=akhir;k++){
					int nilai;
					if((1LL<<i) & a[k]) {
						nilai = 1;
					}else{
						nilai = 0;
					}
					// printf("k: %d nilai: %d cur: %d\n",k, nilai, cur);
					if(nilai != cur && cur != -1) {
						newGroups.pb(ii(start, end));
						// printf("k: %d push newgroups di tengah: %d %d\n",k, start, end);
						start = k, end = k;
					}else{
						end = k;
					}
					cur = nilai;
				}
				newGroups.pb(ii(start, end));
				// printf("push newgroups: %d %d\n",start, end);
			}
			groups.clear();
			groups = newGroups;


		}
		printf("%lld %lld\n",numInv, sor);
	}
	
	
	return 0;
};