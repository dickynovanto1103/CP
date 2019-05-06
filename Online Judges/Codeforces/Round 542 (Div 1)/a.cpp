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

const int maxn = 5010;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int cnt[maxn], minim[maxn];
	memset(cnt, 0, sizeof cnt);
	for(i=1;i<=n;i++){minim[i] = inf;}
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int jarak;
		if(a < b){jarak = b-a;}
		else{jarak = n - (a-b);}
		minim[a] = min(minim[a], jarak);
		cnt[a]++;
	}
	// for(i=1;i<=n;i++){
	// 	printf("i: %d minim: %d cnt: %d\n",i,minim[i], cnt[i]);
	// }
	
	for(i=1;i<=n;i++){
		ll ans = 0;
		for(j=1;j<=n;j++){
			if(!cnt[j]){continue;}
			ll jarak = (cnt[j]-1)*n;
			jarak += minim[j];
			int penambahan;
			if(i < j){
				penambahan = (j-i);
				jarak += (j-i);
			}else if(i > j){
				penambahan = (n - (i-j));
				jarak += (n - (i-j));
			}else if(i == j){
				penambahan = 0;
			}

			// printf("i: %d j: %d penambahan: %d ans: %lld\n",i,j,penambahan,ans);
			ans = max(ans, jarak);
		}
		if(i>1){printf(" ");}
		printf("%lld",ans);
	}
	printf("\n");
	return 0;
};