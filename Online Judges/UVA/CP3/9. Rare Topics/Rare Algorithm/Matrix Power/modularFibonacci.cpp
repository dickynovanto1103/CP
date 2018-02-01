#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll mod[25];
ll m;
const int maxn = 2;

struct Matrix{
	ll mat[maxn][maxn];
};

Matrix matMul(Matrix a, Matrix b){
	int i,j,k;
	Matrix ans;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			ans.mat[i][j] = 0;
			for(k=0;k<maxn;k++){
				ans.mat[i][j]+=a.mat[i][k] * b.mat[k][j];
				ans.mat[i][j]%=mod[m];
			}
		}
	}
	return ans;
}

Matrix identity;

Matrix matPow(Matrix a, ll b){
	if(b==0){return identity;}
	else{
		if(b%2==1){
			return matMul(a,matPow(a,b-1));
		}else{
			Matrix temp = matPow(a,b/2);
			return matMul(temp,temp);
		}
	}
}

int main() {
	ll n;
	
	
	ll i, j;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			identity.mat[i][j] = (i==j);
		}
	}
	mod[0] = 1;
	for(i=1;i<=20;i++){
		mod[i] = 2*mod[i-1];
		//printf("mod[%lld]: %lld\n",i,mod[i]);
	}
	Matrix awal;
	awal.mat[0][0] = 1; awal.mat[0][1] = 1;
	awal.mat[1][0] = 1; awal.mat[1][1] = 0;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		Matrix ans = matPow(awal,n);
		/*printf("awal:\n");
		for(i=0;i<maxn;i++){
			for(j=0;j<maxn;j++){
				if(j){printf(" ");}
				printf("%lld",awal.mat[i][j]);
			}
			printf("\n");
		}
		printf("hasil akhir:\n");
		for(i=0;i<maxn;i++){
			for(j=0;j<maxn;j++){
				if(j){printf(" ");}
				printf("%lld",ans.mat[i][j]);
			}
			printf("\n");
		}*/
		//printf("mod[%d]: %lld\n",m,mod[m]);
		printf("%lld\n", ans.mat[0][1]%mod[m]);
	}
	return 0;
}