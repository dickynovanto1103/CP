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

vi v;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int banyak;
			scanf("%d",&banyak);
			int sum = 0, bil;

			for(j=0;j<banyak;j++){

				scanf("%d",&bil);
				sum += bil;
			}
			v.pb(sum);
		}
		sort(v.begin(),v.end());
		double ans = 0;
		double time = 0;
		for(i=0;i<n;i++){
			time += v[i];
			ans += time;
		}
		ans /= (double)n;
		printf("%.10lf\n",ans);
		v.clear();
	}
	return 0;
};