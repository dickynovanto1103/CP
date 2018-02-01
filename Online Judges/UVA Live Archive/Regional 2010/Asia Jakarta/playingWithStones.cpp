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

ll dfs(ll bil){
	if(bil%2==0){return bil/2;}
	return dfs(bil/2);
}

int main(){
	
	ll a[110];
	int i,j,n,tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		ll ans=0;
		for(i=0;i<n;i++){
			if(a[i]%2==0){ans^=(a[i]/2);}
			else{ans^=dfs(a[i]);}
		}
		if(ans==0){printf("NO\n");}
		else{printf("YES\n");}
	}
	return 0;
};