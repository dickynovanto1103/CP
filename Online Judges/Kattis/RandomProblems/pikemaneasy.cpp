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

const int maxn = 1e4 + 4;
const ll mod = 1e9 + 7;

int main(){
	int n,t,i,j;
	ll a,b,c,waktu[maxn];
	scanf("%d %d %lld %lld %lld %lld",&n,&t,&a,&b,&c,&waktu[0]);
	for(i=1;i<n;i++){

		waktu[i] = ((a*waktu[i-1] + b)%c) + 1;
		// printf("waktu[%d]: %lld\n",i,waktu[i]);
	}
	sort(waktu, waktu+n);
	int cnt = 0;
	ll pen = 0;
	ll cur = 0;
	for(i=0;i<n;i++){
		// printf("i: %d\n",i);
		if(cur + waktu[i] <= t){
			cur += waktu[i];
			pen += cur;
			pen %= mod;
			// printf("cur jd: %lld pen jd: %lld\n", cur,pen);
			cnt++;
		}else{
			// printf("halo\n");
			break;
		}
	}
	printf("%d %lld\n",cnt,pen);
	return 0;
};