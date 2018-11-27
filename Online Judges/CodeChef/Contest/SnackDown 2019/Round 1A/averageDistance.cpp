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
	int tc,i,j,n,m;
	scanf("%d",&tc);
	ii listPair[310*310];
	while(tc--){
		string kata[310];
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){cin>>kata[i];}
		int cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j] == '1'){
					listPair[cnt++] = ii(i,j);
				}
			}
		}
		int counter[600];
		memset(counter, 0, sizeof counter);
		for(i=0;i<cnt;i++){
			for(j=i+1;j<cnt;j++){
				int jarak = abs(listPair[i].first - listPair[j].first) + abs(listPair[i].second - listPair[j].second);
				// printf("jarak: %d\n",jarak);
				// printf("bandingin antara (%d,%d) dan (%d,%d)\n",listPair[i].first,listPair[i].second,listPair[j].first,listPair[j].second);
				counter[jarak]++;
			}
		}
		for(i=1;i<=(n+m-2);i++){
			if(i>1){printf(" ");}
			printf("%d",counter[i]);
		}
		printf("\n");
	}
	return 0;
};