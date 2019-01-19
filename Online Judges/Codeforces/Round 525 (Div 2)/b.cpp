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

int main(){
	priority_queue<int,vi, greater<int> > pq;
	int n,k,i,j;
	ll a[maxn];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	sort(a,a+n);
	ll sum = 0;

	for(i=0;i<n;i++){
		a[i] -= sum;
		if(a[i] > 0){
			printf("%lld\n",a[i]);
			sum += a[i];
			k--;
			if(k == 0){return 0;}
		}

	}
	while(k--){
		printf("0\n");
	}
	return 0;
};