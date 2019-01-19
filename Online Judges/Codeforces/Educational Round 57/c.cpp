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

const int maxn = 2e6 + 5;
int ans[maxn];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	fill(ans, ans+maxn, inf);
	for(i=3;i<=1000;i++){
		ll maksSudut = ((i-2)*180)/i;
		for(j=1;j<=(i-2);j++){
			if((j*180)%i == 0){
				int sudut = j*180/i;
				ans[sudut] = min(ans[sudut], i);
			}
		}
		
	}
	while(tc--){
		int n;
		scanf("%d",&n);
		if(ans[n] == inf){printf("-1\n");}
		else{printf("%d\n",ans[n]);}
		
	}
	return 0;
};