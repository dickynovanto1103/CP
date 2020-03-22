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

int findTambah(int sisaK, int top1, int top2) {
	for(int i=1;i<=sisaK;i++){
		int hasilBagi = (top1 + i)/(i+1);
		if(hasilBagi <= top2){
			return i;
		}
	}
	return sisaK;
}

vi genHasil(int pembagi, int bil) {
	vi a;
	if(pembagi >= bil){
		for(int i=0;i<bil;i++){
			a.pb(1);
		}
		return a;
	}
	int maks = (bil + pembagi - 1)/pembagi;
	int minim = bil / pembagi;
	while(bil % pembagi != 0){
		a.pb(maks);
		bil -= maks;
		pembagi--;
	}
	while(bil){
		a.pb(minim);
		bil -= minim;
		pembagi--;
	}
	assert(bil == 0 && pembagi == 0);
	return a;
}

bool can(int mid, priority_queue<int> pq, int k) {
	if(pq.size() == 1){
		//lgsg bagi sebanyak"nya
		int top = pq.top();
		pq.pop();
		int hasilBagi = (top + k)/(k+1);
		// printf("halo hasilBagi: %d\n", hasilBagi);
		pq.push(hasilBagi);
	} else {
		while(k){
			int top1 = pq.top(); pq.pop();

			//bagi top 1 hingga <= mid
			int tambah = findTambah(k, top1, mid);
			vi v = genHasil(tambah + 1, top1);

			// printf("tambah: %d v: ", tambah);
			for(int i=0;i<v.size();i++){
				// printf("%d ",v[i]);
				pq.push(v[i]);
			}
			// printf("\n");

			if((tambah+1) != v.size()){
				break;
			}

			k -= (tambah);	

		}
		
	}
	return pq.top() <= mid;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[100001];
	for(int tt=1;tt<=tc;tt++){
		int n,k;
		scanf("%d %d",&n,&k);

		for(i=0;i<n;i++){scanf("%d",&a[i]);}

		priority_queue<int> pq, temp;
		for(i=0;i<n-1;i++){
			int diff = a[i+1] - a[i];
			pq.push(diff);
			temp.push(diff);
		}

		int kiri = 1, kanan = pq.top(), mid, ans;
		while(kiri <= kanan) {
			mid = (kiri+kanan)/2;
			if(can(mid, pq, k)) {
				ans = mid;
				kanan = mid - 1;
			}else{
				kiri = mid+1;
			}
			pq = temp;
		}

		// printf("%d\n",ans);
		
		
		// if(pq.size() == 1){
		// 	//lgsg bagi sebanyak"nya
		// 	int top = pq.top();
		// 	pq.pop();
		// 	int hasilBagi = (top + k)/(k+1);
		// 	// printf("halo hasilBagi: %d\n", hasilBagi);
		// 	pq.push(hasilBagi);
		// } else {
		// 	while(k){
		// 		int top1 = pq.top(); pq.pop();
		// 		int top2 = pq.top();
		// 		printf("top1: %d top2: %d\n", top1, top2);

		// 		//bagi top 1 hingga lebih kecil dr top 2
		// 		int tambah = findTambah(k, top1, top2);
		// 		vi v = genHasil(tambah + 1, top1);

		// 		printf("tambah: %d v: ", tambah);
		// 		for(i=0;i<v.size();i++){
		// 			printf("%d ",v[i]);
		// 			pq.push(v[i]);
		// 		}
		// 		printf("\n");

		// 		if((tambah+1) != v.size()){
		// 			break;
		// 		}

		// 		k -= (tambah);	

		// 	}
			
		// }

		printf("Case #%d: %d\n",tt, ans);
	}
	return 0;
};