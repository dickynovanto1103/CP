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

const int maxn = 3e7 + 2;
const ll mod = 3e7;
ll a[maxn], hasil[maxn];
int counter[maxn];

int main(){
	int n,m,q;
	int i,j;
	scanf("%d %d %d",&n,&m,&q);
	for(i=0;i<m;i++){
		scanf("%lld",&a[i]);
		counter[a[i]]++;
	}
	for(i=m;i<n;i++){
		a[i] = a[i-m] + a[i-m+1];
		a[i] %=mod;
		counter[a[i]]++;
	}
	
	//sort
	int cnt = 0;
	for(i=0;i<maxn;i++){
		if(counter[i] == 0){continue;}
		while(counter[i]--) {
			hasil[cnt] = i;
			cnt++;
		}

	}
	while(q--){
		int idx = 0;
		scanf("%d",&idx);
		idx--;
		printf("%lld\n",hasil[idx]);
	}
	

	return 0;
};