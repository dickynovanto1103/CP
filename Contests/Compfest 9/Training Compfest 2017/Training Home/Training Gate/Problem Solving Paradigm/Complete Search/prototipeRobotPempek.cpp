#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,m,k,q;
	int i,j;
	string kata[1010];
	vector<ii> pas;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(i=0;i<n;i++){cin>>kata[i];}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='X'){pas.pb(ii(i,j));}
		}
	}
	while(q--){
		int a,b;
		int jarak = inf;
		scanf("%d %d",&a,&b); a--; b--;
		for(i=0;i<k;i++){jarak = min(jarak,abs(pas[i].first-a) + abs(pas[i].second - b));}
		printf("%d\n",jarak);
	}
	return 0;
}