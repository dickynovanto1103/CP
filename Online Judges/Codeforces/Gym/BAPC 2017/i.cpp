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

const int maxn = 1e2 + 2;

const int hitam = 0, putih = 1, pertama = 0, kedua = 1;

ii dp[maxn][maxn][2][2];

int main(){
	int n,m;
	int a[maxn][maxn];
	int i,j,k,l;
	scanf("%d %d",&n,&m);

	if(n==1){
		if(m%2==0){
			printf("2\n");
		}else{
			printf("1\n");
		}
	}else{
		if(n%2==0){
			printf("0\n");
		}else{
			if(m%2 == 1){
				printf("1\n");
			}else{
				if(n > m){
					printf("0\n");
				}else{
					printf("2\n");
				}
			}
		}
	}
	return 0;
};