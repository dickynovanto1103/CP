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

const int maxn = 1001;
int counter[maxn][maxn];

void solve(int a, int b){
	int i,j;
	//ke kanan bawah
	j = b+1;
	for(i=a+1;i<maxn;i++){
		counter[i][j]++;
		j++;
		if(j>=maxn){break;}
	}
	//ke kiri atas
	j = b-1;
	for(i=a-1;i>=1;i--){
		counter[i][j]++;
		j--;
		if(j<1){break;}
	}
	//ke kanan atas
	j = b+1;
	for(i=a-1;i>=1;i--){
		counter[i][j]++;
		j++;
		if(j>=maxn){break;}
	}
	//ke kiri bawah
	j = b-1;
	for(i=a+1;i<maxn;i++){
		counter[i][j]++;
		j--;
		if(j<1){break;}
	}
}

int main(){
	int n,i,j,a,b;
	scanf("%d",&n);
	ll ans = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		ans+=counter[a][b];
		counter[a][b]++;
		solve(a, b);
	}
	printf("%lld\n",ans);
	return 0;
};