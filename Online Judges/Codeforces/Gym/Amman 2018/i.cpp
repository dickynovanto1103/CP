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
	int tc,x,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&x,&n);
		if(x/n==0){
			printf("-1\n"); continue;
		}
		if(x%n==0){
			int hasilBagi = x/n;
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",hasilBagi);
			}
			printf("\n");
		}else{
			int hasilBagi = x/n;
			vi listBil;
			while(x%n!=0){
				listBil.pb(hasilBagi);
				x-=hasilBagi;
				n--;
			}
			int bagi = x/n;
			while(x>0){
				listBil.pb(bagi);
				x-=(bagi);
			}
			for(i=0;i<listBil.size();i++){
				if(i){printf(" ");}
				printf("%d",listBil[i]);
			}
			printf("\n");

		}
	}
	return 0;
};