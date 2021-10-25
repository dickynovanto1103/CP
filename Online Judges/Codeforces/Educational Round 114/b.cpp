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

bool cmp(int a, int b) {
	return a > b;
}

int main(){
	int tc,a,b,c,m;
	scanf("%d",&tc);
	while(tc--){
		int a[3];
		scanf("%d %d %d %d",&a[0],&a[1],&a[2],&m);
		sort(a, a+3);

		int maxM = 0;
		for(int i=0;i<3;i++){
			maxM += a[i] - 1;
		}
		if(maxM < m) {
			printf("NO\n");
		}else if(maxM == m) {
			printf("YES\n");
		}else{
			int jumlah = a[0] + a[1];
			int selisih = a[2] - jumlah;
			int minimM = max(selisih - 1, 0);
			if(minimM > m) {
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}
	}
	
	return 0;
};