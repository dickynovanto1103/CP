#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(ll a, ll b){return a > b;}

int main() {
	ll n,i,a[10010],b[10010];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	sort(a,a+n);
	for(i=0;i<n;i++){scanf("%lld",&b[i]);}
	sort(b,b+n,cmp);
	/*printf("a:");
	for(i=0;i<n;i++){printf(" %lld",a[i]);}
	printf("\n");
	printf("b:");
	for(i=0;i<n;i++){printf(" %lld",b[i]);}
	printf("\n");*/
	ll sum = 0;
	for(i=0;i<n;i++){
		sum+=a[i]*b[i];
		//printf("%lld dikali dengan %lld sum jd: %lld\n",a[i],b[i],sum);
	}
	printf("%lld\n",sum);
	return 0;
}