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

const int maxn = 4e3 + 3;

bool cmp(ii a, ii b){
	if(a.second == b.second) {
		if(a.second % 2 == 1){ //coba skenario turun ke bawah..nanti coba ke samping kanan
			return a.first < b.first;
		}else{
			return a.first > b.first;
		}
	}
	return a.second < b.second;
}

int v[maxn][maxn];

vii path;

int n;

void getPath(ii a, ii b){
	int x = a.first, y = a.second;
	path.pb(ii(x,y));
	while(ii(x, y)!=b){
		if(y % 2 == 1){ //ke kanan
			if(x == (n)){
				y++;
			}else{
				x++;
			}
			// printf("yang dipush: %d %d\n",x,y);
			path.pb(ii(x,y));
		}else{//ke kiri
			if(x == 1){
				y++;
			}else{
				x--;
			}
			// printf("yang dipush: %d %d\n",x,y);
			path.pb(ii(x,y));
		}
	}
}

int main(){
	int m,i,j;
	scanf("%d %d",&n,&m);

	ii pas[maxn];
	for(i=0;i<2*m;i++){
		scanf("%d %d",&pas[i].first, &pas[i].second);
	}
	sort(pas, pas+2*m, cmp);
	// for(i=0;i<2*m;i++){
	// 	printf("%d %d\n",pas[i].first, pas[i].second);
	// }
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++){
			scanf("%d",&v[i][j]);
		}
	}

	for(i=0;i<2*m;i+=2){
		ii koor1 = pas[i], koor2 = pas[i+1];
		// printf("koor1: %d %d koor2: %d %d\n",koor1.first,koor1.second,koor2.first,koor2.second);
		//jalan
		path.clear();
		getPath(koor1, koor2);
		int ukuran = path.size();
		printf("%d",ukuran);
		for(j=0;j<ukuran;j++){
			printf(" %d %d",path[j].first, path[j].second);
		}
		printf("\n");
	}
	return 0;
};