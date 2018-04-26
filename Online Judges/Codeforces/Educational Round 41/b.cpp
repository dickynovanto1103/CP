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
int awalAsli[maxn], akhirAsli[maxn];
int a[maxn], t[maxn], pref[maxn], suff[maxn], awal[maxn], akhir[maxn], asli[maxn];

int main(){
	int n,k,i,j;
	
	
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&t[i]);}
	for(i=0;i<n;i++){
		if(t[i]==0){asli[i] = 0;}
		else{asli[i] = a[i];}
	}

	//prefix and suffix sum of t
	pref[0] = t[0];
	awal[0] = a[0];
	awalAsli[0] = asli[0];
	for(i=1;i<n;i++){
		pref[i] = t[i] + pref[i-1];
		awal[i] = a[i] + awal[i-1];
		awalAsli[i] = asli[i] + awalAsli[i-1];
	}
	suff[n-1] = t[n-1];
	akhir[n-1] = a[n-1];
	akhirAsli[n-1] = asli[n-1];
	for(i=(n-2);i>=0;i--){
		suff[i] = suff[i+1] + t[i];
		akhir[i] = akhir[i+1] + a[i];
		akhirAsli[i] = akhirAsli[i+1] + asli[i];
	}

	int idxAwal = 0, idxAkhir = k-1;
	int sum = 0;
	int maks = 0;
	while(idxAkhir<n){
		sum = 0;
		if(idxAwal==0){sum+=awal[idxAkhir]; sum+=akhirAsli[idxAkhir+1];}
		else{
			sum+=(awal[idxAkhir] - awal[idxAwal-1]);
			sum+=akhirAsli[idxAkhir+1];
			sum+=awalAsli[idxAwal-1];
		}
		maks = max(maks, sum);
		idxAkhir++;
		idxAwal++;
	}
	printf("%d\n",maks);


	return 0;
};