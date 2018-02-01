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

int main() {
	string kata[25];
	int n,m,tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		//printf("n: %d m: %d\n",n,m);
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		//cari di tiap kolom..catat nomernya
		vi nomor;
		bool found = true, foundpagar;
		for(j=0;j<m;j++){
			foundpagar = false;
			for(i=0;i<n;i++){
				if(kata[i][j]=='#'){foundpagar = true; nomor.pb(i); break;}
			}
			if(!foundpagar){found = false; break;}
		}
		if(found){
			//cek list nomor
			for(i=0;i<nomor.size()-1;i++){
				int sekarang = nomor[i], next = nomor[i+1];
				if(abs(sekarang-next)>1){printf("TIDAK KENA\n"); break;}
			}
			if(i==nomor.size()-1){printf("KENA\n");}
		}else{
			printf("TIDAK KENA\n");
		}
		
	}
	return 0;
}