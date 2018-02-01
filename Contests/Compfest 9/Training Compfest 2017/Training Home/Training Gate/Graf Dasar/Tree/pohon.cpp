#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

int getNumberOfLeaf(int node){
	if(AdjList[node].size()==0){return 1;}
	int ans = 0;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		ans+=getNumberOfLeaf(v);
	}
	return ans;
}

int getTinggi(int node){
	if(AdjList[node].size()==0){return 0;}
	int ans = 0;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		ans = max(ans,1+getTinggi(v));
	}
	return ans;
}

int main() {
	int n,i;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=1;i<=n-1;i++){
		int a;
		scanf("%d",&a); AdjList[a].pb(i+1);
	}
	printf("%d %d\n",getNumberOfLeaf(1), getTinggi(1));

	return 0;
}