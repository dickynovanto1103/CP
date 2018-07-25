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

const int maxn = 4e5 + 5;

ll cnt[maxn];
struct point{
	ll koordinat, isAwal;
};

bool cmp(point a, point b){
	if(a.koordinat == b.koordinat){return a.isAwal > b.isAwal;}
	return a.koordinat < b.koordinat;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	point a[maxn];

	int arrSeharusnya[maxn];

	int idx = 0;
	
	for(i=0;i<n;i++){
		ll awal,akhir;
		scanf("%lld %lld",&awal,&akhir);
		
		arrSeharusnya[awal]++;
		arrSeharusnya[akhir+1]--;
		a[idx].koordinat = awal; a[idx].isAwal = 1;
		idx++;
		a[idx].koordinat = akhir; a[idx].isAwal = 0;
		idx++;
	}

	// for(i=1;i<=maks+1;i++){

	// 	arrSeharusnya[i] += arrSeharusnya[i-1];
	// }

	// int ans[maxn];

	// for(i=0;i<=maks+1;i++){
	// 	if(i){printf(" ");}
	// 	ans[arrSeharusnya[i]]++;
	// 	printf("%d",arrSeharusnya[i]);
	// }
	// printf("\n");
	// printf("ans:\n");
	// for(i=1;i<=n;i++){
	// 	if(i>1){printf(" ");}
	// 	printf("%d",ans[i]);
	// }
	// printf("\n");

	sort(a,a+idx,cmp);

	ll koordinatAwal = a[0].koordinat;
	int tinggi = 1;

	for(i=1;i<idx;i++){
		ll koordinatTujuan = a[i].koordinat;
		ll isAwal = a[i].isAwal;
		if(isAwal){
			koordinatTujuan--;
			cnt[tinggi]+=(koordinatTujuan - koordinatAwal + 1);
			tinggi++;
			koordinatTujuan++;
			koordinatAwal = koordinatTujuan;
		}else{
			cnt[tinggi]+=(koordinatTujuan - koordinatAwal + 1);
			tinggi--;
			koordinatAwal = koordinatTujuan+1;
		}
	}

	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		printf("%lld",cnt[i]);
	}
	printf("\n");

	return 0;
};