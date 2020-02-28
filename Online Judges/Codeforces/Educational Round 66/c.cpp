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

const int maxn = 2e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[maxn];
	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int kiri = 0, kanan = k;
		int ans = -1, minimVal = inf*2;
		for(i=kanan;i<n;i++){
			int tengah = (a[kiri] + a[i]) / 2;
			int maks = max(abs(a[kiri]-tengah), abs(a[i] - tengah));
			if(minimVal > maks) {
				ans = tengah;
				minimVal = maks;
			}
			kiri++;
		}
		
		printf("%d\n",ans);
	}
	return 0;
};