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

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m) != EOF){
		char vs[n][m];
		for(i=0;i<n;i++){
			scanf("%s", vs[i]);
		}

		vi pref(m+1);

		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				if(vs[i-1][j] == 'X' && vs[i][j-1] == 'X'){pref[j] = 1;}
			}
		}

		for(i=1;i<m;i++) pref[i] += pref[i-1];

		int q;
		scanf("%d", &q);
		while(q--){
			int a,b;
			scanf("%d %d",&a,&b);
			a--; b--;
			int banyak = pref[b] - pref[a];
			// printf("a: %d b: %d banyak: %d banyakKiri: %d\n",a, b, banyak, banyakKiri);
			if(banyak){
				puts("NO");
			}else{
				puts("YES");
			}
		}
	}

	


	
	return 0;
};