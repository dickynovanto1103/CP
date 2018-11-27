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

ll tambah[500][500];

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int batas = (int)sqrt(n);
	ll arr[200010];
	memset(arr, 0, sizeof arr);
	while(q--){
		int i,j,a,b,c,idx;
		int com;
		scanf("%d",&com);
		if(com == 1){
			scanf("%d %d %d",&a,&b,&c);
			if(b < batas){
				tambah[a][b] += c;
			}else{ // lgsg tambahin..cuman sebanyak n

				for(i=a;i<=n;i+=b){
					arr[i] += c;
				}
			}
		}else{
			scanf("%d",&idx);
			ll ans = arr[idx];
			for(i=1;i<batas;i++){
				int hasilMod = idx%i;
				ans += tambah[hasilMod][i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
};