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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll a[maxn], b[maxn], pref1[maxn], pref2[maxn];
	pref1[0] = 0; pref2[0] = 0;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i] = a[i];
		pref1[i] = a[i];
		pref1[i] += pref1[i-1];
	}
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++){
		pref2[i] = b[i];
		pref2[i] += pref2[i-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int type, l, r;
		scanf("%d %d %d",&type,&l,&r);
		if(type == 1){
			printf("%lld\n",pref1[r] - pref1[l-1]);
		}else{
			printf("%lld\n",pref2[r] - pref2[l-1]);
		}
	}

	return 0;
};