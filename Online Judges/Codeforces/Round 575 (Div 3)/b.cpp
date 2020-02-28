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

int main(){
	int q,i,j;
	scanf("%d",&q);
	int a[200001];
	while(q--){
		int n,k;
		scanf("%d %d",&n,&k);
		ll tot = 0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			tot += a[i];
		}
		if(k == 1){
			if(tot % 2 == 1){
				printf("YES\n%d\n",n);
			}else{
				printf("NO\n");
			}
			continue;
		}
		vi ans;
		ll sum = 0;
		for(i=1;i<=n;i++){
			sum += a[i];
			if(sum % 2 == 1){
				ans.pb(i);
				tot -= sum;
				sum = 0;
				if(ans.size() == k-1){break;}
			}
		}
		if(tot % 2 == 1){ans.pb(n);}
		if(ans.size() < k){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(i=0;i<ans.size();i++){
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
};