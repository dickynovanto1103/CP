#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 201;

int main() {
	int tc,r,c,n,i,j,k;
	ll l;
	scanf("%d",&tc);
	ll a[maxn][maxn];
	while(tc--){
		scanf("%d %d %d %lld",&r,&c,&n,&l);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				a[i][j] = 1;
			}
		}
		while(n--){
			int r1,c1,r2,c2;
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			for(i=r1;i<=r2;i++){
				for(j=c1;j<=c2;j++){
					a[i][j] = -inf;
				}
			}
		}
		//jumlahin kolom
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(j>1){a[i][j]+=a[i][j-1];}
			}
		}
		ll maks = 0;
		for(i=1;i<=c;i++){
			for(j=i;j<=c;j++){
				ll temp = 0;
				for(int row = 1;row<=r;row++){
					if(i>1){temp+=a[row][j] - a[row][i-1];}
					else{temp+=a[row][j];}

					if(temp<0){temp=0;}
					maks = max(maks,temp);
					//printf("maks jd: %d\n",maks);
				}
			}
		}
		if(maks>=l){printf("YA\n");}
		else{printf("TIDAK\n");}
	}
	return 0;
}