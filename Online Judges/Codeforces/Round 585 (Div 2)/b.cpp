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

const int maxn = 2e5 + 5;

int a[maxn];
int pref[maxn];
int pos[maxn];
int genap[maxn], ganjil[maxn];;

int main(){
	int n,i,j;

	while(scanf("%d",&n) !=EOF){

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			pref[i] = 0;
			
			if(a[i] < 0){
				pref[i] = 1;
				ganjil[i] = 1;
			}else{
				genap[i] = 1;
			}
			if(i){
				pref[i] += pref[i-1];
			}
		}
		for(i=0;i<n;i++){
			genap[i] = 0;
			ganjil[i] = 0;
			if(pref[i] % 2 == 0){
				genap[i] = 1;
			}else{
				ganjil[i] = 1;
			}
			genap[i] += genap[i-1];
			ganjil[i] += ganjil[i-1];
			debug printf("pref[%d]: %d\n",i, pref[i]);
		}
		// for(i=0;i<n;i++){
		// 	debug printf("genap[%d]: %d\n",i, genap[i]);
		// }
		int cntNeg = 0;
		ll ansPos = 0, ansNeg = 0;
		for(i=0;i<n;i++){
			if(cntNeg%2 == 0){
				//butuh genap juga
				int banyakGenap = genap[n-1] - (i == 0 ? 0 : genap[i-1]);
				int banyakGanjil = ganjil[n-1] - (i == 0 ? 0 : ganjil[i-1]);
				ansPos += banyakGenap;
				ansNeg += banyakGanjil;
				debug printf("banyakGenap: %d ans jd: %lld\n",banyakGenap, ansPos);
			}else{
				int banyakGenap = genap[n-1] - (i == 0 ? 0 : genap[i-1]);
				int banyakGanjil = ganjil[n-1] - (i == 0 ? 0 : ganjil[i-1]);
				ansPos += banyakGanjil;
				ansNeg += banyakGenap;
				debug printf("banyakGanjil: %d ans jd: %lld\n",banyakGanjil, ansPos);
			}
			if(a[i] < 0) {
				cntNeg++;
			}
		}
		printf("%lld %lld\n",ansNeg, ansPos);
	}
	return 0;
};