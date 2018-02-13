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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	int a[maxn];
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		int sisa = n-k;
		int minim = a[n-1] - a[0];
		for(i=0;i<n;i++){
			j = i+sisa-1;
			if(j>=n){break;}
			minim = min(minim,a[j] - a[i]);
		}
		printf("%d\n",minim);
	}
	return 0;
};