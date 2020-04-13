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

int cnt[200001];
int temp[200001];

bool can(int n, int mid) {
	int i,j;

	bool ketemu = false;
	int idx = 1;
	int maks = -1;
	
	for(i=1;i<=n;i++){temp[i] = cnt[i];}
	for(i=1;i<=n;i++){
		if(temp[i] >= mid){
			ketemu = true;
			if(maks < temp[i]){
				maks = temp[i];
				idx = i;
			}
		}
	}
	if(!ketemu){
		return false;
	}
	temp[idx] -= min(maks, mid);
	// printf("maks: %d\n",maks);
	// printf("temp[%d]: %d\n",idx, temp[idx]);
	int cnt1 = 0;
	for(i=1;i<=n;i++){
		if(temp[i] >= 1){
			cnt1++;
		}
	}
	if(cnt1 >= mid){return true;}
	return false;
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			cnt[i] = 0;
			temp[i] = 0;
		}
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			cnt[bil]++;
		}
		int kiri = 0, kanan = n, mid, ans;
		while(kiri <= kanan){
			mid = (kiri+kanan)/2;
			// printf("mid: %d\n",mid);
			if(can(n, mid)){
				ans = mid;
				kiri = mid+1;
			}else{
				kanan = mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};