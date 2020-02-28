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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vi a(n+1);
		vi minim(n+1);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		minim[n-1] = a[n-1];
		for(i=n-2;i>=0;i--){
			minim[i] = min(minim[i+1], a[i]);
		}
		int ans = 0;
		for(i=0;i<n-1;i++){
			if(a[i] > minim[i+1]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};