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
	int tc,i,j;
	int n, v,l,r;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&n,&v,&l,&r);
		int banyak = n/v;
		int banyakSebelum = (l-1)/v;
		int banyakSesudah = r/v;
		int banyakAntara = banyakSesudah - banyakSebelum;
		int ans = banyak - banyakAntara;
		printf("%d\n",ans);
	}
	return 0;
};