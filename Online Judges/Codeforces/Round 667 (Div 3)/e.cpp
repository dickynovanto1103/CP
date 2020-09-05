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

int x[200001], y[200001], cnt[200001], koor[200001], pref[200001], jawab[200001], maksSuffix[200001];

int findMostRightIdx(int k, int start, int distinctPoint) {
	int next;
	int kiri = start, kanan = distinctPoint-1, mid, ans;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		if((koor[start] + k) >= koor[mid]) {
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ans;
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<=n;i++){
			cnt[i] = 0;
		}

		for(i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		sort(x, x+n);

		map<int,int> mapper;
		int idx = 0;
		for(i=0;i<n;i++){
			if(mapper.find(x[i]) == mapper.end()){
				mapper[x[i]] = idx;
				koor[idx] = x[i];
				idx++;
			}
		}
		for(i=0;i<n;i++){
			scanf("%d",&y[i]);
		}

		for(i=0;i<n;i++){
			int id = mapper[x[i]];
			cnt[id]++;
		}
		for(i=0;i<idx;i++){
			pref[i] = cnt[i];
			if(i){pref[i] += pref[i-1];}
		}


		//hitung banyak yg bs diambil klo start dari index ini
		for(i=0;i<idx;i++){
			//compute next max index
			int nextMaxIdx = findMostRightIdx(k, i, idx);
			int banyakPoint = pref[nextMaxIdx] - (i == 0 ? 0: pref[i-1]);
			jawab[i] = banyakPoint;
		}
		for(i=idx-1;i>=0;i--){
			if(i == (idx-1)){
				maksSuffix[i] = jawab[i];
			}else{
				maksSuffix[i] = max(maksSuffix[i+1], jawab[i]);
			}
		}

		int maks = 0;
		for(i=0;i<idx;i++){
			int nextMaxIdx = findMostRightIdx(k, i, idx);
			maks = max(maks, jawab[i] + (nextMaxIdx == (idx-1) ? 0 : maksSuffix[nextMaxIdx + 1]));
		}
		printf("%d\n",maks);
	}
	
	return 0;
};