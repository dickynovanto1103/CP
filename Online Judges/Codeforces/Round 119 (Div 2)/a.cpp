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

int n,a,b,c;

int main(){
	scanf("%d %d %d %d",&n,&a,&b,&c);
	int maks = 0;
	int i,j;
	for(i=0;i<=4000;i++){
		int hasil1 = i*a;
		if(hasil1 > n){break;}
		for(j=0;j<=4000;j++){
			int hasil = hasil1 + j*b;
			if(hasil > n){break;}
			int selisih = n - hasil;
			if(selisih % c == 0){
				int k = selisih / c;
				maks = max(maks, i+j+k);
			}
		}
	}
	
	printf("%d\n",maks);
	return 0;
};