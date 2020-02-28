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

const int maxn = 1e4 + 4;

int a[maxn];
int n;

bool can(ll mid, int m) {
	ll sum = 0;
	int totOrang = 1;
	for(int i=0;i<n;i++){
		if((sum + (ll)a[i]) > mid){

			sum = a[i];
			if(sum > mid){return false;}
			totOrang++;
		}else{
			sum += a[i];
		}
	}
	return totOrang <= m;
}

int main(){
	int tc,m,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		ll kiri = 1, kanan = 1e11, mid, ans;

		while(kiri<=kanan) {
			mid = (kiri+kanan)/2LL;
			if(can(mid, min(m,n))) {
				ans = mid;
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		printf("Case #%d: %lld\n",tt, ans);

	}
	return 0;
};