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

priority_queue<ll, vi, greater<ll> > pq;

int main(){
	int n,i,j;
	ll a[200010];
	ll sum = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]); pq.push(a[i]);}
	if(n%2==0){pq.push(0);}
	ll ans = 0;
	while(pq.size()>1){
		ll cur = pq.top();
		pq.pop();
		cur+=pq.top(); pq.pop();
		cur+=pq.top(); pq.pop();
		ans+=cur;
		pq.push(cur);
	}
	printf("%lld\n",ans);
	return 0;
};