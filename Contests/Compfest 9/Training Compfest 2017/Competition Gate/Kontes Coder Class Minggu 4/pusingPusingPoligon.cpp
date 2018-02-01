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

int main() {
	int tc;
	double n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lf %lf",&n,&k);
		double sudut1 = pi/(n*k);
		double sudut2 = (pi/2.0)-(sudut1);
		double x = sin(sudut1)/sin(sudut2);
		printf("%.15lf\n",x*n*k);

	}
	return 0;
}