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
	int a[100];
	int i;
	a[0] = 0; a[1] = 1;
	for(i=2;i<=100;i++){
		a[i] = a[i-1] + a[i-2];
		if(a[i]>=1000){break;}
	}
	/*for(i=0;i<=17;i++){
		printf("%d\n",a[i]);
	}*/
	int n;
	while(scanf("%d",&n),n){
		double expected = (double)n * 1.6;
		int sum = 0;
		bool isHitOne = false;
		for(i=17;i>=2;i--){
			if(n>=a[i]){
				if(a[i]==1){isHitOne=true;}
				n-=a[i]; sum+=(a[i+1]);
			}
		}
		int sum1 = sum;
		if(isHitOne){sum1--;}//karena td ditambah 2..coba klo ditambah 1 doang

		double ans1 = (double)sum;
		double ans2 = (double)sum1;
		double ans = min(fabs(ans1-expected),fabs(ans2-expected));
		printf("%.2lf\n",ans);

	}
	return 0;
}