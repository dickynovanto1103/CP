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

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ii a[1010];
	for(i=0;i<n;i++){
		scanf("%d",&a[i].first);
		a[i].second = i+1;
	}
	sort(a,a+n,cmp);
	ll ans = 0;
	ll cnt = 0;

	for(i=0;i<n;i++){
		ans += cnt*a[i].first + 1;
		cnt++;
	}
	printf("%lld\n",ans);
	for(i=0;i<n;i++){
		printf("%d ",a[i].second);
	}
	printf("\n");
	return 0;
};