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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll cntPairWithDist[100010];
int distFrom[2][100001];
vector<vector<int>> adj;
ll additions[100010];

class Solution {
public:
	int n;

	void resetAdditions(int n) {
		for(int i=0;i<=n;i++){
			additions[i] = 0;
		}
	}

    vector<long long> countOfPairs(int n, int x, int y) {
    	this->n = n;
    	adj.assign(n + 1, vi());
        for(int i=1;i<=n;i++){
        	cntPairWithDist[i] = (n-i) * 2;
        }

        if(x == y) {
        	vector<ll> ans;
        	for(int i=1;i<=n;i++){
        		ans.pb(cntPairWithDist[i]);
        	}

        	return ans;
        }

        resetAdditions(n);
        resetDist(n);
        if(x > y) {swap(x, y);}
        buildGraph(n, x, y);
       	bfs(x, 0);
       	bfs(y, 1);

       	// for(int i=0;i<2;i++){
       	// 	for(int j=1;j<=n;j++){
       	// 		printf("distFrom[%d][%d]: %d\n", i,j,distFrom[i][j]);
       	// 	}
       	// }

       	for(int i=1;i<=n;i++){
       		//hitung brp yang harus dikurangin, berapa yang harus ditambahin, pake teknik Tony mungkin
       		printf("i: %d x: %d y: %d\n", i, x, y);
       		if(i <= x) {
       			findMinIdxInRightThroughIdx(i, 0);
       			
       		}else if(i >= y) {
       			//find maks idx lewat x initial dist > dist now
       			findMaxIdxInLeftThroughIdx(i, 1);
       			
       		}else{
       			//in between
       			findMaxIdxInLeftThroughIdx(i, 0);
       			findMinIdxInRightThroughIdx(i, 1);
       		}
       	}

       	for(int i=1;i<=n;i++){
       		additions[i] += additions[i-1];
       		printf("additions[%d]: %d\n", i, additions[i]);
       	}

       	vector<ll> ans;
       	for(int i=1;i<=n;i++){
       		ll cntNow = (ll)cntPairWithDist[i] + additions[i];
       		assert(cntNow >= 0);
       		ans.pb(cntNow);
       	}

       	return ans;
    }

    void findMaxIdxInLeftThroughIdx(int i, int idx) {
    	//find maks idx lewat x initial dist > dist now
		int kiri = 1, kanan = i - 1, mid, ansNode = -1;
		while(kiri <= kanan) {
			mid = (kiri + kanan) / 2;
			int initialDist = i - mid;
			// printf("in binser\n");
			int dist = getDistLewatXOrY(i, mid, idx);
			if(initialDist > dist) {
				ansNode = mid;
				kiri = mid + 1;
			}else{
				kanan = mid - 1;
			}
		}

		printf("find max idx in left, i: %d idx: %d, ansNode: %d\n", i, idx, ansNode);

		if(ansNode != -1) {
			//pengurangan cnt
			// printf("in pengurangan cnt, additions[%d]-- and additions[%d]++\n", i - ansNode, i);
			additions[i - ansNode]--;
			additions[i - 1 + 1]++;
			printf("pengurangan cnt, additions[%d]--, additions[%d]++\n", i - ansNode, i);
			//penambahan cnt
			// printf("in penambahan cnt");

			additions[getDistLewatXOrY(i, ansNode, idx)]++;
			additions[getDistLewatXOrY(i, 1, idx) + 1]--;
			printf("penambahan cnt, additions[%d]++, additions[%d]--\n", getDistLewatXOrY(i, ansNode, idx), getDistLewatXOrY(i, 1, idx) + 1);
		}
    }

    void findMinIdxInRightThroughIdx(int i, int idx) {
    	//find min idx dimana initial dist > dist now
		int kiri = i + 1, kanan = n, mid, ansNode = -1;
		while(kiri <= kanan) {
			mid = (kiri + kanan) / 2;
			int initialDist = mid - i;
			// printf("in binser\n");
			int dist = getDistLewatXOrY(i, mid, idx);
			if(initialDist > dist) {
				ansNode = mid;
				kanan = mid - 1;
			}else{
				kiri = mid + 1;
			}
		}

		printf("find min idx in right, i: %d idx: %d ansNode: %d\n", i, idx, ansNode);
		if(ansNode != -1) {
			//pengurangan cnt
			// printf("in pengurangan cnt, additions[%d]-- and additions[%d]++\n", ansNode - 1, n -i + 1);
			additions[ansNode - i]--;
			additions[n - i + 1]++;
			printf("pengurangan cnt, additions[%d]--, additions[%d]++\n", ansNode - i, n - i + 1);
			//penambahan cnt
			// printf("in penambahan cnt\n");
			additions[getDistLewatXOrY(i, ansNode, idx)]++;
			additions[getDistLewatXOrY(i, n, idx) + 1]--;
			printf("penambahan cnt, additions[%d]++, additions[%d]--\n", getDistLewatXOrY(i, ansNode, idx), getDistLewatXOrY(i, n, idx) + 1);
		}
    }

    int getDistLewatXOrY(int a, int b, int idx) {
    	int ans = distFrom[idx][a] + distFrom[idx][b];
    	// printf("dist from a: %d to b: %d through idx: %d is: %d\n", a, b, idx, ans);
    	return ans;
    }

    void resetDist(int n) {
		for(int i=0;i<2;i++){
        	for(int j=0;j<=n;j++){
        		distFrom[i][j] = -1;
        	}
        }
    }

    void buildGraph(int n, int x, int y) {
		for(int i=1;i<n;i++){
        	adj[i].pb(i+1);
        	adj[i+1].pb(i);
        }
        adj[x].pb(y);
        adj[y].pb(x);
    }

    void bfs(int node, int idx) {
    	queue<int> q;
    	q.push(node);
    	distFrom[idx][node] = 0;
    	while(!q.empty()) {
    		int cur = q.front(); q.pop();
    		for(int i=0;i<adj[cur].size();i++){
    			int v = adj[cur][i];
    			if(distFrom[idx][v] == -1) {
    				distFrom[idx][v] = distFrom[idx][cur] + 1;
    				q.push(v);	
    			}
    		}
    	}
    }
};

int main(){
	Solution s;
	int n, x, y;
	while(scanf("%d %d %d",&n,&x,&y) != EOF) {
		vector<long long> res = s.countOfPairs(n, x, y);
		printf("result:");
		for(long long a : res) {
			printf(" %lld", a);
		}

		puts("");
	}
};