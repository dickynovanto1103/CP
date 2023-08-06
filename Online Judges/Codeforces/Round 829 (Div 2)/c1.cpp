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
	int tc;
	scanf("%d",&tc);
	int a[200010];
	while(tc--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		if(n % 2 == 1) {puts("-1"); continue;}
		vii v;
		for(int i=0;i<n-1;i+=2){
			if(a[i] == a[i+1]){
				v.pb(ii(i, i+1));
			}else{
				v.pb(ii(i, i));
				v.pb(ii(i+1, i+1));
			}
		}

		printf("%d\n", v.size());
		for(ii pas: v) {
			printf("%d %d\n", pas.first + 1, pas.second + 1);
		}
	}
	
	return 0;
};