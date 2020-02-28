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

const int maxn = 1e5 + 5;

vector<int> adj[2];
int pref[2][maxn];

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	string s;
	cin>>s;
	bool isStart[maxn];
	
	memset(isStart, false, sizeof isStart);
	int cur = -1;
	int cnt = 0;
	for(i=0;i<n;i++){
		int bil = s[i] - '0';
		pref[bil][i] = 1;
		if(i > 0){
			pref[0][i] += pref[0][i-1];
			pref[1][i] += pref[1][i-1];
		}
		if(bil != cur) {
			if(cnt != 1) {
				adj[cur].pb(i-1);
			}
			isStart[i] = true;
			adj[bil].pb(i);
			cnt = 1;
		}else{
			cnt++;
		}
		cur = bil;
	}
	if(cnt != 1){
		adj[cur].pb(n-1);
	}
	if(pref[0][n-1] == 0 || pref[1][n-1] == 0){
		printf("tokitsukaze\n"); return 0;
	}
	bool canWin = false;
	//isi semua dengan 1 / 0
	for(i=0;i<=n-k;i++){
		for(j=0;j<2;j++){
			int tot = k;
			int sebelum = (i == 0 ? 0 : pref[j][i-1]);
			int setelah = pref[j][n-1] - pref[j][i+k-1];
			tot += sebelum;
			tot += setelah;
			if(tot == n){canWin = true; break;}	
		}
		if(canWin){break;}
		
	}
	
	if(canWin){printf("tokitsukaze\n");}
	else{
		bool canDraw = false;
		//cek ronde 2..kalo bs seri..print once again..otherwise quailty
		
		for(i=0;i<=n-k;i++){
			for(j=0;j<2;j++){
				int palingKiri = adj[j][0];
				int palingKanan = adj[j][adj[j].size()-1];
				
				if(palingKiri >= i && palingKiri <= (i+k-1)){
					int idxKiri = lower_bound(adj[j].begin(), adj[j].end(), i+k) - adj[j].begin();
					if(idxKiri == adj[j].size()){
						palingKiri = n-1;
					}else{
						palingKiri = adj[j][idxKiri];
					}
				}
				if(palingKanan >= 0 && palingKanan <= (i+k-1)) {
					int idxKanan = lower_bound(adj[j].begin(), adj[j].end(), i) - adj[j].begin();
					idxKanan--;
					if(idxKanan == -1){
						palingKanan = 0;
					}else{
						palingKanan = adj[j][idxKanan];
					}
				}
				int selisih = palingKanan - palingKiri + 1;
				if(selisih > k){
					canDraw = true;
					break;
				}
			}
			if(canDraw){break;}
		}	
		if(canDraw){
			printf("once again\n");
		}else{
			printf("quailty\n");
		}
	}
	return 0;
};