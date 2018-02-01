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
	double s,p[55],k;
	int q,i,j;
	scanf("%lf %d %lf",&s,&q,&k);
	for(i=0;i<q;i++){
		scanf("%lf",&p[i]);
	}
	sort(p,p+q);
	double maks = 0;
	for(i=0;i<=q;i++){
		double uang = s;
		for(j=0;j<i;j++){
			uang+=k;
		}
		for(j=i;j<q;j++){
			uang = uang*(1+p[j]/100.0);
		}
		maks = max(maks,uang);
	}
	printf("%.10lf\n",maks);
	return 0;
};