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

const int maxn = 2e5 + 5;

int bit[maxn];

void update(int idx, int val){
	for(int i=idx;i<maxn;i+=(i&-i)){
		bit[i] += val;
	}
}

int query(int idx){
	int sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		sum += bit[i];
	}
	return sum;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int nilai[maxn], idx[maxn];
	while(tc--){
		memset(bit, 0, sizeof bit);
		memset(nilai, -1, sizeof nilai);
		memset(idx, -1, sizeof idx);
		int n,m;
		scanf("%d %d",&n,&m);
		int idxAwal = 100001;
		for(i=idxAwal;i<idxAwal + n;i++){
			nilai[i] = i-idxAwal+1;
			idx[i-idxAwal+1] = i;
		}
		for(i=0;i<m;i++){
			int a;
			scanf("%d",&a);
			// printf("a: %d\n",a);
			int indeks = idx[a];
			// printf("indeks: %d\n",indeks);
			int kiri = 0, kanan = indeks-1, mid, ans;
			// printf("i: %d\n",i);
			while(kiri <= kanan){
				mid = (kiri + kanan)/2;
				if(nilai[mid] == -1){
					ans = mid;
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}
			// printf("ans: %d\n",ans);
			int banyak = indeks - ans -1;
			// printf("banyakSementara: %d\n",banyak);
			//tentukan banyak 0
			int banyak0 = query(indeks-1);
			// printf("banyak0: %d\n", banyak0);
			if(i){printf(" ");}
			printf("%d",banyak - banyak0);
			update(indeks, 1);
			nilai[ans] = a;
			idx[a] = ans;
			// printf("nilai[%d] jadi: %d dan idx[%d] jadi: %d\n",ans, a, a, ans);
		}
		printf("\n");

	}
	return 0;
};