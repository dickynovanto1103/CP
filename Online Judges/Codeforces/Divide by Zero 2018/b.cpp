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

const int maxn = 1e3+1;
int a[maxn], b[maxn];

int main(){
	int n,k1,k2,i,j;
	
	scanf("%d %d %d",&n,&k1,&k2);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&b[i]);}
	priority_queue<int> pq;
	for(i=0;i<n;i++){
		pq.push(abs(a[i]-b[i]));
	}
	for(i=0;i<(k1+k2);i++){
		int front = pq.top(); pq.pop();
		if(front==0){pq.push(front+1);}
		else{pq.push(front-1);}
	}
	ll ans = 0;
	while(!pq.empty()){
		ll front = (ll)pq.top(); pq.pop();
		ans+=(front*front);
	}
	printf("%lld\n",ans);

	return 0;
};