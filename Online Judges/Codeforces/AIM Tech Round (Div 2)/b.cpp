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

int main(){
	int n,i,j;
	int a[27];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	ll ans = a[n-1];
	int cur = a[n-1];
	for(i=n-2;i>=0;i--){
		int tambah = min(cur-1, a[i]);
		if(tambah < 0){
			cur = 0;
			continue;
		}
		ans += tambah;
		cur = tambah;
	}
	printf("%lld\n",ans);
	return 0;
};