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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int awal[maxn], akhir[maxn];
int a[maxn];
int cnt[maxn];
bool vis[maxn];

vector<vi> adj;

ii merge(ii a, ii b){
	int minim = min(a.first, b.first);
	int maks = max(a.second, b.second);
	return ii(minim, maks);
}

ii mergeAll(ii range, int begin, int end) {
	int i,j;
	for(i=begin;i<=end;i++){
		range = merge(range, ii(awal[a[i]], akhir[a[i]]));
		vis[i] = true;
	}
	return range;
}

ii getRange(ii a, ii b){
	if(a == ii(-1,-1)){return b;}
	else{
		return ii(a.second + 1, b.second);
	}
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	
	memset(cnt, 0, sizeof cnt);	
	memset(awal, -1, sizeof awal);
	memset(vis, false, sizeof vis);
	adj.assign(maxn, vi());
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		adj[a[i]].pb(i);
		if(awal[a[i]] == -1){
			awal[a[i]] = akhir[a[i]] = i;
		}else{
			akhir[a[i]] = i;
		}
	}

	int ans = 0;

	for(i=0;i<n;i++){
		if(!vis[i]) {
			int begin = awal[a[i]];
			int end = akhir[a[i]];
			ii range = ii(awal[a[i]], akhir[a[i]]);
			ii rangeResult = range;
			do{
				range = rangeResult;
				rangeResult = mergeAll(range, begin, end);
				ii temp = getRange(range, rangeResult);
				begin = temp.first, end = temp.second;
			}while(range != rangeResult);
			
			// printf("range: %d %d\n",range.first, range.second);
			// dah dapet range
			// printf("begin: %d end: %d\n",begin, end);
			int maks = 0;
			vi listBil;
			for(j=range.first;j<=range.second;j++){
				if(cnt[a[j]] == 0){
					listBil.pb(a[j]);
				}
				cnt[a[j]]++;
				maks = max(maks, cnt[a[j]]);
			}
			// printf("maks: %d\n",maks);
			ans += (range.second-range.first+1) - maks;
			for(j=0;j<listBil.size();j++){
				int bil = listBil[j];
				cnt[bil] = 0;
			}

		}
	}
	printf("%d\n",ans);
	
	return 0;
};