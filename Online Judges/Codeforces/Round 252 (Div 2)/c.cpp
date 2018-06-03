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
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	int banyak = (n*m) / k;
	bool isKhusus = false;
	int banyakTerakhir = -1;
	if((n*m)%k!=0){
		banyakTerakhir = (n*m) - banyak*(k-1);
		isKhusus = true;
	}
	// printf("banyakTerakhir: %d\n",banyakTerakhir);
	int x = 1, y = 1;
	bool keKanan = true;
	for(i=0;i<k;i++){
		if(i==(k-1)){
			if(isKhusus){
				banyak = banyakTerakhir;	
			}
		}
		printf("%d ",banyak);
		for(j=0;j<banyak;j++){
			if(j){printf(" ");}
			printf("%d %d", x,y);
			if(keKanan){
				if(y==m){
					x++; keKanan = false;
				}else{
					y++;
				}
			}else{
				if(y==1){
					x++; keKanan = true;
				}else{
					y--;
				}
			}
		}
		printf("\n");
	}
	return 0;
};