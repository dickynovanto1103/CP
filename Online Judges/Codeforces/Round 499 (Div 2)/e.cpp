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

const int maxn = 1e5 + 5;;



int main(){
	int n,k,i,j;
	int a[maxn];
	
	scanf("%d %d",&n,&k);
	
	int gcd = 0;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]%=k;
		gcd = __gcd(gcd, a[i]);
	}

	vi ans;

	int awal = gcd;
	ans.pb(awal);
	int next = (awal+awal)%k;
	while(next!=awal){
		ans.pb(next);
		next+=gcd;
		next%=k;
	}

	sort(ans.begin(), ans.end());

	int cnt = ans.size();
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};