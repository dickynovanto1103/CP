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

const int maxn = 4e5 + 5;

int main(){
	int n,besar, i,j;
	scanf("%d %d",&n,&besar);
	int a[maxn];
	map<int,int> mapper;
	int invMap[maxn];
	int cnt[maxn];

	int counter = 0;
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(mapper.find(a[i]) == mapper.end()){
			mapper[a[i]] = counter;
			invMap[counter] = a[i];
			cnt[counter]++;
			counter++;
		}else{
			int idx = mapper[a[i]];
			cnt[idx]++;
		}
	}
	ll tot;
	for(i=1;i<maxn;i++){
		cnt[i] += cnt[i-1];
	}
	tot = cnt[maxn-1];
	besar *= 8;
	int kMaks = besar / n;
	int bil = 1;

	int K;
	if(kMaks >= 19){
		printf("0\n");
		return 0;
	}else{
		K = powl(2, kMaks);
	}
	// printf("kMaks: %d\n",kMaks);
	ll minim = inf;
	// printf("K: %d\n",K);
	if(counter <= K){
		printf("0\n");
	}else{
		ll ans = cnt[K-1];
		ll sisa = tot - ans;
		minim = min(minim, sisa);
		for(i=K;i<maxn;i++){
			ans = cnt[i] - cnt[i - K];
			sisa = tot - ans;
			minim = min(minim, sisa);
		}
		printf("%lld\n",minim);
	}
	return 0;
};