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

int n,m;

bool isOutOfMatrix(ii p) {
	return !(p.first >= 1 && p.first <= n && p.second >= 1 && p.second <= m);
}

vii getCellsFrom(ii point, int dist) {
	vii ans;
	if(point == ii(1,1)) {
		for(int i=0;i<=dist;i++){
			int dx = i;
			int dy = dist - i;
			ii tujuan = ii(point.first + dx, point.second + dy);
			if(isOutOfMatrix(tujuan)){
				continue;
			}
			ans.pb(tujuan);
		}
	}else{
		for(int i=0;i<=dist;i++){
			int dx = i;
			int dy = dist - i;
			ii tujuan = ii(point.first - dx, point.second - dy);
			if(isOutOfMatrix(tujuan)){
				continue;
			}
			ans.pb(tujuan);
		}
	}
	return ans;
}

bool isVectorSame(const vii& a, const vii& b){
	if(a.size() != b.size()){return false;}
	for(int i=0;i<a.size();i++){
		if(a[i] != b[i]){return false;}
	}
	return true;
}

int main(){
	int tc,i,j;
	int a[31][31];
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		int cnt1 = 0, cnt0 = 0;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j] == 1){cnt1++;}
				else{cnt0++;}
			}
		}
		int ans = min(cnt0, cnt1);

		int jarak = n + m - 2;
		int jawab = 0;
		for(i=0;i<=jarak/2;i++){
			//need to check cells with dist = i from (1,1) and from (n,m)
			//check in n^2..for each cells with dist = i from (1,1), check with all cells with dist = i from (n,m)...check the cnt1 count and cnt0 count of those cells
			//find minimum, add to ans
			int dist = i;
			vii awal = getCellsFrom(ii(1,1), dist);
			vii akhir = getCellsFrom(ii(n,m), dist);

			sort(awal.begin(), awal.end());
			sort(akhir.begin(), akhir.end());

			if(isVectorSame(awal, akhir)){
				break;
			}

			int cnt0 = 0, cnt1 = 0;
			for(j=0;j<awal.size();j++){
				int x = awal[j].first, y = awal[j].second;
				
				if(a[x][y] == 1){cnt1++;}
				else{cnt0++;}
			}
			for(j=0;j<akhir.size();j++){
				int x = akhir[j].first, y = akhir[j].second;
				
				if(a[x][y] == 1){cnt1++;}
				else{cnt0++;}
			}
		

			jawab += min(cnt1, cnt0);
		}
		ans = min(ans, jawab);

		printf("%d\n",ans);
	}
	
	return 0;
};