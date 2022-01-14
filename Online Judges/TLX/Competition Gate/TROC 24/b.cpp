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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j,a[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	if(n == 2) {
		printf("%d\n", a[0] - a[1]);
		return 0;
	}

	ll gen = 0, gan = 0;
	for(i=0;i<n;i++){
		if(i % 2 == 0){gen+=(ll)a[i];}
		else{gan += (ll)a[i];}
	}

	printf("%lld\n", max(gen - gan, gan - gen));
	
	return 0;
};