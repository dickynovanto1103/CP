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
	double a;
	while(scanf("%lf",&a), fabs(a) >= eps) {
		double sum = 0;
		int per = 2;
		int ans = 0;
		while(sum < a){
			sum += 1.0/(double)per;
			per++;
			ans++;
		}
		printf("%d card(s)\n",ans);
	}
	return 0;
};