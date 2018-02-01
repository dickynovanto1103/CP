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
bool isLeaf[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+10,vi()); 
	memset(isLeaf,false,sizeof isLeaf);

	for(i=1;i<n;i++){
		int parent;
		scanf("%d",&parent);
		AdjList[parent].pb(i+1);
	}
	for(i=1;i<=n;i++){
		if(AdjList[i].size()==0){isLeaf[i] = true;}
	}
	for(i=1;i<=n;i++){
		if(!isLeaf[i]){
			//cek anak"nya
			int cnt = 0;
			for(j=0;j<AdjList[i].size();j++){
				int v = AdjList[i][j];
				if(isLeaf[v]){
					cnt++;
					if(cnt>=3){break;}
				}
			}
			if(cnt<3){printf("No\n"); return 0;}

		}
	}
	printf("Yes\n");
	return 0;
};