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

int sum(int n){
	int ans = 0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	return ans;
}

bool isvisited[10000];

int main(){
	int n,i;
	memset(isvisited, false, sizeof isvisited);
	int maks = 0;
	scanf("%d",&n);
	vi ans;
	for(i=1;i<=81;i++){
		int bil = n-i;
		if(sum(bil)==i){
			//printf("bil: %d i: %d\n",bil,i);
			ans.pb(bil);
		}
	}
	printf("%d\n",ans.size());
	for(i=ans.size()-1;i>=0;i--){
		printf("%d\n",ans[i]);
	}

	return 0;
};