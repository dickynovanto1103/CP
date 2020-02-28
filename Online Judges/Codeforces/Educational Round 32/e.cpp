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

int a[36];

vi listBil[2];
int m;
int ans = 0;

void process(int idx, int awal, int akhir) {
	int n = akhir - awal + 1;
	// printf("awal: %d akhir: %d\n",awal, akhir);
	// printf("n: %d\n",n);
	int i,j;
	for(i=0;i<(1<<n);i++){
		int sum = 0;
		for(j=0;j<n;j++){
			if((1<<j) & i){
				sum += a[j + awal];
				sum %= m;
			}
		}
		ans = max(ans, sum);
		listBil[idx].pb(sum);
		debug printf("ke idx: %d dipush: %d\n",idx, sum);
	}
	sort(listBil[idx].begin(), listBil[idx].end());
}

int main(){
	int n,i,j;
	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i] %= m;
		// printf("a[%d]: %d\n",i,a[i]);
	}
	if(n == 1){
		printf("%d\n",a[0]%m);
		return 0;
	}

	process(0,0,n/2-1);
	process(1,n/2,n-1);
	for(i=0;i<listBil[0].size();i++){
		int bil = listBil[0][i];
		int selisih = m-1-bil;
		debug printf("bil: %d selisih: %d\n",bil,selisih);
		int ukuran = listBil[1].size();
		int idx = lower_bound(listBil[1].begin(), listBil[1].end(), selisih) - listBil[1].begin();
		if(idx == ukuran){
			idx--;
		}else{
			if(listBil[1][idx] == selisih){

			}else{
				idx--;
			}
		}
		debug printf("idx: %d ditambah %d\n",idx,listBil[1][idx]);
		ans = max(ans, (bil + listBil[1][idx])%m);

	}
	
	printf("%d\n", ans);
	return 0;
};