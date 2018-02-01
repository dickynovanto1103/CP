#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll n,a[100010],cnt[100010],i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]); cnt[i] = 1;}
	for(i=1;i<n;i++){
		if(a[i]>a[i-1]){cnt[i] = cnt[i-1]+1;}
	}
	for(i=n-2;i>=0;i--){
		if(a[i] > a[i+1] && cnt[i]<=cnt[i+1]){cnt[i] = cnt[i+1]+1;}
	}
	ll sum = 0;
	for(i=0;i<n;i++){
		//if(i){printf(" ");}
		//printf("%lld",cnt[i]);
		sum+=cnt[i];
	}
	//printf("\n");
	printf("%lld\n",sum);
	return 0;
}