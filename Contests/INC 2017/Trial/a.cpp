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

int main(){
	int n,i;
	ll sum = 0, minim = inf, maks = -inf;
	scanf("%d",&n);
	while(n--){
		ll bil;
		scanf("%lld",&bil);
		sum+=bil; minim = min(minim,bil); maks = max(maks,bil);
	}
	set<ll> s;
	s.insert(sum); s.insert(minim); s.insert(maks);
	for(i=0; ;i++){
		if(!s.count(i)){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
};