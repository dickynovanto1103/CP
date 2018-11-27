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

const int maxn = 3e5 + 5;

ll a[maxn], b[maxn];
ll prefA[maxn], prefB[maxn];

int main(){
	int n,m,i,j;
	
	
	scanf("%d",&n);
	ll sum1 = 0, sum2 = 0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]); sum1+= a[i];
		prefA[i] = prefA[i-1] + a[i];
	}

	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%lld",&b[i]); sum2 += b[i];
		prefB[i] = prefB[i-1] + b[i];
	}
	if(sum1 != sum2){
		printf("-1\n");
		return 0;
	}

	int idx1 = 1, idx2 = 1;
	int iterasi = 0;
	while(!(idx1 == (n+1) && idx2 == (m+1))){
		int bil1 = a[idx1], bil2 = b[idx2];
		// printf("idx1: %d idx2: %d bil1: %d bil2: %d\n",idx1,idx2,bil1,bil2);
		if(bil1 == bil2){
			idx1++; idx2++;
		}else{
			if(bil1 < bil2){
				//nanti yang a harus dimerge dengan sebelahnya
				for(i=idx1+1;i<=n;i++){
					ll dicari = prefA[i] - prefA[idx1-1];
					// printf("dicari: %lld\n",dicari);
					//cari di b
					ll idxDi2 = lower_bound(prefB+1, prefB+m+1, dicari+prefB[idx2-1]) - prefB;

					if(prefB[idxDi2] == (dicari + prefB[idx2-1])){
						//ketemu
						idx2 = idxDi2;
						idx1 = i;
						// printf("idx2 jadi: %d\n",idx2);
						break;
					}
					

				}
				idx1++; idx2++;
				// printf("idx1: %d idx2: %d prefB[%d]: %lld \n",idx1,idx2,idx2-1, prefB[idx2-1]);
				// break;
			}else{
				for(i=idx2+1;i<=m;i++){
					ll dicari = prefB[i] - prefB[idx2 - 1];
					//cari di prefA
					ll idxDi1 = lower_bound(prefA+1, prefA + n+1, dicari+prefA[idx1-1]) - prefA;
					if(prefA[idxDi1] == (dicari + prefA[idx1 - 1])){
						//ketemu
						idx1 = idxDi1;
						idx2 = i;
						// printf("idx1 jadi: %d idx2 jadi: %d\n",idx1,idx2);
						break;
					}
				}
				idx1++; idx2++;
				// printf("idx1: %d idx2: %d prefA[%d]: %lld \n",idx1,idx2,idx1-1, prefA[idx1-1]);
				// break;
			}	
		}
		iterasi++;
	}
	printf("%d\n", iterasi);
	return 0;
};