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
	int n;
	double a,b;
	scanf("%d",&n);
	//printf("n: %d\n",n);
	double per = inf;
	int ans;
	for(int i=1;i<=n;i++){
		//printf("i: %d\n",i);
		scanf("%lf %lf",&a,&b);
		//printf("%ld\n",b/a);
		if(per>(b/a)){per = b/a; ans = i;}
	}
	printf("%d\n",ans);
	return 0;
};