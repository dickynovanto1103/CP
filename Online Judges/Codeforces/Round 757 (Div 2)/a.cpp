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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n,l,r,k;
	scanf("%d",&tc);
	int a[101];
	while(tc--){
		scanf("%d %d %d %d",&n,&l,&r,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		int cnt = 0;
		for(i=0;i<n;i++){
			if(a[i] < l || a[i] > r) {continue;}
			if(k >= a[i]) {
				k -= a[i];
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}
	
	return 0;
};