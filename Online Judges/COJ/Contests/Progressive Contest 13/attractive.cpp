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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int pref[maxn];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[maxn];
	while(tc--){
		int n,q;
		scanf("%d %d",&n,&q);

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pref[i] = a[i];
			pref[i] += pref[i-1];
		}
		for(int t=0;t<q;t++){
			int k;
			if(t){printf(" ");}
			scanf("%d",&k);
			ll ans = 0;
			for(i=1;i<=n;i++){
				int kiri = i, kanan = n, mid, ansBawah = -1, ansAtas = -1;
				while(kiri <= kanan) {
					mid = (kiri + kanan)/2;
					int sum = pref[mid] - pref[i-1];
					if(sum > k) {
						kanan = mid-1;
					}else if(sum == k) {
						ansBawah = mid;
						kanan = mid-1;
					}else{
						kiri = mid+1;
					}
				}
				if(ansBawah == -1){

					continue;
				}
				kiri = i, kanan = n;
				while(kiri <= kanan) {
					mid = (kiri + kanan)/2;
					int sum = pref[mid] - pref[i-1];
					if(sum > k) {
						kanan = mid-1;
					}else if(sum == k) {
						ansAtas = mid;
						kiri = mid+1;
					}else{
						kiri = mid+1;
					}
				}
				// printf("tambah\n");
				ans += (ansAtas - ansBawah + 1);


			}
			printf("%lld",ans);
		}
		printf("\n");
	}
	return 0;
};