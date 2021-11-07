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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int a[maxn];
bool dihapus[maxn];
int pref[maxn];
vi bisa;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&n);
		fill(pref, pref+n+1, 0);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] % (i+1) != 0){
				pref[i] = 1;
			}
			pref[i] += pref[i-1];
		}

		bool can = true;
		for(i=1;i<=n;i++){
			int bil = a[i];
			if(bil % (i+1) == 0){
				//cari brp banyak step yang perlu
				int perlu = -1;
				for(j=i-1;j>=1;j--){
					if(bil % (j+1) != 0){
						perlu = i - j;
						break;
					}
				}
				if(perlu == -1){can = false; break;}
			}
		}

		can ? puts("YES"): puts("NO");
	}
	
	return 0;
};