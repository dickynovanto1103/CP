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

const int maxn = 1010;

int p[maxn][maxn];

int main(){
	int h,w,i,j;
	scanf("%d %d",&h,&w);
	int r[maxn], c[maxn];
	memset(p, -1, sizeof p);
	for(i=0;i<h;i++){
		scanf("%d",&r[i]);
		if(!r[i]){
			p[i][0] = 0;
		}else{
			for(j=0;j<r[i];j++){
				p[i][j] = 1;
			}
			p[i][j] = 0;
		}
	}
	for(i=0;i<w;i++){
		scanf("%d",&c[i]);
		if(!c[i]){
			if(p[0][i] == 1){
				printf("0\n");
				return 0;
			}
			p[0][i] = 0;
		}else{
			for(j=0;j<c[i];j++){
				if(!p[j][i]){
					printf("0\n");	
					return 0;
				}
				p[j][i] = 1;
			}
			if(p[j][i] == 1){
				printf("0\n");
				return 0;
			}
			p[j][i] = 0;
		}
	}
	ll ans = 1;
	ll mod = 1e9 + 7;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			// printf("%d ",p[i][j]);
			if(p[i][j] == -1){
				ans *= 2;
				ans %= mod;
			}
		}
		// printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
};