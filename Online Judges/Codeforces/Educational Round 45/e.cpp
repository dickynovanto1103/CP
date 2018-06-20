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

const int maxn = 1e6 + 6;

bool isFillable[maxn];
ll biaya[maxn];
int idxSebelum[maxn];

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	memset(isFillable, true,sizeof isFillable);
	for(i=0;i<m;i++){
		int idx;
		scanf("%d",&idx);
		if(idx==0){
			printf("-1\n");
			return 0;
		}
		isFillable[idx] = false;
	}
	isFillable[n] = false;

	for(i=0;i<k;i++){
		scanf("%lld",&biaya[i]);
	}

	//cek maksimal lebar
	int sebelum = 0;
	int cntMaks = 0;
	int cnt = 0;
	for(i=0;i<n;i++){
		if(isFillable[i]) {
			cntMaks = max(cntMaks, cnt);
			cnt = 0;
			sebelum = i;
		}else{
			cnt++;
			idxSebelum[i] = sebelum;
		}
	}
	idxSebelum[n] = sebelum;
	cntMaks = max(cntMaks, cnt);

	cntMaks++;
	// printf("cntMaks: %d\n",cntMaks);
	if(cntMaks>k){
		printf("-1\n");
	}else{
		int idx = cntMaks;
		
		ll minim = (ll)inf*10000LL;
		// printf("idx: %d\n",idx);
		for(i=idx;i<=k;i++){
			int cur = 0;
			bool isBackToBefore = false;
			// printf("i: %d\n",i);
			int j = 0;
			ll total = 0;
			while(j<n) {
				j+=i;
				total+=biaya[i-1];
				// printf("biaya[%d]: %lld\n",i-1,biaya[i-1]);
				// printf("total jd: %lld\n",total);
				if(j>=n){break;}
				if(!isFillable[j]){
					j = idxSebelum[j];
					if(j==cur){
						isBackToBefore = true;
						break;
					}
				}
			}
			if(isBackToBefore){continue;}
			minim = min(minim, total);
		}
		printf("%lld\n",minim);
	}


	return 0;
};