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

const int maxn = 2e5 + 5;

int a[maxn];
int sorted[maxn];

int n,k;

bool can(int mid) {
	int i;
	int bil = sorted[mid];
	vi listPos;
	for(i=0;i<n;i++){
		if(a[i] <= bil){listPos.pb(i);}
	}

	//dari posisi"ini kita coba untuk tentukan apakah mau ditaruh di section genap atau ganjil
	//dan ga bisa ditaruh secara berturut"...jadi kalo next posisi tepat di idx+1, harus diskip elemen ini..karena kita fokus di section genap / ganjil saja
	int needGanjil = (k % 2 == 1 ? k/2 + 1: k/2);
	int needGenap = k/2;

	//cek ganjil dulu
	//syarat bisa ditaruh di ganjil:
	//1. Jika k ganjil, posisi idx diambil bisa 0 dan index terakhir (n-1)
	//2. Jika k genap, posisi idx diambil bisa 0 tapi tidak index terakhir (n-1)
	//3. Tetap harus dijarak minimal 1 antar posisi
	int ukuran = listPos.size();
	int cnt = 0;
	int lastIdx = -inf;
	for(i=0;i<ukuran;i++){
		int idx = listPos[i];
		if(lastIdx + 1 == idx){continue;}
		if(k % 2 == 0 && idx == (n-1)){continue;}
		cnt++;
		lastIdx = idx;
	}

	if(cnt >= needGanjil){return true;}

	//cek genap
	//syarat bisa ditaruh di genap:
	//1. idx != 0
	//2. Jika k ganjil, posisi idx ga bs ambil idx terakhir (n-1)
	//3. Jika k genap, posisi idx bisa ambil idx terakhir (n-1)
	lastIdx = -inf;
	cnt = 0;
	for(i=0;i<ukuran;i++){
		int idx = listPos[i];
		if(lastIdx + 1 == idx){continue;}
		if(idx == 0){continue;}
		if(k % 2 == 1 && idx == (n-1)){continue;}
		cnt++;
		lastIdx = idx;
	}

	if(cnt >= needGenap){return true;}

	return false;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sorted[i] = a[i];
	}

	sort(sorted, sorted + n);
	int kiri = 0, kanan = n-1, mid, ans;
	while(kiri <= kanan){
		mid = (kiri + kanan)/2;
		if(can(mid)){
			ans = sorted[mid];
			kanan = mid - 1;
		}else{
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};