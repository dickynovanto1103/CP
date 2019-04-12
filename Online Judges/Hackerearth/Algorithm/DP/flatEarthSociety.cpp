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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int maxn = 1e5 + 1;
ll a[maxn];
ll dpDepan[maxn], dpBelakang[maxn];
int l,r;

ll solveDepan(int idx){
	if(idx >= maxn){return 0;}
	if(dpDepan[idx] != -1){return dpDepan[idx];}
	return dpDepan[idx] = max(solveDepan(idx+1), a[idx] + solveDepan(idx+r+1));
}

ll solveBelakang(int idx){
	if(idx <= 0){return 0;}
	if(dpBelakang[idx] != -1){return dpBelakang[idx];}
	return dpBelakang[idx] = max(solveBelakang(idx-1), a[idx] + solveBelakang(idx-l-1));
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d %d %d",&n,&l,&r);
		int cnt[maxn];
		memset(cnt, 0, sizeof cnt);
		
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			cnt[bil]++;
		}
		
		for(i=1;i<=100000;i++){
			a[i] = (ll)cnt[i]*(ll)i;
		}
		memset(dpDepan, -1, sizeof dpDepan); memset(dpBelakang, -1, sizeof dpBelakang);
		ll ans1 = solveDepan(1);
		ll ans2 = solveBelakang(100000);
		printf("%lld\n",max(ans1,ans2));
	}
	return 0;
};