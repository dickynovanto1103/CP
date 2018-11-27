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

const int maxn = 1e4 + 4;
int a[maxn];

int main(){
	int tc,k,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		int cntLebih1 = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] > 1){cntLebih1++;}
		}
		if(cntLebih1 <= k){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};