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

string numToBinary(int n, int digits) {
	string s;
	while(n){
		int bil = n % 2;
		n /= 2;
		s += (bil + '0');
	}
	while(s.size() < digits){
		s += '0';
	}
	reverse(s.begin(), s.end());
	return s;
}

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
		// printf("HALOOO\n");
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			// cout<<numToBinary(a[i], 7)<<endl;
		}
		vector<vi> groups;
		vi awalMula;
		for(i=0;i<n;i++){awalMula.pb(i);}
		groups.pb(awalMula);

		int sor = 0;
		ll numInv = 0;
		for(i=29;i>=0;i--){
			ll invXor = 0;
			ll invOri = 0;
			for(j=0;j<groups.size();j++){
				vi inv, asli;
				// printf("group %d\n",j);
				for(int k=0;k<groups[j].size();k++){
					int idx = groups[j][k];
					// printf("idx: %d\n",idx);
					if((1<<i) & a[idx]) {
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
				sor += (1<<i);
				
				for(j=0;j<n;j++){
					a[j] ^= (1LL<<i);
				}

				numInv += invXor;
				// printf("numInv tambah invXor: %lld jadi: %lld\n",invXor, numInv);
				// printf("sor value ditambah %lld jadi: %lld\n",1LL<<i, sor);
			}else{
				numInv += invOri;
				// printf("numInv tambah invOri: %lld jadi: %lld\n",invOri, numInv);
			}

			vector<vi> newGroups;
			for(j=0;j<groups.size();j++){
				vi group0, group1;
				for(int k=0;k<groups[j].size();k++){
					int idx = groups[j][k];
					int nilai;
					if((1<<i) & a[idx]) {
						group1.pb(idx);
					}else{
						group0.pb(idx);
					}
				}
				if(group1.size()){
					newGroups.pb(group1);	
				}
				if(group0.size()){
				 	newGroups.pb(group0);
				}
			}
			groups = newGroups;


		}
		printf("%lld %d\n",numInv, sor);
	}
	
	
	return 0;
};