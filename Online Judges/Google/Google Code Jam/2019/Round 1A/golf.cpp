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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n,m;
	scanf("%d %d %d",&tc,&n,&m);
	while(tc--){
		int maks = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<18;j++){
				if(j){printf(" ");}
				printf("18");
			}
			printf("\n");
			fflush(stdout);
			int sum = 0;
			for(j=0;j<18;j++){
				int angka;
				cin>>angka;
				sum += angka;
			}
			if(sum > m){continue;}
			else{maks = max(maks, sum);}
		}
		printf("%d\n",maks);
		fflush(stdout);
		int ver;
		scanf("%d",&ver);
		if(ver == -1){return 0;}
	}
	return 0;
};