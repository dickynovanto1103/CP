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

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		char s[n+1][m+1];
		int row[n+1], col[m+1];
		memset(row, 0, sizeof row); memset(col, 0, sizeof col);
		for(i=0;i<n;i++){scanf("%s",s[i]);}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j] == '*'){row[i]++; col[j]++;}
			}
		}
		int tot = n+m;
		int ans = inf;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j] == '.'){
					int jum = row[i] + col[j];
					ans = min(ans, tot-jum-1);
				}else{
					int jum = row[i] + col[j];
					ans = min(ans, tot-jum);	
				}
				
			}
		}
		printf("%d\n",ans);
	}

	return 0;
};