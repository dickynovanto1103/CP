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
	int tc,i,j;
	scanf("%d",&tc);
	int a[10010];
	a[1] = 1; a[2] = 2; a[3] = 4;
	while(tc--){
		int n;
		scanf("%d",&n);
		if(n <= 3){printf("%d\n",a[n]);}
		else{
			int selisih = n-3;
			int bil = 4 + selisih*3;
			printf("%d\n", bil);
		}
	}
	return 0;
};