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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int s[maxn];
	for(i=1;i<=n;i++){
		s[i] = i;
	}
	sort(a+1,a+n+1);
	double minim = 1;
	for(i=1;i<=n;i++){
		// printf("a[%d]: %d\n",i,a[i]);
		if(s[i] < a[i]){

			printf("impossible\n");
			return 0;
		}else{
			minim = min(minim, (double)a[i]/(double)s[i]);
		}
	}
	printf("%.9lf\n",minim);
	return 0;
};