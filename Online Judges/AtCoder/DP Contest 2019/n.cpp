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

const int maxn = 401;

int main(){
	int n,i,j;
	ll a[maxn];
	scanf("%d",&n);
	priority_queue<ll, vi, greater<ll> > pq;
	for(i=0;i<n;i++){scanf("%lld",&a[i]); pq.push(a[i]);}
	ll tot = 0;
	while(pq.size() > 1){
		ll bil1 = pq.top(); pq.pop();
		ll bil2 = pq.top(); pq.pop();
		ll sum = bil1 + bil2;
		tot += sum;
		pq.push(sum);
	}
	printf("%lld\n",tot);
	
	return 0;
};