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
ll pref1[maxn], pref2[maxn];

int main(){
	int n,m;
	ll k;
	scanf("%d %d %lld",&n,&m,&k);
	int i,j;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		pref1[i] = a[i];
		if(i){
			pref1[i] += pref1[i-1];
		}
	}

	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		pref2[i] = b[i];
		if(i){
			pref2[i] += pref2[i-1];
		}
	}

	int cnt = 0;
	for(i=0;i<n;i++){
		if(pref1[i] > k){
			break;
		}
		int ans = i+1;
		ll sisa = k - pref1[i];
		int idx = upper_bound(pref2, pref2+m, sisa) - pref2;
		ans += idx;
		cnt = max(cnt, ans);
	}

	for(i=0;i<m;i++){
		if(pref2[i] > k){
			break;
		}
		int ans = i+1;
		ll sisa = k - pref2[i];
		int idx = upper_bound(pref1, pref1+n, sisa) - pref1;
		ans += idx;
		cnt = max(cnt, ans);
	}
	printf("%d\n",cnt);
	
	return 0;
};