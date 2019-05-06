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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int q;
	scanf("%d",&n);
	set<ll> s;
	set<ll>::iterator it;
	for(i=0;i<n;i++){
		ll bil;
		scanf("%lld",&bil);
		s.insert(bil);
	}

	ll diff[maxn], pref[maxn];
	memset(diff, 0, sizeof diff); memset(pref, 0, sizeof pref);
	vi a;
	for(it=s.begin();it!=s.end();it++){
		a.pb(*it);
	}
	ll ukuran = a.size();
	for(i=0;i<ukuran-1;i++){
		diff[i] = a[i+1] - a[i] - 1;
		// printf("diff[%d]: %lld\n",i,diff[i]);
	}

	sort(diff, diff+ukuran-1);

	for(i=0;i<ukuran-1;i++){
		pref[i] = diff[i];
		if(i){pref[i] += pref[i-1];}
	}

	scanf("%d",&q);
	for(i=0;i<q;i++){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		b-=a;
		//process
		int idx = upper_bound(diff, diff+ukuran-1, b) - diff;
		ll ans;
		ans = (idx == 0 ? 0 : pref[idx-1]);
		// printf("idx: %d ans: %lld\n",idx, ans);
		ans += (ukuran - idx)*b;
		ans += ukuran; 

		if(i){printf(" ");}
		printf("%lld",ans);
		

	}
	printf("\n");
	return 0;
};