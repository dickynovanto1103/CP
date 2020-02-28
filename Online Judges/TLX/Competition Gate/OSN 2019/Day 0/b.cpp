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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

bool cmp(ii a, ii b){
	return a.second > b.second;
}

int main(){
	int n,p,q,i,j;
	scanf("%d %d %d",&n,&p,&q);
	int val[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	set<int> s;
	int a[maxn], b[maxn];
	bool ada[maxn], adaDiB[maxn];
	memset(ada, false, sizeof ada); memset(adaDiB, false, sizeof adaDiB);
	for(i=0;i<p;i++){
		scanf("%d",&a[i]);
		ada[a[i]] = true;
	}
	vii listBil;
	for(i=0;i<q;i++){
		scanf("%d",&b[i]);
		if(ada[b[i]]){
			listBil.pb(ii(b[i], val[b[i]]));
		}
		adaDiB[b[i]] = true;
	}

	sort(listBil.begin(), listBil.end(), cmp);
	ll sum = 0;
	for(i=0;i<listBil.size();i+=2){
		sum += listBil[i].second;
	}
	for(i=0;i<p;i++){
		if(!adaDiB[a[i]]){
			sum += val[a[i]];
		}
	}
	printf("%lld\n",sum);

	return 0;
};