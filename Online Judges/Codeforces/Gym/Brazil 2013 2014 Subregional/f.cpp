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

ll a[300003];

int main(){
	int sum, n, len,c=0;
	scanf("%d", &n);
	sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld", a+i);
		a[i+2*n] = a[i];
		a[i+n] = a[i];
		sum += a[i];
	}
	if(sum%3){
		puts("0");
		return 0;
	}
	len = sum/3;
	for(int i=1;i<3*n;i++){
		a[i] += a[i-1];
	}
	for(int i=0;i<n;i++){
		int k = i;
		int idx = lower_bound(a+k, a+3*n, a[k]+len)-a;
		if(idx>=3*n||a[idx]-a[k] != len)
			continue;
		k = idx;
		idx = lower_bound(a+k, a+3*n, a[k]+len)-a;
		if(idx>=3*n||a[idx]-a[k] != len)
			continue;
		c++;
	}
	printf("%d\n", c/3);
	return 0;
};