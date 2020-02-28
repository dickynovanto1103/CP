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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int i,j;
	int bil = -1;
	bool normal[n + m + 1];
	memset(normal, false, sizeof normal);
	if(n < m){
		for(i=1;i<=n;i++) {
			printf("? 1 %d\n",i);
			fflush(stdout);
			int banyak;
			scanf("%d",&banyak);
			int angka;
			for(j=0;j<banyak;j++){
				scanf("%d",&angka);
			}
			if(banyak == 0 || banyak > 1){
				bil = i;
			}else{
				normal[angka] = true;
			}
		}	
	}else{
		for(i=n+1;i<=n+m;i++) {
			printf("? 1 %d\n",i);
			fflush(stdout);
			int banyak;
			scanf("%d",&banyak);
			int angka;
			for(j=0;j<banyak;j++){
				scanf("%d",&angka);
			}
			if(banyak == 0 || banyak > 1){
				bil = i;
			}else{
				normal[angka] = true;
			}
		}	
	}

	if(bil == -1){
		if(n < m){
			for(i=n+1;i<=n+m;i++){
				if(!normal[i]){
					bil = i; break;
				}
			}
		}else{
			for(i=1;i<=n;i++){
				if(!normal[i]){
					bil = i; break;
				}
			}
		}
	}
	printf("! %d\n",bil);
	fflush(stdout);
	return 0;
};