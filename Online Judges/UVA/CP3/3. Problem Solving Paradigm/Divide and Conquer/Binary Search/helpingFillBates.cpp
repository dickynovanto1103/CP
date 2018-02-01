#include <bits/stdc++.h>

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

vector<vi> AdjList;

int main() {
	string kata;
	int q, n,i,j;
	AdjList.assign(52,vi());
	int bil;
	
	cin>>kata;
	n = kata.length();

	for(i=0;i<n;i++){
		bil = kata[i];
		if(bil>=97){bil-=71;}
		else{bil-=65;}
		AdjList[bil].pb(i);
	}
	/*for(i=0;i<52;i++){
		printf("node: %d:",i);
		for(j=0;j<AdjList[i].size();j++){
			printf(" %d",AdjList[i][j]);
		}
		printf("\n");
	}*/
	cin>>q;
	string s;
	while(q--){
		cin>>s;
		int ukuran = s.length();
		int idx = 0, start, end;
		bool foundSalah = false;
		int idxKetemu;
		for(i=0;i<ukuran;i++){
			bil = s[i];
			if(bil>=97){bil-=71;}
			else{bil-=65;}
			//printf("idx: %d\n",idx);
			idxKetemu = lower_bound(AdjList[bil].begin(), AdjList[bil].end(), idx) - AdjList[bil].begin();
			//printf("kar: %c idxKetemu: %d\n",s[i],AdjList[bil][idxKetemu]);
			int ukuranAdj = AdjList[bil].size();
			//printf("ukuranAdj[%d]: %d\n",bil,ukuranAdj);
			if(idxKetemu>=ukuranAdj){//ga ketemu
				printf("Not matched\n"); break;
			}else{
				idx = AdjList[bil][idxKetemu]+1;
				if(!i){start = AdjList[bil][idxKetemu];}
			}
		}
		if(i==ukuran){printf("Matched %d %d\n",start,AdjList[bil][idxKetemu]);}
	}

	return 0;
}