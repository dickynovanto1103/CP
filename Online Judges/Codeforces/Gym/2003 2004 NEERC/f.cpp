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

int n,i,j,k;
int a[30], b[30];

int eval(int val){
	for(int i=0;i<=n;++i)
		b[n-i] = a[i];
	for(int i=0;i<n;++i){
		b[i+1] -= val * b[i];
	}
	return b[n];
}

int main(){
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
	scanf("%d", &n);
	for(i=0;i<=n;++i)
		scanf("%d", a+i);
	// int sq = sqrt(abs(a[n]));
	// for(i=1;i<=sq;++i){
	// 	if(a[n]%i == 0){
	// 		// cout<<i<<" "<<eval(i)<<" "<<eval(-i)<<endl;
	// 		if(eval(i)<=0 || eval(-i)<=0){
	// 			puts("NO");
	// 			return 0;
	// 		}
	// 		j = a[n]/i;
	// 		if(j != i && (eval(j)<=0 || eval(-j)<=0)){
	// 			puts("NO");
	// 			return 0;
	// 		}
	// 	}
	// }
	// puts("YES");
	if(n < 2)
		puts("YES");
	else if(n > 2)
		puts("NO");
	else
		puts(1LL*a[1]*a[1]<4LL*a[0]*a[2]?"YES" : "NO");
	return 0;
};