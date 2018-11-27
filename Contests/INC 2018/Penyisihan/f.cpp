#include <bits/stdc++.h>
 
using namespace std;
 
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
 
int n,i,j,k,t;
vector<vi> AdjList;
set<char> v[1002];
char s[1000002];
 
vi match, vis;

int Aug(int node) {
	if(vis[node]){
		return 0;
	}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}


int main(){
	int q;
	scanf("%d %d", &n, &q);
	
	getchar();
	for(i=0;i<n;++i){
		bool ambil = true;
		char c;
		while((c = getchar()) != '\n'){
			if(c == ' ')
				ambil = true;
			else if(ambil){
				v[i].insert(c);
				ambil = false;
				// printf("yang diinsert di %d adalah %c\n",i,c);
			}

		}
	}
	while(q--){
		AdjList.assign(150,vi());
		scanf("%s", s);
		int len = strlen(s);
		if(len > n)
			puts("NO");
		else{
 			for(i=0;i<len;i++){
 				char kar = s[i];
 				for(j=0;j<n;j++){
 					if(v[j].count(kar)){
 						AdjList[j].pb(n+i);
 						// printf("kar: %c --> %d terhubung dengan: %d\n",kar,j,n+i);
 					}
 				}
 			}

 			int mcbm = 0;
			match.assign(n+len+2,-1);
			for(i=0;i<n;i++){
				vis.assign(n+len+2,0);
				mcbm+=Aug(i);
			}
			// printf("mcbm: %d\n",mcbm);
			if(mcbm == len){printf("YES\n");}
			else{printf("NO\n");}
		}
		AdjList.clear();
	}
	return 0;
}