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
	int n,m,i,j;
	scanf("%d %d",&n,&m);

	ii p[2010];
	int pas[2010];
	set<ii> s;
	for(i=1;i<=2*n;i++){
		scanf("%d",&p[i].first); p[i].second = i; s.insert(ii(p[i].first, p[i].second));
	}
	int a[1010],b[1010];
	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
		pas[a[i]] = b[i]; pas[b[i]] = a[i];
	}

	int turn;
	scanf("%d",&turn);
	if(turn==1){
		// pilih yang di pasangan itu terus...
		for(i=0;i<m;i++){
			
		}
	}
	return 0;
};