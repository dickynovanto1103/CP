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

const int maxn = 1e5 + 5;
int bit[maxn];
int n;

void update(int node, int val){
	for(int i=node;i<maxn;i+=(i&-i)){
		bit[i]+=val;
	}
}

int get(int idx){
	int sum = 0;
	for(int i=idx;i>0;i-=(i&-i)){
		sum+=bit[i];
	}
	return sum;
}

void printArrayBIT(){
	int i;
	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		printf("%d",bit[i]);
	}
	printf("\n");
}

const ll mod = 1e9 + 7;

int main(){
	int i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll jawab = 0;
	for(i=n;i>=1;i--){
		int bil = a[i];
		int ans1 = get(maxn-1);
		int ans2 = get(bil-1);
		
		ll ans = ans1 - ans2;
		jawab+=((ll)(ans*(ans+1))/2LL);
		jawab%=mod;
		
		update(a[i], 1);
		
	}

	jawab+=n;
	jawab%=mod;
	printf("%lld\n",jawab);
	return 0;
};