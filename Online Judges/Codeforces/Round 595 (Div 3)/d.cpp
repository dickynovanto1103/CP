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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	iii a[200010];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first.first, &a[i].first.second);
		a[i].second = i;
	}
	sort(a,a+n, [](iii a, iii b){
		if(a.first.first == b.first.first){
			return a.first.second - a.first.first > b.first.second - b.first.first;
		}
		return a.first.first < b.first.first;
	});
	int cur = -1, banyakBuang = 0;
	vi li;
	for(i=0;i<n;i++){

		iii pas = a[i];
		int awal = pas.first.first, akhir = pas.first.second;
		debug printf("%d %d %d\n",awal, akhir, pas.second);
		if(cur != awal){
			cur = awal;
			banyakBuang = 0;
		}
		int idxAkhir = upper_bound(a, a+n, iii(ii(akhir,inf), 0)) - a;
		int idxAwal = lower_bound(a,a+n, iii(ii(awal,0),0)) - a;
		
		int banyak = idxAkhir - idxAwal - banyakBuang;
		debug printf("idxAwal: %d idxAkhir: %d banyakBuang: %d\n",idxAwal, idxAkhir, banyakBuang);
		if(banyak > k){
			li.pb(pas.second+1);
			banyakBuang++;
			printf("dipush: %d\n",pas.second);
		}

	}
	printf("%d\n",(int)li.size());
	for(int a: li){
		printf("%d ",a);
	}
	printf("\n");
	return 0;
};