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

bool cmp1(int a, int b){
	return a > b;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	vector<vi> a, temp;
	int a[n+1][m+1];
	int temp[n+1][m+1];
	int totRow[n+1], totCol[m+1];
	
	vi v;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int bil;
			scanf("%d",&bil);
			v.pb(bil);
			// temp[i][j] = a[i][j];
		}
	}

	if(n > m){
		
	}
	for(i=0;i<n*m;i++){

	}

	vii row, col;
	for(i=0;i<n;i++){
		ll sum = 0;
		for(j=0;j<m;j++){
			sum += a[i][j];
		}
		totRow[i] = sum;
		row.pb(ii(sum, i));
	}
	for(j=0;j<m;j++){
		ll sum = 0;
		for(i=0;i<n;i++){
			sum += a[i][j];
		}
		totCol[j] = sum;
		col.pb(ii(sum, j));
	}
	sort(row.begin(), row.end(), cmp); sort(col.begin(), col.end(), cmp);
	ll maks = 0;
	ll ans = 0;
	for(i=0;i<min((int)row.size(), 4);i++){
		ans += row[i].first;
	}
	maks = max(maks, ans);
	ans = 0;
	for(i=0;i<min((int)col.size(), 4);i++){
		ans += col[i].first;
	}
	maks = max(maks, ans);
	bool isRowSmaller = (n <= m);

	for(int tt=1;tt<=3;tt++){
		vi listBil;

		if(tt == 1) {
			if(isRowSmaller){
				for(i=0;i<n;i++) {
					ll ans = row[i].first;
					for(j=0;j<m;j++){
						totCol[j] -= a[row[i].second][j];
						a[row[i].second][j] = 0;
					}

					vi listBil;
					for(j=0;j<m;j++){
						listBil.pb(totCol[j]);
					}
					sort(listBil.begin(), listBil.end(), cmp1);
					for(j=0;j<3;j++){
						ans += listBil[j];
					}
					maks = max(maks, ans);
					for(j=0;j<m;j++){
						a[row[i].second][j] = temp[row[i].second][j];
						totCol[j] += a[row[i].second][j];
					}
				}	
			}else{
				for(i=0;i<m;i++){
					ll ans = col[i].first;
					for(j=0;j<n;j++){
						totCol[j] -= a[row[j].second][j];
						a[row[i].second][j] = 0;
					}

					vi listBil;
					for(j=0;j<m;j++){
						listBil.pb(totCol[j]);
					}
					sort(listBil.begin(), listBil.end(), cmp1);
					for(j=0;j<3;j++){
						ans += listBil[j];
					}
					maks = max(maks, ans);
					for(j=0;j<m;j++){
						a[row[i].second][j] = temp[row[i].second][j];
						totCol[j] += a[row[i].second][j];
					}
				}
			}
			
		}
		
	}

	return 0;
};