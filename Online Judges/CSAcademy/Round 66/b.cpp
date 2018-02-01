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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

bool cmp(ii a, ii b){
	if(a.first == b.first){return a.second > b.second;}
	return a.first < b.first;
}

ll sum[maxn];

int main(){
	int n,i,j;
	ll x;
	ii a[maxn];
	vector<ii> arr;
	scanf("%d %lld",&n,&x);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&a[i].first,&a[i].second);
		//nilaiMaks[a[i].first] = max(nilaiMaks[a[i].first],a[i].second);
	}
	sort(a,a+n,cmp);
	//memset(isVisited,false,sizeof isVisited);
	
	
	sum[0] = a[0].second;
	for(i=1;i<n;i++){
		sum[i] = sum[i-1] + a[i].second;
	}
	ll minim = x;
	for(i=0;i<n;i++){
		if(a[i].first<x){
			if((x-sum[i])<0){continue;}
			minim = min(minim,x-sum[i]);
		}
		else{
			if((a[i].first-sum[i])<0){continue;}
			minim = min(minim,a[i].first - sum[i]);
		}
	}
	printf("%lld\n",minim);

	return 0;
};