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
	double ans = 0;
	for(i=1;i<=n;i++){
		int cur = i;
		int cnt = 0;
		while(cur < k){
			cur *= 2;
			cnt++;
		}
		double jawab = (1.0/(double)n) * (1.0/(double)pow(2,cnt));
		// printf("i: %d cnt: %d\n",i,cnt);
		ans += jawab;
	}
	printf("%.12lf\n",ans);
	return 0;
};