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

ll fac[21];

ll c(int a, int b){
	return fac[a] / (fac[b] * fac[a-b]);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	fac[0] = 1;
	for(i=1;i<=10;i++){
		fac[i] = (ll)i*fac[i-1];
	}
	while(tc--){
		int r,s,x,y,w;
		scanf("%d %d %d %d %d",&r,&s,&x,&y,&w);
		int banyakAtas = s-r+1;
		double totalUang = 0;
		for(i=x;i<=y;i++){
			ll kombinasi = c(y,i);
			double peluang = 1;
			for(j=0;j<i;j++){
				peluang *= ((double)banyakAtas/(double)s);
			}
			int selisih = y - i;
			for(j=0;j<selisih;j++){
				peluang *= (1.0-((double)banyakAtas/(double)s));
			}
			totalUang += peluang*(double)kombinasi*(double)w;
		}
		if(totalUang > 1.0){printf("yes\n");}
		else{printf("no\n");}

	}
	return 0;
};