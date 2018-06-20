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

const int maxn = 2e5 + 5;
ll counter[maxn];
ll sum[maxn];

int main(){
	int tc,n,q,i,j;
	int a[maxn];

	scanf("%d",&tc);
	while(tc--){
		memset(counter,0,sizeof counter);
		memset(sum,0,sizeof sum);
		scanf("%d %d",&n,&q);
		int maks = -1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			counter[a[i]]++;
			maks = max(maks, a[i]);
		}
		for(i=0;i<=(maks + 1);i++){
			
		}
		kk
		while(q--){
			int x;
			scanf("%d",&x);
		}
	}
	return 0;
};