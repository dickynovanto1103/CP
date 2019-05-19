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

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	AdjList.assign(110, vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		// if(a > b){swap(a,b);}
		AdjList[a].pb(b); AdjList[b].pb(a);
	}

	vector<deque<ii> > listPos;
	listPos.assign(110, deque<ii>());
	int x = 1;
	for(i=1;i<=n;i++){
		int banyak = AdjList[i].size() + 2;
		for(j=0;j<banyak;j++){
			listPos[i].pb(ii(x++,i));
		}
	}

	for(i=1;i<=n;i++){
		int idxBelakang = listPos[i].size()-1;
		for(j=0;j<AdjList[i].size();j++){
			int v = AdjList[i][j];
			if(v < i){continue;}
			//ambil back dari listPos v...lalu taruh di paling belakang 
			ii back = listPos[v].back(); listPos[v].pop_back();
			ii depan = listPos[i][idxBelakang];
			int x = depan.first;
			listPos[v].push_front(ii(x, v));
			idxBelakang--;
		}
	}

	for(i=1;i<=n;i++){
		int ukuran = listPos[i].size();
		printf("%d\n",ukuran);
		for(j=0;j<ukuran;j++){
			printf("%d %d\n",listPos[i][j].first,listPos[i][j].second);
		}
	}

	return 0;
};