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

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(a[0]!=0){printf("-1\n"); return 0;}
	for(i=0;i<(n-1);i++){
		if((a[i+1] - a[i])>=2){printf("-1\n"); return 0;}
	}
	ll ans = 0;
	int x[maxn];
	memset(x,0,sizeof x);

	for(i=(n-1);i>=1;i--){
		// printf("i: %d\n",i);
		x[i] = a[i];
		ans+=a[i];
		int cnt = a[i];
		// printf("cntAwal: %d\n",cnt);
		// printf("ans jd: %lld\n",ans);
		for(j=i;j>=0;j--){
			// printf("j: %d\n",j);
			// printf("cnt sekarang: %d\n",cnt);
			if(a[j]!=cnt){
				i = j+1;
				// printf("i jd: %d\n",i);
				break;
			}
			x[j] = cnt;
			cnt--;
			// printf("cnt: %d\n",cnt);
			if(cnt==0){
				i = j;
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
};