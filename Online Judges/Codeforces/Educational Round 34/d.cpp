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

const int maxn = 200010;
ll a[maxn];
ll sum[maxn];
vi listIdx[maxn];
map<ll,int> mapper;
map<ll,int>::iterator it;

int main(){
	int tc,i,j;
	int n;
	scanf("%d",&n);
	int cnt = 1;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		it=mapper.find(a[i]);
		if(it==mapper.end()){
			mapper[a[i]] = cnt;
			listIdx[cnt].pb(i);
			cnt++;
		}else{
			int nilai = mapper[a[i]];
			listIdx[nilai].pb(i);
		}
		if(i==0){sum[i]=a[i];}
		else{sum[i] = sum[i-1] + a[i];}
	}
	//lakukan penjumlahan
	ll ans = 0;
	for(i=0;i<n;i++){
		//cari indeks minimal yang x-1,x dan x+1
		ll bil = a[i];
		int indeks = mapper[bil];
		int indeks1 = mapper[bil-1];
		int indeks2 = mapper[bil+1];
		//printf("indeks2: %d\n",indeks2);
		int idx = lower_bound(listIdx[indeks].begin(),listIdx[indeks].end(),i+1) - listIdx[indeks].begin();
		int idx1 = lower_bound(listIdx[indeks1].begin(),listIdx[indeks1].end(),i+1) - listIdx[indeks1].begin();
		int idx2 = lower_bound(listIdx[indeks2].begin(),listIdx[indeks2].end(),i+1) - listIdx[indeks2].begin();
		int ukuran = listIdx[indeks].size();
		int ukuran1 = listIdx[indeks1].size();
		int ukuran2 = listIdx[indeks2].size();
		int banyakYangSama = ukuran-idx + ukuran1-idx1 + ukuran2-idx2;
		ans+=(sum[n-1] - sum[i]);
		// printf("%d %d %d\n",ukuran-idx,ukuran1-idx1,ukuran2-idx2);
		// printf("ans: %lld banyakYangSama: %d\n",ans,banyakYangSama);
		ans-=((ukuran-idx)*bil);
		ans-=((ukuran1-idx1)*(bil-1));
		ans-=((ukuran2-idx2)*(bil+1));
		ans-=((n-1-i-banyakYangSama)*bil);
	}
	printf("%lld\n",ans);
	return 0;
};