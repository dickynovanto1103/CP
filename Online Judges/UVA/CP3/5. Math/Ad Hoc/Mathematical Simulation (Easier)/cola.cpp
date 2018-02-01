#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i;
	while(scanf("%d",&n)!=EOF){
		int sisa, ans = -inf;
		for(i=0;i<=3;i++){
			sisa = i;
			int total = 0, ada = n;
			//printf("i: %d\n",i);
			while(true){
				//printf("masuk\n");
				total+=ada; sisa+=ada;
				if(sisa/3==0){break;}
				//printf("total jd: %d\n",total); printf("sisa: %d\n",sisa);
				ada = sisa/3;//dapet gratis 1 botol tiap 3 botol kosong
				sisa%=3;
				//printf("sisa sekarang: %d\n",sisa);

			}
			if(sisa>=i){ans = max(ans,total);}
		}
		printf("%d\n",ans);	
	}
	
	return 0;
}