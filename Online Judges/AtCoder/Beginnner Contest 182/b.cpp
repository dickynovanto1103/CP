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
	int n,i,j,a[101];
	while(scanf("%d",&n) != EOF) {
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int maks = 0, bil = 0;
		for(i=2;i<=1000;i++){
			int ans = 0;
			for(j=0;j<n;j++){
				if(a[j] % i == 0){
					ans++;
				}
			}
			if(ans > maks){
				maks = ans;
				bil = i;
			}
		}
		printf("%d\n",bil);
	
	}
	
	return 0;
};