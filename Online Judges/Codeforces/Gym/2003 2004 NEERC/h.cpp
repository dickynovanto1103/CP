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

const int maxn = 5e4 + 4;

int main(){
	freopen("highways.in", "r", stdin);
	freopen("highways.out", "w", stdout);
	int n,i,j;
	int a[maxn];
	int jarak[maxn];
	a[0] = 0;
	jarak[0] = 0;
	jarak[1] = 0;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=3){printf("0\n");}
	else{
		int minim = 2*inf;
		int s1,e1,s2,e2;
		for(i=2;i<=(n-2);i++){
			int jarak1 = a[n] - a[i];
			int jarak2 = a[i+1];
			int total = jarak1 + jarak2;
			// printf("i: %d\n", );
			if(total < minim){
				minim = total;
				s1 = i+1;
				e1 = 1;
				s2 = n;
				e2 = i;
			}

		}
		printf("%d\n", minim);
		printf("%d %d %d %d\n",s1,e1,s2,e2);
	}
	return 0;
};