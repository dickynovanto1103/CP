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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[200000];

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i){a[i] += a[i-1];}
	}
	int ans = inf;
	int idx;
	for(i=0;i<=n-k;i++){
		if(ans > a[i+k-1] - (i == 0 ? 0 : a[i-1])){
			ans = a[i+k-1] - (i == 0 ? 0 : a[i-1]);
			idx = i+1;
		}
	}
	printf("%d\n",idx);
	return 0;
};