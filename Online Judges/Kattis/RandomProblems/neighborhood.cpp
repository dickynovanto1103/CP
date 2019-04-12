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
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	int a[maxn];
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+k);
	ll sum = 0;
	for(i=1;i<=n;i++){
		int next = lower_bound(a,a+k, i) - a;
		if(next == k){break;}
		int bil = a[next];
		// printf("i: %d bil: %d\n",i,bil);
		int jarak = n - bil + 1;
		// printf("jarak: %d\n",jarak);
		sum += jarak;
	}
	printf("%lld\n",sum);
	return 0;
};