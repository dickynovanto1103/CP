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

const int maxn = 2010;

int main(){
	int i,j;
	int n,a[maxn];
	scanf("%d",&n);
	int maks = 0;
	for(i=1;i<=n;i++){scanf("%d",&a[i]); maks = max(maks, a[i]);}
	int selisih = 1000000 - maks;
	printf("%d\n",n+1);
	printf("1 %d %d\n",n,selisih);
	for(i=1;i<=n;i++){
		a[i] += selisih;
	}
	for(i=1;i<=n;i++){
		int modWanted = i-1;
		int bil = a[i] - modWanted;
		printf("2 %d %d\n",i,bil);
		a[i]%=bil;
	}
	// for(i=1;i<=n;i++){
	// 	printf("%d ",a[i]);
	// }
	return 0;
};