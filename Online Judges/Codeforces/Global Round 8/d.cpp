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

ll a[200001];

int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}

	// vector<vi> adj;
	// adj.assign(21,vi());

	sort(a,a+n);
	for(j=0;j<20;j++){
		int cnt = 0;
		for(i=0;i<n;i++){
			if((1<<j) & a[i]) {
				cnt++;
			}
		}

		for(i=0;i<cnt;i++){
			a[i] |= (1<<j);
		}

		for(i=cnt;i<n;i++){
			if((1<<j) & a[i]){
				a[i] -= (1<<j);
			}
		}
	}
	
	ll ans = 0;
	for(i=0;i<n;i++){
		ans += (ll)a[i]*(ll)a[i];
	}

	printf("%lld\n",ans);
	
	return 0;
};