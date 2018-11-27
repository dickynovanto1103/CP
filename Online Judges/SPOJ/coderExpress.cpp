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

const int maxn = 1e3 + 3;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[maxn], lis[maxn], lds[maxn];
	vi seq;
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int len = 0;
		for(i=0;i<n;i++){
			int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
			int ukuran = seq.size();
			if(idx == ukuran){
				seq.pb(a[i]);
				len++;
				lis[i] = len;
			}else{
				seq[idx] = a[i];
				lis[i] = idx+1;
			}
		}
		seq.clear();
		len = 0;
		for(i=n-1;i>=0;i--){
			int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
			int ukuran = seq.size();

			if(idx == ukuran){
				seq.pb(a[i]);
				len++;
				lds[i] = len;
			}else{
				seq[idx] = a[i];
				lds[i] = idx+1;
			}
		}
		int ans = max(lds[0], lis[n-1]);
		for(i=1;i<(n-1);i++){
			ans = max(ans, lis[i] + lds[i] - 1);
		}
		printf("%d\n",ans);
		seq.clear();
	}
	return 0;
};