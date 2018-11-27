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
	int tc,n;
	ll i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;;i++){
			
			if(((i*i) % n) == 0){
				int banyak = i*i / n;
				int cnt = 0;
				char kar = 'a';
				printf("%lld\n",i);
				for(j=0;j<i;j++){
					for(int k=0;k<i;k++){
						printf("%c",kar);
						cnt++;
						if(cnt == banyak){
							cnt = 0;
							kar++;
						}
					}
					printf("\n");
				}
				break;
			}
		}
	}
	return 0;
};