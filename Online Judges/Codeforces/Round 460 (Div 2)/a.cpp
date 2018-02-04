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
	int n,m,a,b,i,j;
	scanf("%d %d",&n,&m);
	double minim = inf;
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		minim = min(minim, (double)a/(double)b);
	}
	printf("%.8lf\n",minim*m);
	return 0;
};