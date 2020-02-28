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
	int n,k,m,i,j;
	scanf("%d %d %d",&n,&k,&m);
	int a[101];
	int sum = 0;
	for(i=0;i<n-1;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int tot = n*m;
	int x = tot - sum;
	if(x < 0){
		x = 0;
	}
	if(x >= 0 && x <= k){
		printf("%d\n",x);
	}else{
		printf("-1\n");
	}
	return 0;
};