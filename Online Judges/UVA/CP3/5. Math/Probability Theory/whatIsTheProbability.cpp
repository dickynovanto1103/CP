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

int main(){
	int tc,n,idx;
	double p,q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %lf %d",&n,&p,&idx);
		q = 1.0 - p;
		int i;
		double ans = 0;
		for(i=0;i<100;i++){
			ans+=(p*pow(q,idx-1));
			// printf("%lf*%lf^(%d)\n",p,q,idx-1);
			// printf("ans jd: %lf\n",ans);
			idx+=n;

		}
		printf("%.4lf\n",ans);
	}
	return 0;
};