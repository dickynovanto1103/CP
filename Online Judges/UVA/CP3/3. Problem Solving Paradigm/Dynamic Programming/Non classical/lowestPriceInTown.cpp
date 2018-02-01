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

double hargaSatu,harga[21];
int n,banyak[21];
double memo[22][101];
double solve(int id, int w){
	if(id==n+1){return inf;}
	if(w<=0){return 0;}
	if(memo[id][w]!=-1.0){return memo[id][w];}
	return memo[id][w] = min(solve(id+1,w),harga[id] + solve(id,w-banyak[id]));
}

int main() {
	int test=1;
	int i,j;
	while(scanf("%lf %d",&hargaSatu,&n)!=EOF){
		printf("Case %d:\n",test++);
		banyak[0] = 1; harga[0] = hargaSatu;
		for(i=1;i<=n;i++){scanf("%d %lf",&banyak[i],&harga[i]);}
		string kata;

		getline(cin>>ws,kata);
		//cout<<"kata: "<<kata<<endl;
		int ukuran = kata.length();
		int bil=0, cnt = 0;
		memset(memo,-1,sizeof memo);
		for(i=0;i<22;i++){
			for(j=0;j<101;j++){
				memo[i][j] = -1.0;
			}
		}
		double ans;
		for(i=0;i<ukuran;i++){
			if(kata[i]==' '){

				ans = solve(0,bil);
				printf("Buy %d for $%.2lf\n",bil,ans);
				bil=0;
			}
			else{bil*=10; bil+=kata[i]-48;}
		}
		ans = solve(0,bil);
		printf("Buy %d for $%.2lf\n",bil,ans);

	}
	return 0;
}