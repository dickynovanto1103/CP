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
	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		int loop = n/k;
		for(i=0;i<loop;i++){
			for(j=0;j<k;j++){
				printf("%c",j+'a');
			}
		}
		int sisa = n%k;
		for(i=0;i<sisa;i++){printf("%c",i+'a');}
		printf("\n");
	}
	return 0;
};