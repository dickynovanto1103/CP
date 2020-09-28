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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll a[10002];
int n;

void cetak(){
	printf("cetak\n");
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	printf("\n");
}

viii ans;

void process(int i, int j, int x) {
	a[i] -= (x*i);
	a[j] += (x*i);
	debug cetak();
	assert(a[i] >= 0);
	assert(a[j] >= 0);
	ans.pb(iii(ii(i,j), x));
}

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		ans.clear();
		scanf("%d",&n);
		ll sum = 0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		// printf("sum: %lld n: %d\n",sum, n);

		if(sum % n != 0){
			printf("-1\n");
			continue;
		}
		ll expected = sum / n;

		//cari bagi maksimal...ambil maks 3
		vii listTambah;
		for(i=2;i<=n;i++){
			ll bagi = a[i] / i;
			ll sisa = a[i] % i;
			if(bagi > 0){
				listTambah.pb(ii(a[i] - sisa, i));
				// process(i, 1, bagi);
			}
		}
		sort(listTambah.begin(), listTambah.end(), cmp);
		int sz = min(3, (int)listTambah.size());
		for(i=0;i<sz;i++){
			ii pas = listTambah[i];
			int idx = pas.second, tambah = pas.first;

			int bagi = a[idx] / idx;
			// printf("a[%d]: %d bagi: %d tambah: %d\n",idx, a[idx], bagi, tambah);
			process(idx, 1, bagi);
		}

		vii list;
		for(i=2;i<=n;i++){
			if(a[i] == 0){continue;}
			//find nearest divider

			int bagi = (a[i] + i - 1) / i;
			int harapan = i * bagi;

			int selisih = harapan - a[i];
			if(selisih > 0){
				list.pb(ii(selisih, i));
				// printf("selisih: %d i: %d\n",selisih, i);	
			}else if(selisih == 0){
				process(i, 1, bagi);
			}
		}
		sort(list.begin(), list.end());
		for(i=0;i<list.size();i++){
			ii pas = list[i];
			int idx = pas.second, selisih = pas.first;
			// printf("idx: %d selisih: %d\n",idx, selisih);

			process(1, idx, selisih);

			int bagi = a[idx] / idx;
			process(idx, 1, bagi);
		}

		for(i=2;i<=n;i++){
			if(a[i] == expected){
				continue;
			}else if(a[i] < expected) {
				//tambahin dari satu
				ll selisih = expected - a[i];
				process(1, i, selisih);
			}else{

			}
		}

		for(i=1;i<=n;i++){
			assert(a[i] == expected);
		}
		assert((int)ans.size() <= 3*n);
		printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++){
			printf("%d %d %d\n",ans[i].first.first, ans[i].first.second, ans[i].second);
		}
	}
	
	return 0;
};