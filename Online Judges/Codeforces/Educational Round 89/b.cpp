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

bool isOverlap(ii a, ii b){
	return ((a.first >= b.first && a.first <= b.second) || (b.first >= a.first && b.first <= a.second));
}

ii merge(ii a, ii b){
	ii res = ii(0,0);
	res.first = min(a.first, b.first);
	res.second = max(a.second, b.second);
	return res;
}

int main(){
	int tc,i,j;
	int n,x,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&x,&m);
		ii cur = ii(x,x);
		for(i=0;i<m;i++){
			int l,r;
			scanf("%d %d", &l,&r);
			ii pas = ii(l,r);
			if(isOverlap(cur, pas)) {
				cur = merge(cur, pas);
			}
		}
		printf("%d\n",cur.second - cur.first + 1);
	}
	
	return 0;
};