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
	int n,i;
	scanf("%d",&n);
	if(n<=5){
		printf("-1\n");
		for(i=2;i<=n;i++){
			printf("%d %d\n",1,i);
		}
		return 0;
	}else{
		for(i=2;i<=4;i++){
			printf("%d %d\n",1,i);
		}
		for(i=5;i<=n;i++){
			printf("%d %d\n",2,i);
		}

		//seksi bisa
		for(i=2;i<=n;i++){
			printf("%d %d\n",1,i);
		}
	}
	return 0;
};