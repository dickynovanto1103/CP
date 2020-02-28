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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int c,m,x;
		scanf("%d %d %d",&c,&m,&x);
		int minim = min(c,min(m,x));
		int ans = minim;
		c -= minim; m -= minim; x -= minim;
		if(c == 0 || m == 0){
			printf("%d\n",ans);
		}else{
			int maks = max(c,m);
			int minim = min(c,m);
			if(minim * 2 <= maks){
				ans += minim;
			}else{
				int selisih = maks - minim;
				ans += selisih;
				maks -= selisih*2;
				minim -= selisih;
				assert(maks == minim);
				ans += (maks*2 / 3);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
};