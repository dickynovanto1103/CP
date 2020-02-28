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
	int n,i,j;
	while(scanf("%d",&n), n){
		int x[1010], y[1010];
		

		for(i=0;i<n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		if(n == 1){
			printf("1\n");
		}else{
			int ans = 2;
			for(i=0;i<n;i++){
				map<ii,int> mapper;
				map<ii,int>::iterator it;
				for(j=i+1;j<n;j++){
					int ye = y[j] - y[i];
					int ex = x[j] - x[i];
					// printf("i: %d j: %d ye: %d ex: %d\n",i,j,ye, ex);
					int gcd = __gcd(ye,ex);
					ye /= gcd; ex /= gcd;
					if(ex < 0){
						ex *= -1;
						ye *= -1;
					}

					if(ye == 0){
						mapper[ii(1,0)]++;
					}else if(ex == 0){
						mapper[ii(0,1)]++;
					}else{
						mapper[ii(ex,ye)]++;
					}
				}
				for(it=mapper.begin();it!=mapper.end();it++){
					ans = max(ans, it->second + 1);
				}
			}
			
			printf("%d\n",ans);
		}
	}
	return 0;
};