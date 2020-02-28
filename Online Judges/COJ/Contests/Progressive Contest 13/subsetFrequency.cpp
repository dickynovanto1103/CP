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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bitset<200000001> bit;
vi list1;

bool cmp(ii a, ii b){
	if(a.second == b.second){return a.first < b.first;}
	return a.second > b.second;
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	bit.reset();
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		list1.pb(bil);
		bit[list1[i]] = true;
		// s.insert(bil); temp.insert(bil);
	}
	sort(list1.begin(), list1.end());
	vi a(k);
	for(i=0;i<k;i++) {
		scanf("%d",&a[i]);
	}
	vii ans;
	int cnt[1000];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		int bil = list1[i];
		for(j=0;j<k;j++) {
			int sum = a[j];
			int cari = sum - bil;
			if(cari < 0){continue;}
			if(bit[cari] && cari != bil) {
				cnt[j]++;
			}
		}
	}
	for(i=0;i<k;i++){
		if(cnt[i]){
			ans.pb(ii(a[i], cnt[i]));
		}
	}
	// for(i=0;i<k;i++) {
	// 	int sum = a[i];
	// 	int tot = 0;
	// 	for(j=0;j<n;j++){
	// 		int kurang = sum - list1[j];
	// 		if(kurang <= 0){continue;}
	// 		if(kurang == list1[j]){continue;}

	// 		if(bit[kurang]){tot++;}
	// 	}
	// 	if(tot){ans.pb(ii(sum, tot));}
	// }
	sort(ans.begin(), ans.end(), cmp);
	for(i=0;i<ans.size();i++){
		printf("%d %d\n", ans[i].first, ans[i].second/2);
	}

	return 0;
};