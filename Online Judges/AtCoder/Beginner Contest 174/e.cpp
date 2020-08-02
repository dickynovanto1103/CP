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

int a[200001];
int n,k;

bool can(int mid) {
	//harapannya bs panjangnya maks = mid
	int tot = 0;
	for(int i=0;i<n;i++){
		int banyak = a[i] / mid;
		if(a[i]%mid == 0){
			banyak--;
		}
		tot += banyak;
	}
	return tot <= k;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);

	int maks = 0, minim = inf;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		maks = max(maks, a[i]);
		minim = min(minim, a[i]);
	}

	int kiri = 1, kanan = maks, mid, ans;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		// printf("mid: %d\n",mid);
		if(can(mid)) {
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	
	printf("%d\n",ans);
	return 0;
};