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

const int maxn = 110;

int main(){
	int n,i,j;
	int seharusnya1[maxn];
	int seharusnya2[maxn];
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n/2;i++){scanf("%d",&a[i]);}

	sort(a,a+(n/2));
	// for(i=0;i<n/2;i++){printf("%d\n",a[i]);}
	int cnt = 0;
	for(i=1;i<=n;i+=2){seharusnya1[cnt] = i; cnt++; }
	cnt = 0;
	for(i=2;i<=n;i+=2){seharusnya2[cnt] = i; cnt++; }
	int ans1 = 0, ans2 = 0;
	cnt = 0;
	for(i=0;i<n/2;i++){
		ans1+=(abs(seharusnya1[cnt] - a[i]));
		ans2+=(abs(seharusnya2[cnt] - a[i]));
		cnt++;
	}
	printf("%d\n",min(ans1,ans2));
	return 0;
};