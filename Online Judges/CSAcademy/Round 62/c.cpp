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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
const int maxn = 1010;
bool isVisited[maxn];

int tujuan;

int banyakJalan(int node){
	int i,j;
	int ans = 0;
	for(i=0;i<AdjList[node].size();i++){

	}
}
bool isSimple(int node){
	int i,j;
	int jumlahBisa = 0;
	isVisited[false]
	for(i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(can(v)){jumlahBisa++;}
		if(jumlahBisa>1){return false;}
	}

	return true;
}

int main(){
	int n,m,i,j,q;
	scanf("%d %d %d",&n,&m,&q);
	AdjList.assign(n+1,vi());
	int bil1,bil2;
	for(i=0;i<m;i++){scanf("%d %d",&bil1,&bil2); AdjList[bil1].pb(bil2); AdjList[bil2].pb(bil1);}
	for(i=0;i<q;i++){
		int awal;
		scanf("%d %d",&awal,&tujuan);
		bool ans = isSimple(awal);
	}
	return 0;
};