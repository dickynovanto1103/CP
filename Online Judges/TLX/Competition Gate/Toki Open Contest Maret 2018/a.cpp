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
	int n,i,j;
	int x[maxn],y[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	bool valid = true;
	for(i=0;i<(n-1);i++){
		if(x[i] == x[i+1] || y[i]==y[i+1]){
			continue;
		}else{
			valid = false; break;
		}
	}
	if(valid){
		printf("YA\n");
	}else{
		printf("TIDAK\n");
	}
	return 0;
};