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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j,n;
	int a[maxn];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int terakhir = n-2;
		for(i=0;i<n;i++){
			for(j=0;j<(n-2);j++){
				if(a[j] > a[j+2]){
					swap(a[j], a[j+2]);
					// printf("ditukar a[%d]:%d dan a[%d]: %d\n",j,a[j], j+2, a[j+2]);
					// printf("array sekarang\n");
					// for(int k=0;k<n;k++){
					// 	if(k){printf(" ");}
					// 	printf("%d",a[k]);
					// }
					// printf("\n");
				}
				// printf("i: %d j: %d\n",i,j);
			}
				
		}
		// printf("array akhir\n");
		// for(i=0;i<n;i++){
		// 	if(i){printf(" ");}
		// 	printf("%d",a[i]);
		// }
		// printf("\n");
		int idx = -1;
		for(i=0;i<(n-1);i++){
			if(a[i] > a[i+1]){idx = i; break;}
		}
		if(idx==-1){printf("OK\n");}
		else{printf("%d\n",idx);}

	}

	return 0;
};