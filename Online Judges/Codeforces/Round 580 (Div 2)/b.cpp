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
	int n,i,j;
	scanf("%d",&n);
	int a[100001];
	int neg = 0, nol = 0, pos = 0;
	ll ans = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 0){nol++; ans++;}
		else if(a[i] < 0){neg++; ans += (ll)(abs(-a[i]-1));}
		else{pos++; ans += (ll)abs(a[i] - 1);}
	}
	if(neg % 2 == 0){
		printf("%lld\n",ans);
	}else{
		if(nol > 0) {
			printf("%lld\n",ans);
		}else{
			ans += 2LL;
			printf("%lld\n",ans);
		}
	}

	return 0;
};