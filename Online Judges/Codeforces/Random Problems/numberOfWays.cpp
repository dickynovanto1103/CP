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

const int maxn = 5e5 + 4;

ll a[maxn];
ll prefix[maxn], suffix[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll sum = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(sum%3!=0){printf("0\n"); return 0;}
	ll hasilBagi = sum/3;
	vi idxPref, idxSuff;
	prefix[0] = a[0];
	if(prefix[0]==hasilBagi){idxPref.pb(0);}
	for(i=1;i<n;i++){
		prefix[i] = prefix[i-1] + a[i];
		if(prefix[i]==hasilBagi){idxPref.pb(i);}
	}
	suffix[n-1] = a[n-1];
	if(suffix[n-1]==hasilBagi){idxSuff.pb(n-1);}
	for(i=n-2;i>=0;i--){
		suffix[i] = suffix[i+1] + a[i];
		if(suffix[i]==hasilBagi){idxSuff.pb(i);}
	}
	reverse(idxSuff.begin(), idxSuff.end());
	// printf("idxSuff:\n");
	// for(i=0;i<idxSuff.size();i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",idxSuff[i]);
	// }
	// printf("\n");
	int ukuranPref = idxPref.size();
	sum = 0;
	for(i=0;i<ukuranPref;i++){
		int idx = idxPref[i];
		int idxLain = lower_bound(idxSuff.begin(), idxSuff.end(), idx+2) - idxSuff.begin();
		// printf("mencari idx: %d idxLain: %d\n",idx+2,idxLain);
		sum+=(idxSuff.size()-idxLain);
	}

	printf("%lld\n",sum);
	return 0;
};