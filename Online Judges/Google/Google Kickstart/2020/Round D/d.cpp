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

int main(){
	int n,q,i,j;
	int tc;
	scanf("%d",&tc);
	int d[100001];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:",tt);
		scanf("%d %d",&n,&q);

		for(i=1;i<n;i++){
			scanf("%d",&d[i]);
		}
		for(i=0;i<q;i++){
			int s,k;
			scanf("%d %d",&s,&k);
			// printf("i: %d s: %d k: %d\n",i,s,k);
			if(s == 1 || s == n) {
				if(s == 1){
					printf(" %d",s + k - 1);
				}else{
					printf(" %d",n-k+1);
				}
			}else {
				int l = s-1, r = s;
				int room = s;
				k--;
				while(k--) {
					if(l == 0) {
						room = r +1;
						r = r + 1;
						continue;
					}
					if(r == n){
						room = l;
						l = l-1;

						continue;
					}
					if(d[l] < d[r]){
						room = l;
						l = l - 1;
					}else{
						room = r + 1;
						r = r + 1;
					}
				}
				printf(" %d",room);
			}
		}
		printf("\n");
	}

	
	return 0;
};