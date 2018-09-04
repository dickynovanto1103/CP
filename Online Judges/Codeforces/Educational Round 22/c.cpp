#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000LL
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

const int maxn = 5e3 + 3;

ll pref[maxn];

ll hitung(int l, int r){
	r--;
	if(l>r){return 0;}
	if(l == 0){return pref[r];}
	return pref[r] - pref[l-1];
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		pref[i] = a[i];
	}

	for(i=1;i<n;i++){
		pref[i] += pref[i-1];
		// printf("pref[%d]: %lld\n",i,pref[i]);
	}
	ll ans = -inf;
	int jawaban[3];
	for(i=0;i<=n;i++){
		ll maks1 = -inf;
		// printf("i: %d\n",i);
		int idx1, idx2;
		for(j=0;j<=i;j++){
			// printf("j: %d\n",j);
			//cari batas 1
			ll jawab1 = hitung(0,j);
			ll jawab2 = hitung(j,i);
			ll jawab = jawab1 - jawab2;
			if(maks1 < jawab){
				// printf("jawab1: %lld jawab2: %lld jawab: %lld jawaban0: %d\n",jawab1,jawab2,jawab,j);
				// jawaban[0] = j;
				idx1 = j;
				maks1 = jawab;
			}
		}
		ll maks2 = -inf;
		for(j=i;j<=n;j++){
			// printf("j: %d\n",j);
			//cari batas 2
			ll jawab1 = hitung(i,j);
			ll jawab2 = hitung(j,n);
			ll jawab = jawab1 - jawab2;
			if(maks2 < jawab){
				// printf("jawab1: %lld jawab2: %lld jawab: %lld jawaban2: %d\n",jawab1,jawab2,jawab,j);
				maks2 = jawab;
				idx2 = j;
				// jawaban[2] = j;
			}
		}

		if(ans < (maks1 + maks2)){

			jawaban[1] = i;
			ans = maks1 + maks2;
			jawaban[0] = idx1;
			jawaban[2] = idx2;
			// printf("maks1: %lld maks2: %lld ans: %lld jawaban1: %d\n",maks1,maks2,ans,i);
		}
	}
	for(i=0;i<3;i++){
		if(i){printf(" ");}
		printf("%d",jawaban[i]);
	}
	printf("\n");
	return 0;
};