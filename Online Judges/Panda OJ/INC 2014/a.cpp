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
		scanf("%d",&n);
		int sum = 0;
		while(n--){
			int bil;
			scanf("%d",&bil);
			sum+=bil;
		}
		if(sum<=16000){
			printf("16GB\n");
		}else if(sum<=32000){
			printf("32GB\n");
		}else if(sum<=64000){
			printf("64GB\n");
		}else{
			printf("128GB\n");
		}
	}
	return 0;
};