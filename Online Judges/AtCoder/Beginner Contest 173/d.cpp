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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[200001];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	sort(a,a+n, cmp);

	int sisa = n-1;
	vi avail;
	avail.pb(a[0]);
	ll ans = 0;
	for(i=1;i<n;i++){
		if(avail.size() >= sisa){
			int idx = 0;
			for(j=i;j<n;j++){
				ans += avail[idx++];
				// printf("j: %d idx; %d\n",j, idx-1);
			}
			break;
		}else{
			int back = avail.back();
			ans += back;
			avail.pop_back();
			avail.pb(a[i]); avail.pb(a[i]);
			// printf("ans: %lld\n",ans);
			// for(j=0;j<avail.size();j++){
			// 	printf("%d ", avail[j]);
			// }
			// printf("\n");
			sisa--;
		}
	}
	printf("%lld\n",ans);
	
	return 0;
};