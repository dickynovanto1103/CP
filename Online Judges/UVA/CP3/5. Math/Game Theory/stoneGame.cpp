#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j;
	while(scanf("%d",&n),n){
		vi a;
		ll bil;
		bool found = false;
		for(i=0;i<n;i++){scanf("%lld",&bil); a.pb(bil);}
		for(i=0;i<n;i++){
			ll hasilXor = 0;
			for(j=0;j<n;j++){
				if(i!=j){
					hasilXor^=a[j];
				}
			}
			if(a[i]>hasilXor){found = true; break;}
		}
		if(found){printf("Yes\n");}
		else{printf("No\n");}
	}
	return 0;
}