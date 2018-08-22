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

const int maxn = 150010;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn],b[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	int gcd1 = a[n-1], gcd2 = b[n-1];
	// printf("gcd1: %d gcd2: %d\n",gcd1,gcd2);
	for(i=n-2;i>=0;i--){
		gcd1 = max(__gcd(gcd1, a[i]), __gcd(gcd1, b[i]));
		gcd2 = max(__gcd(gcd2, a[i]), __gcd(gcd2, b[i]));
		// printf("gcd1: %d gcd2: %d\n",gcd1,gcd2);
		// printf("gcd1 jadi: %d gcd2 jd: %d\n",gcd1,gcd2);
	}
	int gcdGenap = gcd1, gcdGanjil = gcd2;
	if(gcdGenap == 1 && gcdGanjil == 1){
		printf("-1\n");
	}else{
		printf("%d\n",max(gcdGenap, gcdGanjil));
	}
	return 0;
};