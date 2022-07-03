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
	int n,i,j,a[1001], b[1001];
	while(scanf("%d",&n) != EOF) {
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		for(i=0;i<n;i++){scanf("%d",&b[i]);}

		int cnt = 0;
		for(i=0;i<n;i++){
			if(a[i] == b[i]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i != j && a[i] == b[j]) {
	  				cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	
	
	return 0;
};