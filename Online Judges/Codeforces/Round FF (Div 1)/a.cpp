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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int decr[maxn], inc[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int cur = a[0];
	int len = 1;

	for(i=1;i<n;i++){
		if(a[i] > cur) {
			len++;
		}else{
			int panjang = 1;
			for(j=i-1;j>i-1-len;j--){
				inc[j] = panjang++;
			}
			panjang = 1;
			for(j=i-len;j<=i-1;j++){
				decr[j] = panjang++;
			}
			len = 1;
		}
		cur = a[i];
	}
	int panjang = 1;
	for(j=n-1;j>n-1-len;j--){
		inc[j] = panjang++;
	}
	panjang = 1;
	for(j=n-len;j<=n-1;j++){
		decr[j] = panjang++;
	}
	
	int maks = 0;
	for(i=0;i<n;i++){
		maks = max(maks, inc[i]);
	}

	maks = max(maks, 1 + inc[1]);
	maks = max(maks, 1 + decr[n-2]);
	for(i=1;i<n-1;i++){
		//ubah index i
		maks = max(maks, 1 + inc[i+1]);
		maks = max(maks, 1 + decr[i-1]);
		if((a[i+1] - a[i-1]) >= 2){
			maks = max(maks, 1 + inc[i+1] + decr[i-1]);
		}
	}
	printf("%d\n",maks);
	return 0;
};