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

int p[200010];

void back(int n){
	if(n == 1){printf("1 "); return;}
	while(n!=1){
		back(p[n]);
		printf("%d ",n);
		return;
	}

}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	p[1] = -1;
	for(i=2;i<=n;i++){
		scanf("%d",&p[i]);
	}
	back(n);
	printf("\n");
	return 0;
};