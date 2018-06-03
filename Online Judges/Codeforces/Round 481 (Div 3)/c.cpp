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

const int maxn = 2e5 + 5;

int main(){
	int n,m,i,j;
	ll a[maxn], pref[maxn];
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){

		scanf("%lld",&a[i]);
		if(i == 0){pref[i] = a[i];}
		else{pref[i] = pref[i-1] + a[i];}
	}
	for(i=0;i<m;i++){
		ll nomor;
		scanf("%lld",&nomor);
		//cari idx
		int idx = lower_bound(pref,pref+n,nomor) - pref;
		if(idx==0){
			printf("%d %lld\n",idx+1,nomor);
		}else{
			printf("%d %lld\n",idx+1,nomor - pref[idx-1]);
		}
	}
	return 0;
};