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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

ii a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n==2){printf("0\n"); return 0;}
	ll sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i].first);
		sum += a[i].first;
		a[i].second = i+1;
	}
	// printf("sum: %lld\n",sum);
	sort(a,a+n);
	ll maks = 0;
	vi listIdx;
	for(i=0;i<n;i++){
		if(i == n-1){
			maks = a[i-1].first;
		}else{
			maks = a[n-1].first;
		}
		// printf("maksSekarang: %lld\n",maks);
		ll nilaiSum = sum - a[i].first - maks;
		// printf("nilaiSum; %lld elemen sekarang: %d\n",nilaiSum, a[i].first);
		if(maks == nilaiSum){
			listIdx.pb(a[i].second);
		}

	}
	int ukuran = listIdx.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		printf("%d ",listIdx[i]);
	}
	printf("\n");
	return 0;
};