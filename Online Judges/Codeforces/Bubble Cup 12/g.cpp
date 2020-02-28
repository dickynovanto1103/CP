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
typedef vector<ll> vi;
typedef pair<ll,int> ii;
typedef vector<ii> vii;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	int temp[n+1][m+1];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			temp[i][j] = a[i][j];
		}
	}
	vii row, col;
	for(i=0;i<n;i++){
		ll sum = 0;
		for(j=0;j<m;j++){
			sum += a[i][j];
		}
		row.pb(ii(sum, i));
	}
	for(j=0;j<m;j++){
		ll sum = 0;
		for(i=0;i<n;i++){
			sum += a[i][j];
		}
		col.pb(ii(sum, j));
	}
	sort(row.begin(), row.end(), cmp); sort(col.begin(), col.end(), cmp);
	ll maks = 0;
	//fokus row dulu
	for(i=0;i<=min((int)row.size(), 4);i++){
		for(j=0;j<n;j++){
			for(int k=0;k<m;k++){
				a[j][k] = temp[j][k];
			}
		}
		int numRow = i, numCol = 4-i;
		ll ans = 0;
		for(j=0;j<i;j++) {
			ans += row[j].first;
			debug printf("j: %d row tambah %lld idx: %d ans jd: %lld\n",j,row[j].first, row[j].second,ans);
			for(int k=0;k<m;k++){
				a[row[j].second][k] = 0;
			}
		}
		vi listSumCol;
		for(j=0;j<m;j++){
			ll sum = 0;
			for(int k=0;k<n;k++){
				sum += a[k][j];
			}
			listSumCol.pb(sum);
		}
		sort(listSumCol.begin(), listSumCol.end());
		reverse(listSumCol.begin(),listSumCol.end());

		for(j=0;j<min(numCol, (int)listSumCol.size());j++){
			ans += listSumCol[j];
			debug printf("tambah col: %lld ans jd: %lld\n",listSumCol[j], ans);
		}
		maks = max(maks, ans);
	}

	//fokus kolom
	for(i=0;i<=min(4, (int)col.size());i++){
		for(j=0;j<n;j++){
			for(int k=0;k<m;k++){
				a[j][k] = temp[j][k];
			}
		}
		int numCol = i, numRow = 4-i;
		ll ans = 0;
		for(j=0;j<i;j++){
			ans += col[j].first;
			debug printf("j: %d col tambah %lld idx: %d ans jd: %lld\n",j,col[j].first, col[j].second,ans);
			for(int k=0;k<n;k++){
				a[k][col[j].second] = 0;
			}
		}

		vi listSumRow;
		for(j=0;j<n;j++){
			ll sum = 0;
			for(int k=0;k<m;k++){
				sum += a[j][k];
			}
			listSumRow.pb(sum);
		}
		sort(listSumRow.begin(), listSumRow.end());
		reverse(listSumRow.begin(), listSumRow.end());
		for(j=0;j<min(numRow, (int)listSumRow.size());j++){
			ans += listSumRow[j];
			debug printf("tambah row: %lld ans jd: %lld\n",listSumRow[j], ans);
		}
		maks = max(maks, ans);
	}
	printf("%lld\n",maks);
	return 0;
};