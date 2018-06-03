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
	int n,m,i,j;
	ll a[maxn], x[maxn], y[maxn], b[maxn];
	scanf("%d",&n);
	// ll idx[maxn];
	ll hargaMaks[2*maxn];
	memset(hargaMaks,-1,sizeof hargaMaks);
	int idx = 0;
	map<ll,int> mapper;
	for(i=0;i<n;i++){

		scanf("%lld %lld",&a[i],&x[i]);
		if(mapper.find(a[i]) == mapper.end()) {
			mapper[a[i]] = idx;
			hargaMaks[idx] = x[i];
			idx++;
		}else{
			int idx = mapper[a[i]];
			hargaMaks[idx] = max(hargaMaks[idx], x[i]);
		}
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%lld %lld",&b[i],&y[i]);
		if(mapper.find(b[i]) == mapper.end()) {
			mapper[b[i]] = idx;
			hargaMaks[idx] = y[i];
			idx++;
		}else{
			int idx = mapper[b[i]];
			hargaMaks[idx] = max(hargaMaks[idx], y[i]);
		}	
	}
	ll sum = 0;
	for(i=0;i<2*maxn;i++){
		if(hargaMaks[i]!=-1){
			sum+=(ll)hargaMaks[i];
		}
	}
	printf("%lld\n",sum);
	return 0;
};