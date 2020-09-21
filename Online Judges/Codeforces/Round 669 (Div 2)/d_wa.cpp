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

const int maxn = 3e5 + 1;
struct nod
{
	int minim, maks;
};

nod seg[4*maxn];

int a[maxn];

int ans[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	ans[1] = 0;
	ans[2] = 1;
	
	for(i=3;i<=n;i++){
		//coba binser ke kiri ada ga yang di tengah"nya min(tingginya) > max(a[kiri] dan a[kanan]), atau ada ga yang max(tinggi tengah) < min(a[kiri], a[kanan])
		int kiri = 1, kanan = i-2, mid, jawaban = ans[i-1] + 1;
		while(kiri <= kanan){
			mid = (kiri+kanan)/2;
			nod jawab = query(1,1,n,mid+1, i-1);
			// printf("mid+1: %d i-1: %d jawab: %d %d\n",mid+1, i-1, jawab.minim, jawab.maks);
			if(jawab.minim > max(a[mid], a[i])) {
				jawaban = min(jawaban, ans[mid] + 1);
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		ans[i] = jawaban;
		
		kiri = 1, kanan = i-2, jawaban = ans[i-1] + 1;
		while(kiri <= kanan){
			mid = (kiri+kanan)/2;
			nod jawab = query(1,1,n,mid+1, i-1);
			if(jawab.maks < min(a[mid], a[i])) {
				jawaban = min(jawaban, ans[mid] + 1);
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		ans[i] = min(ans[i], jawaban);
		// printf("ans[%d]: %d\n",i, ans[i]);
	}

	printf("%d\n",ans[n]);

	return 0;
};