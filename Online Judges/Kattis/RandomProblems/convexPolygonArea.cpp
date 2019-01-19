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

int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);

	while(tc--){
		vii listBil;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			listBil.pb(ii(a,b));
		}
		listBil.pb(listBil[0]);
		int luas = 0;
		for(i=0;i<n;i++){
			luas += listBil[i].first*listBil[i+1].second;
			luas -= listBil[i].second*listBil[i+1].first;
		}
		if(luas % 2 == 1) {
			printf("%d.5\n",luas/2);
		}else{
			printf("%d\n",luas/2);
		}
	}
	return 0;
};