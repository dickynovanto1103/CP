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

int a[1000001];
vi ans;

int main(){
	int n,i,j;
	string s[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){cin>>s[i];}
	int dist[101][101];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i == j){dist[i][j] = 1;}
			else{
				if(s[i][j] == '1'){
					dist[i][j] = 1;
				}else{
					dist[i][j] = inf;	
				}	
			}
		}
	}
	int k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int path;
	scanf("%d",&path);
	for(i=0;i<path;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	ans.pb(a[0]);
	int node = a[0];
	int jarak = 1;
	for(i=1;i<(path);i++){
		if(dist[node][a[i]] == jarak) {
			jarak++;
		}else{
			ans.pb(a[i-1]);
			node = a[i-1];
			i--;
			jarak = 1;
		}
	}
	ans.pb(a[path-1]);
	int pjg = ans.size();
	printf("%d\n",pjg);
	for(i=0;i<pjg;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]+1);
	}
	printf("\n");

	return 0;
};