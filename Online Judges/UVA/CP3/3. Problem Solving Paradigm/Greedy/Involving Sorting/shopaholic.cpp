#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(int a, int b){return a > b;}

int main() {
	int tc,n,i,a[20010];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n,cmp);
		/*for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");*/
		i=2;
		int ans = 0;
		while(i<n){
			ans+=a[i];
			//printf("yang ditambah: a[%d]: %d\n",i,a[i]);
			i+=3;
		}
		printf("%d\n",ans);
	}
	return 0;
}