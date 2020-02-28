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

int main(){
	int q,i,j;
	ll n;
	scanf("%d",&q);
	ll a = 1350851717672992089;
	// printf("%lld\n",a);
	ll pangkat[38];
	pangkat[0] =1;
	for(i=1;i<38;i++){
		pangkat[i] = 3LL*pangkat[i-1];
	}
	while(q--){
		scanf("%lld",&n);
		ll temp = n;
		bool vis[40];
		memset(vis, false, sizeof vis);
		ll bil = 0;
		for(i=37;i>=0;i--){
			if(temp >= pangkat[i]){
				vis[i] = true;
				temp -= pangkat[i];
				bil += pangkat[i];
			}
		}
		for(i=0;i<=37;i++){
			if(bil >= n){break;}
			if(!vis[i]){
				bil += pangkat[i];
				vis[i] = true;
			}
		}
		if(bil < n){
			bil = a;
			for(i=0;i<38;i++){
				vis[i] = false;
			}
		}
		for(i=37;i>=0;i--){
			if(vis[i]){
				if(bil - pangkat[i] >= n){
					bil -= pangkat[i];
				}
			}
		}
		printf("%lld\n",bil);
	}
	return 0;
};