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
	int n,i,j;
	ll a,b;
	double minim = (double)inf*3.0, maks = -minim, sum = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&a,&b);
		minim = min(minim, (double)a/(double)b);
		maks = max(maks, (double)a/(double)b);
		sum += (double)a/(double)b;
	}
	printf("%.9lf %.9lf %.9lf\n",minim,maks,sum);
	return 0;
};