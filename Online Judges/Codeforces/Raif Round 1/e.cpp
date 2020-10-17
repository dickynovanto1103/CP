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
int cnt[1000001];
int temp[1000001];

bool can(int mid, int n, int k) {
	int banyak = n;
	for(int i=0;i<n;i++){
		if(a[i] > mid){
			int bagi = (a[i] + mid - 1) / mid;
			banyak--;
			banyak+=bagi;
		}
	}
	return banyak <= k;
}

ll hit() {
	ll ans = 0;
	for(int i=1;i<=1000000;i++){
		ans += ((ll)cnt[i]*(ll)i*(ll)i);
	}
	return ans;
}

int main(){
	int n,k,i,j;
	while(scanf("%d %d",&n,&k) != EOF) {
		priority_queue<int> pq;
		int minim = inf, maks = 0;
		for(i=0;i<=1000000;i++){
			cnt[i] = 0;
			temp[i] = 0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			minim = min(minim, a[i]); maks = max(maks, a[i]);
		}
		int kiri = 1, kanan = maks, mid, ans;
		// printf("kiri: %d kanan: %d\n",kiri, kanan);
		while(kiri <= kanan) {
			mid = (kiri + kanan)/2;
			if(can(mid, n, k)){
				ans = mid;
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		printf("ans: %d\n",ans);

		for(i=0;i<n;i++){
			if(a[i] >= ans){
				if(a[i] % ans == 0){
					int banyak = a[i] / ans;
					int bil = ans;
					cnt[bil] += banyak;
				}else{
					int banyak = a[i] / ans;
					int sisa = a[i] % ans;
					cnt[ans] += banyak;
					cnt[sisa]++;
					printf("ans: %d banyak: %d sisa: %d\n",ans, banyak, sisa);
				}
			}else{
				temp[a[i]]++;
				cnt[a[i]]++;
			}
		}
		int total = 0;
		for(i=1;i<=maks;i++){
			total += cnt[i];
		}
		// printf("total: %d\n",total);

		for(i=maks;i>=1;i--){
			if(total == k){
				break;
			}
			if(cnt[i] >= (i-1)){
				cnt[i] -= (i-1);
				cnt[i-1] += i;
				total++; 
				i++;
			}
		}
		assert(total == k);
		//optimize more
		multiset<int> s;
		for(i=1;i<=maks;i++){
			int sisa = cnt[i] - temp[i];
			for(j=0;j<sisa;j++){
				s.insert(i);
				printf("insert %d\n",i);
			}
		}
		// printf("size; %d\n",int(s.size()));
		if(s.size() == 1){
			printf("%lld\n",hit());
			continue;
		}

		while(true) {
			assert(s.size() > 1);
			int kecil = *s.begin(), besar = *s.rbegin();
			if(kecil == besar){break;}
			int cntKecil = cnt[kecil], cntBesar = cnt[besar];
			cnt[kecil]--; cnt[besar]--;
			cnt[kecil+1]++; cnt[besar-1]++;
			s.erase(s.begin()); s.erase(--s.end());
			s.insert(kecil+1); s.insert(besar-1);
			kecil = *s.begin(), besar = *s.rbegin();
			if(cnt[besar] == cntBesar){
				break;
			}
		}

		printf("%lld\n",hit());
	}
	
	return 0;
};