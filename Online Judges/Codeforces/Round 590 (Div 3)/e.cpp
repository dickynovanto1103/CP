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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int n,i,j,m;
	scanf("%d %d",&n,&m);
	int a[maxn];
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	ll ans[maxn];
	memset(ans, 0, sizeof ans);
	for(i=0;i<m-1;i++){
		int awal = a[i], akhir = a[i+1];
		// printf("x: %d y: %d\n",awal, akhir);
		if(awal > akhir){
			swap(awal, akhir);
		}else if(awal == akhir){continue;}
		//1..awal-1
		int selisih;
		if(1 <= awal-1){
			selisih = akhir - awal;
			debug printf("selisih: %d awal: %d akhir: %d tambah di %d sampe %d\n",selisih,awal,akhir,1,awal-1);
			ans[1] += selisih; ans[awal] -= selisih;
		}
		
		//awal..awal
		selisih = akhir - 1;
		debug printf("tambah %d dari %d sampe %d\n",selisih, awal, awal);
		ans[awal] += selisih; ans[awal+1] -= selisih;
		//awal + 1 .. akhir-1
		if(awal+1 <= akhir-1){
			selisih = akhir - (awal+1);
			debug printf("tambah %d dari %d sampe %d\n",selisih, awal+1, akhir-1);
			ans[awal+1] += selisih; ans[akhir] -= selisih;	
		}
		
		//akhir..akhir
		selisih = abs(1-(awal+1));
		debug printf("tambah %d dari %d sampe %d\n",selisih, akhir, akhir);
		ans[akhir] += selisih; ans[akhir+1] -= selisih;
		//akhir+1..n
		if(akhir+1 <= n){
			selisih = akhir - awal;
			debug printf("tambah %d dari %d sampe %d\n",selisih, akhir+1, n);
			ans[akhir+1] += selisih; ans[n+1] -= selisih;	
		}
		
	}
	for(i=1;i<=n;i++){
		ans[i] += ans[i-1];
		printf("%lld ",ans[i]);
	}
	printf("\n");

	return 0;
};