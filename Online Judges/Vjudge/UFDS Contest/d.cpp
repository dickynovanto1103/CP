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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[101];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans = 0;
	bool vis[101];
	for(i=1;i<=n;i++){
		int b = i;
		int temp = b;
		memset(vis, false, sizeof vis);
		// printf("i: %d\n",i);
		while(b>=1){
			vis[b] = true;
			// printf("diclose: %d\n",b);
			b-=k;
		}
		b = temp;
		while(b<=n){
			vis[b] = true;
			// printf("close lg: %d\n",b);
			b += k;
		}
		int cnt0 = 0, cnt1 = 0;

		for(j=1;j<=n;j++){
			if(!vis[j]){
				// if(j == 2){
				// 	printf("a[%d]: %d\n",j,a[j]);	
				// }
				
				if(a[j] == -1){cnt0++;}
				else{cnt1++;}
			}
		}
		// printf("%s\n", );
		ans = max(ans, abs(cnt1 - cnt0));
	}
	printf("%d\n",ans);
	return 0;
};