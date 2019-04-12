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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[maxn][maxn];
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int ans = 0;
		for(i=0;i<n-1;i++){
			multiset<int> s;
			multiset<int>::iterator it;
			for(j=0;j<m;j++){
				s.insert(a[i][j]);
			}
			for(j=0;j<m;j++){
				it = s.find(a[i+1][j]);
				// printf("cari a[%d][%d]: %d\n",i+1,j,a[i+1][j]);
				if(it != s.end()){
					ans++;
					// printf("ans jd: %d\n",ans);
					s.erase(it);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};