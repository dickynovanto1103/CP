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

const int maxn = 1e5 + 5;

int main(){
	int tc,n,c,i,j;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&n,&c);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		vi listJarakAntara;
		for(i=0;i<(n-1);i++) {
			listJarakAntara.pb(a[i+1] - a[i]);
		}
		int kiri = 0, kanan = a[n-1] - a[0], mid, ans = 0;
		while(kiri<=kanan) {
			mid = (kiri+kanan)/2;
			//ambil sebanyak mid
			// titik = a[0];
			int jarakAntaraSementara = 0;
			int ukuranListJarak = listJarakAntara.size();
			int cnt = 1;
			for(i=0;i<ukuranListJarak;i++) {
				jarakAntaraSementara+=(listJarakAntara[i]);
				if(jarakAntaraSementara >= mid) {
					jarakAntaraSementara = 0;
					cnt++;
				}
			}
			if(cnt>=c) { // perlu diperbesar jaraknya
				ans = mid;
				kiri = mid+1;
			}else {
				kanan = mid-1;
			}
		}

		printf("%d\n",ans);
	}
	return 0;
};