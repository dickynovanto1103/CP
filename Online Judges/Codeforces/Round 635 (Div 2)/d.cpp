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

const int maxn = 1e5 + 5;

vector<vii> adj[3][3];

void generate(int a[maxn], int b[maxn], int n, int m, int idx1, int idx2) {
	int i,j;
	for(i=0;i<n;i++){
		int bil = a[i];
		//get 2 closest from b and c
		int idx11 = upper_bound(b, b+m, bil) - b;
		if(idx11 == m){idx11--;}
		int idx22 = lower_bound(b, b+m, bil) - b;
		if(idx22 == m){idx22--;}
		if(b[idx22] > bil){
			idx22--;
			if(idx22 < 0){idx22++;}
		}
		adj[idx1][idx2][i].pb(ii(idx11, idx22));
	}
}

int findSisa(int a, int b){
	int bil[] = {0, 1, 2};
	for(int i=0;i<3;i++){
		if(a != bil[i] && b != bil[i]){return bil[i];}
	}

	assert(false);
	return -1;
}

int n, m, k;

int getPanjang(int i) {
	if(i == 0){return n;}
	else if(i == 1){return m;}
	else{return k;}
}

int a[3][maxn];

ll getVal(int a, int b, int c){
	ll satu = ((ll)(a-b))*((ll)(a-b));
	ll dua = ((ll)(a-c))*((ll)(a-c));
	ll tiga = ((ll)(c-b))*((ll)(c-b));
	return satu + dua + tiga;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d %d",&n,&m,&k);

		for(i=0;i<n;i++){scanf("%d",&a[0][i]);}
		for(i=0;i<m;i++){scanf("%d",&a[1][i]);}
		for(i=0;i<k;i++){scanf("%d",&a[2][i]);}
		sort(a[0],a[0]+n); sort(a[1],a[1]+m); sort(a[2],a[2]+k);
		
		//get 2 shortest of a number
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(i == j){continue;}
				int panjang = getPanjang(i);
				adj[i][j].assign(panjang+1, vii());
			}
		}


		// adjAB.assign(n+1, vi()); adjBC.assign(m+1, vi()); adjCA.assign(k+1, vi());
		// adjAB.assign(n+1, vi()); adjBC.assign(m+1, vi()); adjCA.assign(k+1, vi());
		generate(a[0], a[1], n, m, 0, 1);
		generate(a[1], a[0], m, n, 1, 0);
		generate(a[0], a[2], n, k, 0, 2);
		generate(a[2], a[0], k, n, 2, 0);
		generate(a[1], a[2], m, k, 1, 2);
		generate(a[2], a[1], k, m, 2, 1);


		ll ans = (ll)inf*(ll)inf*(ll)2;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(i != j){
					int sisa = findSisa(i, j);
					int panjang = getPanjang(i);
					for(int l=0;l<panjang;l++){
						assert(adj[i][j][l].size() != 0);
						ii pas = adj[i][j][l][0];
						int satu = pas.first, dua = pas.second;
						ii pasSatu = adj[j][sisa][satu][0];
						ii pasDua = adj[j][sisa][dua][0];

						int satusatu = pasSatu.first, satudua = pasSatu.second;
						int duasatu = pasDua.first, duadua = pasDua.second;
						// printf("l: %d satu: %d pasSatu: %d %d dua: %d pasDua: %d %d\n",l, satu, satusatu, satudua, dua, duasatu, duadua);
						ans = min(ans, getVal(a[i][l], a[j][satu], a[sisa][satusatu]));
						ans = min(ans, getVal(a[i][l], a[j][satu], a[sisa][satudua]));
						ans = min(ans, getVal(a[i][l], a[j][dua], a[sisa][duasatu]));
						ans = min(ans, getVal(a[i][l], a[j][dua], a[sisa][duadua]));
					}
				}
			}
		}

		printf("%lld\n",ans);

	}
	
	return 0;
};