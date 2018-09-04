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

const int maxn = 3e5 + 5;

ii intersect(int l, int r, int i, int j){
	// printf("l: %d r: %d i: %d j: %d\n",l,r,i,j);
	if(l > j || r < i){return ii(-1,-1);}
	if(i<=l && r<=j){
		return ii(l,r);
	}
	if(l<=i && j<=r){
		return ii(i,j);
	}
	if(r >= i && j>=r){
		return ii(i,r);
	}
	if(l <= j && i<=l){
		return ii(l,j);
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn],b[maxn];
	
	for(i=0;i<n;i++){scanf("%d %d",&a[i],&b[i]);}
	ii pref[maxn], suff[maxn];
	
	int kiri = a[0],kanan = b[0];
	pref[0].first = a[0]; pref[0].second = b[0];
	suff[n-1].first = a[n-1]; suff[n-1].second = b[n-1];
	for(i=1;i<n;i++){
		pref[i] = intersect(pref[i-1].first, pref[i-1].second, a[i], b[i]);
		// printf("pref[%d]: %d %d\n",i,pref[i].first, pref[i].second);
	}
	for(i=n-2;i>=0;i--){
		suff[i] = intersect(suff[i+1].first, suff[i+1].second, a[i], b[i]);
		// printf("suff[%d]: %d %d\n",i,suff[i].first, suff[i].second);
	}

	int maks = 0;
	maks = max(maks, suff[1].second - suff[1].first);
	maks = max(maks, pref[n-2].second - pref[n-2].first);
	for(i=1;i<(n-1);i++){
		ii hasilIntersect = intersect(pref[i-1].first, pref[i-1].second, suff[i+1].first, suff[i+1].second);
		maks = max(maks, hasilIntersect.second - hasilIntersect.first);
	}

	printf("%d\n",maks);
	return 0;
};