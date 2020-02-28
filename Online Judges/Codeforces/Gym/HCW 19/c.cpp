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

int a[2020];
int n;

bool can(int w, int p, int q) {
	int i,j;
	bool bisa = true;
	// printf("w: %d\n",w);
	for(i=0;i<n;i++) {
		if(p == 0 && q == 0){bisa = false;break;}
		if(i == n-1){
			break;
		}

		int setelah = a[i+1];
		int diff = setelah - a[i]+1;
		// printf("setelah; %d a[%d]: %d diff: %d\n",setelah, i, a[i], diff);
		if(diff > w) {
			if(diff > 2*w){
				if(p > 0) {
					p--;
				}else{
					q--;
					int setelah = a[i] + 2*w-1;
					// printf("setelah: %d q jd: %d\n", setelah,q);
					int idxSetelah = upper_bound(a,a+n, setelah) - a;

					i = idxSetelah - 1;	
				}
			}else{
				if(p > 0){
					p--;
					
				}else{
					q--;
					int setelah = a[i] + 2*w-1;
					// printf("setelah: %d q jd: %d\n", setelah,q);
					int idxSetelah = upper_bound(a,a+n, setelah) - a;
					i = idxSetelah - 1;
				}	
			}
			
		}else{
			if(p > 0) {
				p--;
				int setelah = a[i] + w-1;
				// printf("setelah: %d p jd: %d\n", setelah,p);
				int idxSetelah = upper_bound(a,a+n, setelah) - a;
				// printf("idxSetelah: %d\n",idxSetelah);
				i = idxSetelah - 1;
			}else{
				q--;
				// printf("q jd: %d\n",q);
				int setelah = a[i] + 2*w-1;
				// printf("setelah; %d\n",setelah);
				int idxSetelah = upper_bound(a,a+n, setelah) - a;
				i = idxSetelah - 1;

			}
		}
	}
	return bisa;
}

int main(){
	int p,q;
	scanf("%d %d %d",&n,&p,&q);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int kiri = 1, kanan = inf, mid, ans;
	while(kiri <= kanan) {
		mid = (kiri+kanan)/2;
		if(can(mid, p, q)) {
			ans = mid;
			kanan = mid-1;			
		}else{
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};