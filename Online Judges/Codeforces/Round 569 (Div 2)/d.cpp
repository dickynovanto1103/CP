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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int rowAkhir = n;
	for(i=1;i<=n/2;i++){
		if(rowAkhir < i){
			break;
		}else{
			int colAkhir = m;
			for(j=1;j<=m;j++){
				printf("%d %d\n%d %d\n",i,j,rowAkhir, colAkhir);
				colAkhir--;
			}
		}
		rowAkhir--;
	}
	if(rowAkhir == i){
		int colAkhir = m;
		
		for(j=1;j<=m/2;j++){
			printf("%d %d\n%d %d\n",i,j,rowAkhir, colAkhir);
			colAkhir--;
		}
		if(colAkhir == j){printf("%d %d\n",rowAkhir,colAkhir); return 0;}
	}
	return 0;
};