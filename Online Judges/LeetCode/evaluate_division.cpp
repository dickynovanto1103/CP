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
typedef pair<int,double> id;
typedef vector<id> vid;
typedef vector<ii> vii;

class UnionFind{
private: 
	vi rank,p,setSize;
	int numset,i;
public:
	UnionFind(int n){
		numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
		for(i=0;i<n;i++){p[i]=i;}
	}

	int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			numset--;
			int x=findSet(i), y=findSet(j);
			if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
			else{
				p[x]=y;
				setSize[y]+=setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	int numDisjointSet(){return numset;}
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

class Solution {
public:
	void solve(vector<vid>& adj, int node) {
		for(int i=0;i<adj[node].size();i++){
			int v = adj[node][i].first;

			if(vis[v]) {
				continue;
			}

			double value = adj[node][i].second;
			vis[v] = true;
			//node / v = value
			val[v] = val[node] / value;
			solve(adj, v);
		}
	}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    	map<string, int> mapper;
    	int cntSt = 0;
    	UnionFind UF(equations.size() * 2);

        for(int i=0;i<equations.size();i++){
        	string a = equations[i][0], b = equations[i][1];
        	if(mapper.find(a) == mapper.end()) {
        		mapper[a] = cntSt++;
        	}

        	if(mapper.find(b) == mapper.end()) {
        		mapper[b] = cntSt++;
        	}

        	int idxA = mapper[a], idxB = mapper[b];
        	UF.unionSet(idxA, idxB);
        }


        vector<vid> adj;
        adj.assign(cntSt + 1, vid());
        
        for(int i=0;i<values.size();i++){
        	string a = equations[i][0], b = equations[i][1];
        	int idxA = mapper[a], idxB = mapper[b];

        	adj[idxA].pb(id(idxB, values[i]));
        	adj[idxB].pb(id(idxA, 1.0/values[i]));
        }

        memset(vis, false, sizeof vis);

        for(int i=1;i<=cntSt;i++){
        	if(!vis[i]) {
        		vis[i] = true;
        		val[i] = 10;
        		solve(adj, i);
        	}
        }

        vector<double> ans;

        for(int i=0;i<queries.size();i++){
        	string a = queries[i][0], b = queries[i][1];
        	if(mapper.find(a) == mapper.end() || mapper.find(b) == mapper.end()) {
        		ans.pb(-1.0);
        		continue;
        	}

        	int idxA = mapper[a], idxB = mapper[b];

        	if(!UF.isSameSet(idxA, idxB)) {
        		ans.pb(-1.0);
        		continue;
        	}

        	ans.pb(val[idxA] / val[idxB]);
        }

        return ans;
    }

private:
	bool vis[41];
	double val[41];

};

int main(){
	int n, q;
	while(cin>>n>>q) {
		vector<vector<string>> equations, queries;
		vector<double> values;
		for(int i=0;i<n;i++){
			string a,b;
			cin>>a>>b;
			vector<string> v;
			v.pb(a); v.pb(b);
			equations.pb(v);
		}

		for(int i=0;i<n;i++){
			double v;
			cin>>v;
			values.pb(v);
		}

		for(int i=0;i<q;i++){
			string a,b;
			cin>>a>>b;
			vector<string> v;
			v.pb(a); v.pb(b);
			queries.pb(v);
		}

		Solution sol;
		vector<double> answers = sol.calcEquation(equations, values, queries);
		for(double d: answers) {
			printf("%lf ", d);
		}
		puts("");
	}
	
	return 0;
};