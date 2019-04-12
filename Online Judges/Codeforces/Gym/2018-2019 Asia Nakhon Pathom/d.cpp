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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e6 + 6;

int a[maxn];

bool can(int mid, int n) {
	int i,j;
	int sekarang = a[0] + 10;
	int cnt = 1;
	for(i=0;i<n;i++){
		if(abs(a[i] - sekarang) > 10){
			sekarang = a[i] + 10;
			cnt++;
		}
	}
	if(cnt <= mid){return true;}
	cnt = 1;
	sekarang = a[n-1] - 10;
	for(i=n-1;i>=0;i--){
		if(abs(a[i] - sekarang) > 10){
			sekarang = a[i] - 10;
			cnt++;
		}
	}
	if(cnt<=mid){return true;}
	return false;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		if(n == 0){printf("0\n"); continue;}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int kiri = 1, kanan = 2000001, mid, ans;
		while(kiri <= kanan) {
			mid = (kiri+kanan)/2;
			if(can(mid, n)){
				ans = mid;
				kanan = mid-1;
			}else{
				kiri = mid + 1;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};