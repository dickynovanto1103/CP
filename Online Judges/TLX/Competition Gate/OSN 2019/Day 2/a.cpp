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

const int maxn = 2e5 + 5;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[maxn], b[maxn];
	
	vi listStart, listEnd;
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		listStart.pb(a[i]);
		listEnd.pb(b[i]);
	}
	sort(listStart.begin(), listStart.end());
	sort(listEnd.begin(), listEnd.end());
	for(i=0;i<n;i++){
		int awal = a[i], akhir = b[i];
		int idxAkhir = upper_bound(listStart.begin(), listStart.end(), akhir) - listStart.begin();
		int idxAwal = upper_bound(listEnd.begin(), listEnd.end(), awal-1) - listEnd.begin();
		// printf("i: %d awal: %d akhir: %d idxAwal: %d idxAkhir: %d\n",i, awal, akhir, idxAwal, idxAkhir);
		printf("%d\n",idxAkhir - idxAwal-1);
	}
	return 0;
};