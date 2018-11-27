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
	scanf("%d %d",&n,&m);
	ll sum = 0;
	ll a[maxn];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		// a[i] = min(a[i], n);
		sum += a[i];
	}
	sort(a,a+n);
	ll elemen = a[n-1];
	ll pakai = elemen;
	ll ketinggian = elemen;

	for(i=n-2;i>=0;i--){
		if(ketinggian == 1){
			pakai++;
		}else{
			ketinggian = min(a[i], ketinggian - 1LL);
		}
	}
	printf("%lld\n",sum-pakai);

	return 0;
};