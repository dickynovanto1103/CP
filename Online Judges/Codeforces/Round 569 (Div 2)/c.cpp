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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	deque<int> a;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a.push_back(bil);
	}
	ii ans[maxn];
	for(i=1;i<n;i++){
		int depan = a.front(); a.pop_front();
		int depan2 = a.front(); a.pop_front();
		if(depan > depan2){
			a.push_front(depan);
			a.push_back(depan2);
		}else{
			a.push_front(depan2);
			a.push_back(depan);
		}
		// printf("depan: %d depan2: %d\n",depan, depan2);
		// for(j=0;j<n;j++){
		// 	printf("%d\n",a[j]);
		// }
		ans[i] = ii(depan, depan2);
	}
	// for(i=0;i<n;i++){
	// 	printf("a[%d]: %d\n",i,a[i]);
	// }

	// int bil[maxn];
	// for(i=1;i<n;i++){
	// 	bil[i-1] = a[i];
	// }


	while(q--){
		ll idx;
		scanf("%lld",&idx);
		if(idx < (ll)n){
			printf("%d %d\n",ans[idx].first, ans[idx].second);
		}else{
			idx %= (ll)(n-1);
			if(idx == 0){idx = n-1;}
			// printf("idx :%d\n",idx);
			printf("%d %d\n",a[0], a[idx]);
		}
	}
	return 0;
};