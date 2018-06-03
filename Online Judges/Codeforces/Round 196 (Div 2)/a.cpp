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
	int n,m,i,j;
	int a[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){scanf("%d",&a[i]);}
	sort(a,a+m);
	int minim = inf;
	for(i=0;i<=(m-n);i++){
		minim = min(minim, a[i+n-1] - a[i]);
	}
	printf("%d\n",minim);
	return 0;
};