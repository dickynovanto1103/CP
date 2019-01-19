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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e3 + 3;

int a[maxn];
int pref[maxn][2], suff[maxn][2], mid[maxn][maxn][2][2];

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
		pref[i][a[i]]++;
		suff[i][a[i]]++;
	}
	for(i=1;i<n;i++){
		pref[i][0] += pref[i-1][0];
		pref[i][1] += pref[i-1][1];
	}
	for(i=n-2;i>=0;i--){
		suff[i][0] += suff[i+1][0];
		suff[i][1] += suff[i+1][1];
	}
	int ans = max(pref[n-1][0], pref[n-1][1]);
	ans = max(ans, max(suff[1][1], suff[1][0]));
	for(i=1;i<n;i++){
		ans = max(ans, pref[i-1][0] + suff[i][1]);
	}
	int k,l;

	for(i=0;i<n;i++){
		mid[i][i][a[i]][a[i]] = 1;
		mid[i][i][1][0] = 1;
	}

	for(i=1;i<n;i++){
		int awal = 0, akhir = awal + i;
		while(akhir < n){
			for(k=0;k<2;k++){
				for(l=1;l>=k;l--){
					mid[awal][akhir][l][k] = max(mid[awal][akhir-1][l][k] + (a[akhir] == k), mid[awal+1][akhir][l][k] + (a[awal] == l));
					if(awal == 0 && akhir == (n-1))
						ans = max(ans, mid[awal][akhir][l][k]);
					else if(awal == 0)
						ans = max(ans, mid[awal][akhir][l][k] + suff[akhir+1][l]);
					else if(akhir == (n-1))
						ans = max(ans, mid[awal][akhir][l][k] + pref[awal-1][k]);
					else
						ans = max(ans, pref[awal-1][k] + mid[awal][akhir][l][k] + suff[akhir+1][l]);
				}
			}
			awal++; akhir++;	
		}
		

	}

	
	printf("%d\n",ans);
	
	
	return 0;
};