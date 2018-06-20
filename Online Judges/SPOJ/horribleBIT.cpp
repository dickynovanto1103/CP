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

const int maxn = 1e5 + 5;
int n;
ll bit1[maxn], bit2[maxn];

ll query1(int idx){
	ll sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)) {
		sum+=bit1[i];
	}
	return sum;
}
ll query2(int idx){
	ll sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)) {
		sum+=bit2[i];
	}
	return sum;
}

void updateBit1(int idx, ll val) {
	for(int i=idx;i<=n;i+=(i&-i)) {
		bit1[i]+=val;
	}
}

void updateBit2(int idx, ll val) {
	for(int i=idx;i<=n;i+=(i&-i)) {
		bit2[i]+=val;
	}
}

void update(int l, int r, ll v) {
	updateBit1(l, v);
	updateBit1(r+1,-v);
	updateBit2(l, v*((ll)l-1LL));
	updateBit2(r+1, -v*((ll)r));
}

ll jawab(int l) {
	return query1(l)*(ll)l - query2(l);
}

int main(){
	int tc,i,j,q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&q);
		memset(bit1,0,sizeof bit1); memset(bit2, 0, sizeof bit2);
		while(q--){
			int com,l,r;
			ll v;
			scanf("%d",&com);
			if(com==0){
				scanf("%d %d %lld",&l,&r,&v);
				update(l,r,v);
			}else{
				scanf("%d %d",&l,&r);
				ll ans = jawab(r) - jawab(l-1);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
};