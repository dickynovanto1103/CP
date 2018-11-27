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
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	if(k==0){
		printf("%d\n",n); 
		for(i=1;i<=n;i++){
			if(i>1){printf(" ");}
			printf("%d",i);
		}
		printf("\n");
		return 0;
	}
	if(k>=n){printf("1\n1\n"); return 0;}
	int jangkauan = 2*k+1;
	int banyak = n/jangkauan + (n%jangkauan == 0 ? 0 : 1);
	printf("%d\n",banyak);
	if(n%jangkauan == 0){
		int awal = k+1;
		for(i=awal;i<=n;i+=(2*k+1)){
			if(i>awal){printf(" ");}
			printf("%d",i);
		}
		printf("\n");
		return 0;
	}
	if(n<=jangkauan){
		printf("%d\n",k+1);
		return 0;
	}
	int awal = k+1, akhir = n-k;
	int a1, a2, sisaAkhir;
	for(i=awal;i>=1;i--){
		for(j=akhir;j<=n;j++){

			int occupy1 = i + k;
			int occupy2 = n - j + 1 + k;
			// printf("i: %d j: %d\n",i,j);
			// printf("occupy1; %d occupy2: %d\n",occupy1,occupy2);
			int tot = occupy2 + occupy1;
			int sisa = n-tot;
			if(sisa < 0){continue;}
			if(sisa%jangkauan == 0){
				a1 = i, a2 = j;
				sisaAkhir = sisa;
				break;
			}
		}
	}
	vi listBil;
	listBil.pb(a1); listBil.pb(a2);

	for(i=2*k+1+a1;i<a2;i+=(2*k+1)){
		listBil.pb(i);
	
	}
	sort(listBil.begin(), listBil.end());
	for(i=0;i<listBil.size();i++){
		if(i){printf(" ");}
		printf("%d",listBil[i]);
	}
	printf("\n");
	return 0;

};