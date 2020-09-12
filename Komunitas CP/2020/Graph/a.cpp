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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	vector<vi> out, in;
	scanf("%d",&n);
	out.assign(n+1, vi());
	in.assign(n+1, vi());
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		out[i].pb(a);
		in[a].pb(i);
	}

	for(i=1;i<=n;i++){
		int outDariI = out[i][0];
		if(out[outDariI].size() && in[i].size() && in[i][0] == out[outDariI][0]) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	
	return 0;
};