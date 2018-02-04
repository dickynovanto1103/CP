#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define 
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int cnt[256]; 
vector<vi> AdjList;

int main(){
	int n,m,i,j;
	string kata;
	scanf("%d %d",&n,&m);
	cin>>kata;
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
	}
	//cek ada cycle apa ngga
	for(i=0;i<n;i++)
	return 0;
};