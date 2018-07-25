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

int n;
ll ans[13] = {4,10,20,35,56,83,116, 155, 198, 244, 292, 341,390};

int main(){
	
	scanf("%d",&n);
	if(n<=13){
		printf("%lld\n",ans[n-1]);
	}else{
		ll selisihIdx = (n-1) - 12;
		ll totalSelisih = selisihIdx*49LL;
		ll jawab = 390 + totalSelisih;
		// printf("totalSelisih: %lld\n",totalSelisih);
		printf("%lld\n",jawab);
	}

	return 0;
};