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
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n;
	ll bil;
	priority_queue<ll,vi, greater<ll> > pq;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){scanf("%lld",&bil); pq.push(bil);}
		ll ans = 0;
		while(!pq.empty()){
			ll front1 = pq.top(); pq.pop();
			ll front2 = pq.top(); pq.pop();
			ll bilbaru = front1+front2;
			ans+=bilbaru;
			if(pq.empty()){break;}
			pq.push(bilbaru);
		}
		printf("%lld\n",ans);
	}
	return 0;
};