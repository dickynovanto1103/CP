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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int a[51];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}


		bool found = false;
		for(i=0;i<n;i++){
			int sum = 0;
			for(j=0;j<n;j++){
				if(i == j){continue;}
				sum += a[j];
			}
			if(sum % (n-1) == 0) {
				int bagi = sum / (n-1);
				if(bagi == a[i]){
					found = true;
					break;
				}
			}
		}

		found ? puts("YES"): puts("NO");
	}
	
	return 0;
};