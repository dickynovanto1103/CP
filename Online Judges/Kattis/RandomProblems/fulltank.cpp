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
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 1e3 + 3;

vector<vii> AdjList;

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    AdjList.assign(maxn, vii());
    int a[maxn];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        AdjList[u].pb(ii(v,w));
        AdjList[v].pb(ii(u,w));
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int cap, u,v;
        scanf("%d %d %d",&cap,&u,&v);
        int dp[maxn][101];
        for(i=0;i<n;i++){
            for(j=0;j<=cap;j++){
                dp[i][j] = inf;
            }
        }

        priority_queue<iii, viii, greater<iii> > pq;
        if(u == v){
            printf("0\n"); continue;
        }
        dp[u][0] = 0;
        pq.push(iii(dp[u][0], ii(u, 0)));
        
        int ans = inf;
        while(!pq.empty()){
        	iii front = pq.top(); pq.pop();
        	int jarak = front.first, node = front.second.first, banyakBensinSekarang = front.second.second;
        	if(jarak > dp[node][banyakBensinSekarang]){continue;}
            //coba isi bensin
            if(banyakBensinSekarang < cap) {
                if(dp[node][banyakBensinSekarang+1] > dp[node][banyakBensinSekarang] + a[node]){
                    dp[node][banyakBensinSekarang+1] = dp[node][banyakBensinSekarang] + a[node];
                    pq.push(iii(dp[node][banyakBensinSekarang+1], ii(node, banyakBensinSekarang + 1)));
                }
            }
            //ke tetangga
            for(i=0;i<AdjList[node].size();i++){
                ii v = AdjList[node][i];
                int tetangga = v.first, berat = v.second;
                if(berat > banyakBensinSekarang){continue;}
                if(dp[tetangga][banyakBensinSekarang - berat] > dp[node][banyakBensinSekarang]){
                    dp[tetangga][banyakBensinSekarang - berat] = dp[node][banyakBensinSekarang];
                    pq.push(iii(dp[tetangga][banyakBensinSekarang - berat], ii(tetangga, banyakBensinSekarang - berat)));
                }
            }
        }

        for(i=0;i<=cap;i++){
        	ans = min(ans, dp[v][i]);
        }
        if(ans == inf){printf("impossible\n");}
        else{printf("%d\n",ans);}
    }
    return 0;
};