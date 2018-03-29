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

const int maxn = 50010;

int main(){
	int n,i,j;
	double a[maxn];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}

	double it = 0;
	double minim = inf;
	for(it=0;it<10;it+=0.01) {
		double ans = 0;
		for(i=0;i<n;i++){
			ans+=(pow(abs(a[i]-it),1.5));
		}
		minim = min(minim,ans);
	}
	printf("minim: %.2lf\n",minim);

	return 0;
};