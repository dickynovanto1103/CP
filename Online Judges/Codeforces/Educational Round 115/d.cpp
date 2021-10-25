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

const int maxn = 2e5 + 5;

int a[maxn], b[maxn];
int cnta[maxn], cntb[maxn];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){

			scanf("%d %d",&a[i], &b[i]);
			cnta[a[i]]++; cntb[b[i]]++;
		}

		ll cntAll = ((ll)n*(n-1) / 2)*(n-2)/3;
		ll cntBad = 0;
		for(i=0;i<n;i++){
			cnta[a[i]]--; cntb[b[i]]--;

			cntBad += (ll)cnta[a[i]] * cntb[b[i]];

			cnta[a[i]]++; cntb[b[i]]++;	
		}

		printf("%lld\n", cntAll - cntBad);

		for(i=1;i<=n;i++){
			cnta[i] = cntb[i] = 0;
		}
	}
	
	return 0;
};