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

int pos[200010];
int a[100001];

int main(){
	int tc,i,j,n;

	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);

		for(int i=0;i<=2*n;i++){
			pos[i] = 0;	
		}

		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			pos[a[i]] = i+1;
		}

		int cnt=0;
		for(int i=0;i<n;i++) {
			int bil = a[i];
			// printf("bil: %d\n", bil);
			for(j=1;;j++){
				ll kali = (ll)bil * j;
				if(kali > 2*n) {
					break;
				}
				// printf("kali: %lld pos[%d]: %d i: %d\n", kali, j, pos[j], i);
				if(pos[j] != 0 && kali == (pos[j] + i+1) && (i+1 < pos[j])) {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
};