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
typedef set<int> si;

vector<si> Adj1;
vector<vi> Adj2;

const int maxn = 1e5 + 5;

int main(){
	int n,k,q,i,j;
	scanf("%d %d %d",&n,&k,&q);
	Adj1.assign(n+1,si()); Adj2.assign(n+1,vi());
	for(i=0;i<k;i++){
		int banyak = 0;
		scanf("%d",&banyak);
		for(j=0;j<banyak;j++){
			int orang;
			scanf("%d",&orang);
			Adj1[i].insert(orang); Adj2[orang].pb(i);
		}

	}
	while(q--){
		int banyak = 0;
		scanf("%d",&banyak);
		int orang[maxn];
		int cnt = 0;
		for(i=0;i<banyak;i++){
			scanf("%d",&orang[i]);
			int men = orang[i];
			//masuk grup mana saja orang ini
			for(j=0;j<Adj2[men].size();j++){
				int grup = Adj2[men][j];
				if(Adj1[grup].find(men) == Adj1[grup].end()) {
					continue;
				}else{
					Adj1[grup].erase(men);
					if(Adj1[grup].empty()){
						cnt++;
					}
				}
			}
		}
		for(i=0;i<banyak;i++){
			int men = orang[i];
			for(j=0;j<Adj2[men].size();j++){
				int grup = Adj2[men][j];
				Adj1[grup].insert(men);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
};