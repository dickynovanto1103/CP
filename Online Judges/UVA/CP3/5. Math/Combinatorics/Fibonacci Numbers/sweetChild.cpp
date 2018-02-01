#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[800],i;
	while(scanf("%d",&n),(n!=-1)){
		for(i=1;i<=n;i++){a[i] = i;}
		int cnt = 0;
		do{
			bool found = true;
			for(i=1;i<=n;i++){
				if(a[i]==i){found = false; break;}
			}
			if(!found){continue;}
			cnt++;
			/*for(i=1;i<=n;i++){
				if(i>1){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");*/
		}while(next_permutation(a+1,a+n+1));
		printf("cnt: %d\n",cnt);
	}
	return 0;
}