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
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		int bil;
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			scanf("%d",&bil);
		}
		if(n%2==0){
			printf("0\n");
		}else{
			printf("1\n0.0\n");
		}
	}
	return 0;
};