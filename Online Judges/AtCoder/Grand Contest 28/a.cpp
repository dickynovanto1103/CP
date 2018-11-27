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
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	string a,b;
	scanf("%d %d",&n,&m);
	cin>>a>>b;
	ll gcd = __gcd(n,m);
	ll lcm = ((ll)n*(ll)m) / gcd;	

	ll selisih1 = lcm/n;
	ll selisih2 = lcm/m;
	vi list1,list2;
	for(j=0;j<n;j++){
		list1.pb((ll)j*selisih1);
		// printf("%lld ",j*selisih1);
	}
	// printf("\n");
	for(j=0;j<m;j++){
		list2.pb((ll)j*selisih2);
		// printf("%lld ",j*selisih2);
	}
	// printf("\n");
	vii idxSama;
	for(j=0;j<n;j++){
		int idx = lower_bound(list2.begin(),list2.end(), list1[j]) - list2.begin();
		if(list2[idx] == list1[j]){
			idxSama.pb(ii(j,idx));
			// printf("sama: %lld dan ditemukan di idx: %d %d\n",b[idx], j, idx);
		}
	}
	for(i=0;i<idxSama.size();i++){
		int idx1 = idxSama[i].first, idx2 = idxSama[i].second;
		// printf("idx1: %d idx2: %d\n",idx1,idx2);
		if(a[idx1] != b[idx2]){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",lcm);
	
	return 0;
};