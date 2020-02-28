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
typedef pair<double,int> ii;
typedef vector<ii> vii;

int main(){
	int i,j;
	ll n;
	scanf("%lld",&n);
	int a[5], b[5];
	double aPerB[5], bPerA[5];
	for(i=0;i<3;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<3;i++){
		scanf("%d",&b[i]);
	}
	set<pair<double, int> > s1, s2, temp;
	for(i=0;i<3;i++){
		aPerB[i] = a[i]/b[i];
		bPerA[i] = b[i]/a[i];
		s1.insert(ii(aPerB[i], i));
		s2.insert(ii(bPerA[i],i));
	}
	//tinjau s2 dulu
	temp = s2;
	int cnt[3] = {0};
	vi listIdx;
	for(i=0;i<3;i++){
		ii back = *(--s2.end());
		s2.erase(--s2.end());

		int idx = back.second;
		if(b[idx] <= a[idx]){break;}
		else{listIdx.pb(idx);}
		//tuker sebanyak a[idx];
		// cnt[idx] += n/a[idx];
		// n %= a[idx];
	}
	if(listIdx.size() == 1){
		int idx = listIdx[i];
		cnt[idx] += n/a[idx];
		n %= a[idx];
	}else{
		//ambil 2 aja
		for(i=n)
	}
	for(i=0;i<listIdx.size())
	s2 = temp;

	//tinjau s1
	//jadiin acorn semua dulu

	for(i=0;i<3;i++){
		n += (ll)cnt[i]*b[i];
		cnt[i] = 0;
	}
	temp = s1;
	for(i=0;i<3;i++){
		ii back = *(--s1.end());
		s1.erase(--s1.end());
		int idx = back.second;
		if(a[idx] <= b[idx]){break;}
		//tuker sebanyak b[idx];
		cnt[idx] += n/b[idx];
		n %= b[idx];
	}
	s1 = temp;
	//saatnya jadiin acorn lg
	for(i=0;i<3;i++){
		n += (ll)cnt[i]*a[i];
		cnt[i] = 0;
	}
	printf("%lld\n",n);
	return 0;
};