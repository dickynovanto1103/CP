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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool valid[1000010];

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		memset(valid, true, sizeof valid);
		valid[k] = true;
		int i,j;
		for(i=k*2;i<=n;i+=k){
			// valid[i] = true;	
			for(j=2*i;j<=n;j+=i){
				valid[j] = false;
			}
		}
		int cnt = 0;
		for(i=k;i<=n;i+=k){
			if(valid[i]){cnt++;}
		}
		printf("%d\n",cnt);	
	}
	
	
	return 0;
};