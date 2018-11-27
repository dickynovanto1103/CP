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

int main(){
	int tc,n,i,j;
	ll a[7500];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lld",&a[i]); }
		ll ans = 0;
		int k;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					if(a[i] == (a[j] * a[k]) || a[j] == (a[i] * a[k]) || a[k] == (a[i]*a[j])){
						ans++;
					}
				}
			}
		}
		
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
};