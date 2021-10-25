/*if 1 says 2 is an impostor, if 1 is impostor, then 2 is crewmate
							  if 1 is crewmate, then 2 is impostor
  if 1 says 2 is a crewmate, if 1 is impostor, then 2 is impostor
  							 if 1 is crewmate, then 2 is crewmate
*/
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
#define impostor 1
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
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

const int maxn = 2e5 + 4;

vector<vii> out, in;

bool vis[maxn];
int col[maxn];

bool valid;

void dfs(int node, int colNow) {
	col[node] = colNow;
	if(!valid){
		return;
	}
	for(int i=0;i<out[node].size();i++){
		ii tt = out[node][i];
		int v = tt.first, isImpostor = tt.second;
		if(col[v] != -1) {
			//check apakah bener
			if(col[node] == impostor) {
				//if node = impostor, if(isImpostor), then col[v] should be crew
				//isImpostor = true, col[v] = crew, 
				if(col[v] == isImpostor) {
					valid = false;
					return;
				}
			}else{
				//if node = crewmate, then col[v] should be equal to isImpostor
				if(col[v] != isImpostor) {
					valid = false;
					return;
				}
			}
			continue;
		}

		//continue traverse
		dfs(v, col[node] == impostor ? !isImpostor : isImpostor);
	}

	for(int i=0;i<in[node].size();i++){
		ii tt = in[node][i];
		int v = tt.first, isImpostor = tt.second;
		if(col[v] != -1) {
			//check
			if(col[node] == impostor) {
				//if node == impostor, then if(isImpostor), then the one speaking is true, then v should be crewmate
				//isImpostor = true, col[v] = crew, isImpostor = false, col[v] = impostor
				if(isImpostor == col[v]){
					valid = false;
					return;
				}
			}else{
				//if node = crewmate, then if(isImpostor), then the one speaking is false, then v should be impostor
				//isImpostor = true, col[v] = impostor, isImpostor = false, col[v] = crew
				if(col[v] != isImpostor) {
					valid = false;
					return;
				}
			}
			continue;
		}

		dfs(v, col[node] == impostor ? !isImpostor: isImpostor);
	}
}

int cnt[2][maxn];

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);
		fill(col, col+n+1, -1);
		for (int i = 0; i < 2; ++i)
		{
			fill(cnt[i], cnt[i]+n+1, 0);
		}
		UnionFind UF(n+1);
		in.assign(n+1, vii()); out.assign(n+1, vii());

		for(i=0;i<m;i++){
			int a,b;
			char s[10];
			scanf("%d %d %s",&a,&b,s);
			UF.unionSet(a, b);
			
			out[a].pb(ii(b, s[0] == 'i' ? impostor: 0));
			in[b].pb(ii(a, s[0] == 'i' ? impostor: 0));
		}
		valid = true;
		for(i=1;i<=n;i++){
			if(col[i] == -1)
				dfs(i, impostor);
		}
		if(!valid){
			puts("-1");
			continue;
		}
		

		for(i=1;i<=n;i++){
			int category = UF.findSet(i);
			cnt[col[i]][category]++;
		}
		int ans = 0;
		for(i=1;i<=n;i++){
			ans += max(cnt[0][i], cnt[1][i]);
		}
		printf("%d\n", ans);
	}	
	
	return 0;
};