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

const int maxn = 1e5 + 5;

double power(double a, int b){
	if(b==0){return 1.0;}
	else{
		if(b%2==0){
			double temp = power(a,b/2);
			return temp*temp;
		}else{
			return a*power(a,b-1);
		}
	}
}

int main(){
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	double ans = 0;
	for(i=1;i<=m;i++){
		// printf("i: %d\n",i);
		ans += (double)i*power((double)i/(double)m, n);
		// printf("ans1 jd: %lf\n",ans);
		ans -= (double)i*power((double)(i-1)/(double)m, n);
		// printf("ans2 jd: %lf\n",ans);
	}
	printf("%.9lf\n",ans);
	return 0;
};