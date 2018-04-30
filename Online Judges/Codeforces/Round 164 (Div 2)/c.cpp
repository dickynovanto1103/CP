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

int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,1,-1};
int n,m;

bool isValid(ii a) {
	if(a.first == 0 && a.second == 0){return false;}
	return a.first>=0 && a.first<=n && a.second>=0 && a.second <= m;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	int maksUkuran = 0;
	ii start;
	vii ans;
	for(i=0;i<4;i++){
		vii listAns;
		if(i==0){start = ii(n,m);}
		else if(i==1){start = ii(n,0);}
		else if(i==2){start = ii(0,0);}
		else{start = ii(m,0);}

		// printf("i: %d start awal: %d %d\n",i,start.first, start.second);
		if(isValid(start)){listAns.pb(start);}
		while(true){
			start.first+=dx[i]; start.second+=dy[i];
			if(isValid(start)){
				// printf("start jd: %d %d\n",start.first, start.second);
				listAns.pb(start);
			}
			else{break;}
		}
		if(maksUkuran < listAns.size()) {
			maksUkuran = listAns.size();

			ans = listAns;
		}
	}
	printf("%d\n",maksUkuran);
	for(i=0;i<maksUkuran;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}

	return 0;
};