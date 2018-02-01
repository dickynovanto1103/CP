/*#include <bits/stdc++.h>

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

vector<vii> AdjList;
vi dist, parent, ts,dfs_num;
void PrintPath(int i){
	if(parent[i]==i){printf("%d",i+1); return;}
	PrintPath(parent[i]);
	printf(" %d",i+1);
}

int main() {
	int n,i,j,k,d,a[31][11];
	while(scanf("%d %d",&n,&d)!=EOF){
		AdjList.assign(n,vii());
		dist.assign(n,-inf);
		vi indegree(n,0);
		for(i=0;i<n;i++){
			for(j=0;j<d;j++){
				scanf("%d",&a[i][j]);
			}
			sort(a[i],a[i]+j);
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i!=j){
					for(k=0;k<d;k++){
						if(a[i][k] >= a[j][k]){break;}
					}
					if(k==d){AdjList[i].pb(ii(j,1)); indegree[j]++;}
				}
			}
		}
		queue<int> q;
		for(i=0;i<n;i++){
			if(indegree[i]==0){q.push(i); dist[i] = 0;}
		}
		while(!q.empty()){
			int front = q.front(); q.pop();
			ts.pb(front);
			for(i=0;i<AdjList[front].size();i++){
				ii v = AdjList[front][i];
				if(--indegree[v.first]==0){
					q.push(v.first);
				}
			}
		}

		for(i=0;i<n;i++){parent.pb(i);}//parent dr dirinya adalah dirinya...awal

		for(i=0;i<ts.size();i++){
			int node = ts[i];
			if(dist[node]!=-inf){
				for(j=0;j<AdjList[node].size();j++){
					ii v = AdjList[node][j];
					if(dist[v.first] < dist[node] + 1){
						dist[v.first] = dist[node] + 1;
						parent[v.first] = node;
					}
				}
			}
		}
		
		

		int maks = 0, nodeMaks;
		for(i=0;i<n;i++){
			if(maks < dist[i]){
				maks = dist[i];
				nodeMaks = i;
			}
		}
		//printf("\n\n");
		printf("%d\n",maks+1);
		PrintPath(nodeMaks);
		printf("\n");
		AdjList.clear(); dist.clear(); parent.clear(); ts.clear(); dfs_num.clear();
	}
	return 0;
}*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int k, n;
    int A[30][10];
    while(scanf("%d %d", &k, &n) == 2) {
        int i, j, l;
        int map[30][30] = {}, bmap[30][30] = {};
        for(i = 0; i < k; i++) {
            for(j = 0; j < n; j++)
                scanf("%d", &A[i][j]);
            sort(A[i], A[i]+n);
        }
        int indeg[30] = {};
        for(i = 0; i < k; i++) {
            for(j = 0; j < k; j++) {
                for(l = 0; l < n; l++) {
                    if(A[i][l] >= A[j][l])
                        break;
                }
                if(l == n) {
                    map[i][j] = 1, indeg[j]++, bmap[j][i] = 1;
                } else
                    map[i][j] = 0, bmap[j][i] = 0;
            }
        }
        int dp[30] = {}, sour[30] = {}, used[30] = {};
        while(1) {
            for(i = 0; i < k; i++) {
                if(indeg[i] == 0 && used[i] == 0) {
                    int mm = -1, mi = -1;
                    for(j = 0; j < k; j++) {
                        if(bmap[i][j] == 1) {
                            if(dp[j] > mm)
                                mm = dp[j], mi = j;
                        }
                    }
                    mm++;
                    used[i] = 1, dp[i] = mm;
                    sour[i] = mi;
                    for(j = 0; j < k; j++) {
                        if(map[i][j] == 1 && used[j] == 0)
                            indeg[j]--;
                    }
                    break;
                }
            }
            if(i == k)  break;
        }
        int mm = -1, mi = -1;
        for(i = 0; i < k; i++)
            if(dp[i] > mm)
                mm = dp[i], mi = i;
        printf("%d\n", mm+1);
        int ans[30], at = -1;
        do {
            ans[++at] = mi;
            if(dp[mi] == 0) break;
            mi = sour[mi];
        } while(1);
        for(i = at; i >= 0; i--)
            printf("%s%d", i != at ? " " : "", ans[i]+1);
        puts("");
    }
    return 0;
}