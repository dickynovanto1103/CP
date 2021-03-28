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

int compute(vi a){
	int ans = 0;
	int n = a.size();
	int i,j;
	for(i=0;i<n-1;i++){
		int minim = a[i], minIdx = i;
		for(j=i;j<n;j++){
			if(minim > a[j]) {
				minim = a[j];
				minIdx = j;
			}
		}
		ans += (minIdx - i + 1);
		reverse(a.begin()+i, a.begin()+minIdx+1);
		// printArray(n, a);
	}
	return ans;
}

int main(){
	int i,j;
	for(i=2;i<=10;i++){
		bool vis[100];
		memset(vis, false, sizeof vis);
		vi a;
		for(j=0;j<i;j++){
			a.pb(j);
		}
		int minim = inf, maks = -inf;
		do{
			int ans = compute(a);
			vis[ans] = true;
			minim = min(minim, ans);
			maks = max(maks, ans);
		}while(next_permutation(a.begin(), a.end()));
		printf("%d -> %d %d ",i, minim, maks);
		bool visitedAll = true;
		for(j=minim;j<=maks;j++){
			if(!vis[j]){
				visitedAll = false;
				break;
			}
		}
		printf("visitedAll: %d\n", visitedAll);

	}
	
	return 0;
};