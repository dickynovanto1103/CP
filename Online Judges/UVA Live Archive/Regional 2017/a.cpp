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
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[10];
	while(tc--){
		for(i=0;i<7;i++){
			scanf("%d",&a[i]);
		}
		int angkaAkhir = a[6];
		int maks;
		int minimBil = inf;
		for(i=0;i<6;i++){
			minimBil = min(minimBil, a[i]);
		}
		if(minimBil>=angkaAkhir){printf("DATA IS BIAS!\n"); continue;}
		int pembilang = (angkaAkhir - minimBil )*100;
		maks = pembilang / minimBil;
		maks = (pembilang + minimBil - 1)/minimBil;
		// if(pembilang % minimBil != 0){

		// }
		if(maks <= 0) {printf("DATA IS BIAS!\n");}
		else{printf("%d%% INCREASE!\n",maks);}
	}
	return 0;
};