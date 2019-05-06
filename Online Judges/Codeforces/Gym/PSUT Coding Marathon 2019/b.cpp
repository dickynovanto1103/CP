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

vector<vi> AdjList;
const int maxn = 110;

vi match, vis;

int Aug(int node) {
	// printf("node: %d\n",node);
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[33], d[12];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++){
		scanf("%d",&d[i]);
	}

	sort(a, a+n);
	sort(d, d+10);
	int maks = 0;
	for(i=1;i<=10;i++){
		d[10] = i;
		AdjList.assign(maxn, vi());
		bool valid = true;
		for(j=0;j<n;j++){
			for(int k=0;k<=10;k++){
				if(d[k] <= a[j]){AdjList[j].pb(n+k);}
			}
			if(AdjList[j].size() == 0){valid = false; break;}
		}
		if(valid){maks = i;}

	}
	printf("%d\n",maks);
	return 0;
};