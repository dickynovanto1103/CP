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

const int maxn = 2e5 + 5;

vector<vi> zebra, almostZebra;
vi listIdxZebra, listIdxAlmostZebra;

int main(){
	string kata;
	int i,n;
	cin>>kata;
	n = kata.length();
	zebra.assign(n+1, vi()); almostZebra.assign(n+1, vi());
	for(i=0;i<n;i++){
		char kar = kata[i];
		// printf("i: %d\n",i);
		if(kar=='0'){
			// printf("kar 0 -->");
			if(listIdxAlmostZebra.empty()){
				listIdxZebra.pb(i); //ketambahan yang baru
				zebra[i].pb(i); almostZebra[i].pb(i);
				// printf("kepush: %d\n",i);
			}else{
				//ambil dari almost zebra
				
				int idx = listIdxAlmostZebra.back(); listIdxAlmostZebra.pop_back();
				// printf("ambil dari almostZebra dengan idx: %d\n",idx);
				zebra[idx].pb(i); almostZebra[idx].pb(i);
				listIdxZebra.pb(idx);
				// printf("dipush ke zebra[%d] dan almostZebra[%d]\n",idx,idx);
			}
		}else{
			if(listIdxZebra.empty()){
				printf("-1\n"); return 0;
			}else{
				// printf("kar 1 --> ");
				//ambil idxTerakhir
				int idx = listIdxZebra.back(); listIdxZebra.pop_back();
				// printf("ambil idxTerakhir idx: %d ",idx);
				zebra[idx].pb(i); almostZebra[idx].pb(i);
				// printf("dipush ke zebra[%d] dan almostZebra[%d]\n",idx,idx);
				listIdxAlmostZebra.pb(idx);
				// printf("dipush ke listIdxAlmostZebra: %d\n",i);
			}
		}
	}
	if(listIdxAlmostZebra.size()!=0){printf("-1\n"); return 0;}
	int j;
	// printf("nilai zebra\n");
	// for(i=0;i<8;i++){
	// 	printf("node %d: ",i);
	// 	for(j=0;j<zebra[i].size();j++){
	// 		printf(" %d",zebra[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("nilai almostzebra\n");
	// for(i=0;i<8;i++){
	// 	printf("node %d: ",i);
	// 	for(j=0;j<almostZebra[i].size();j++){
	// 		printf(" %d",almostZebra[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("%d\n",(int)listIdxZebra.size());
	for(i=0;i<listIdxZebra.size();i++){
		int idx = listIdxZebra[i];
		printf("%d",(int)zebra[idx].size());
		for(int j=0;j<zebra[idx].size();j++){
			printf(" %d",zebra[idx][j]+1);
		}
		printf("\n");
	}
	return 0;
};