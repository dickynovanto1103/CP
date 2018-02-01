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
	int n,k;
	int i,j;
	int a[110];
	scanf("%d %d",&n,&k);
	int maks = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(k%a[i]==0){maks = max(maks,a[i]);}
	}
	printf("%d\n",k/maks);
	return 0;
};