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

int main(){
	int n,i,j;
	scanf("%d",&n);
	vector<vi> AdjList;

	AdjList.assign(110, vi());
	vii listEdge;
	for(i=1;i<=n;i++){
		int ga = n - i;
		if(n % 2 == 0){ga++;}
		for(j=i+1;j<=n;j++){
			if(j == ga){continue;}
			listEdge.pb(ii(i,j));
		}
	}
	printf("%d\n",(int)listEdge.size());
	for(i=0;i<listEdge.size();i++){
		printf("%d %d\n",listEdge[i].first,listEdge[i].second);
	}

	return 0;
};