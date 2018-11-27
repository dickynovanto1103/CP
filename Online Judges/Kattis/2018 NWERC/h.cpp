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

const int maxn = 5e5 + 5;
int a[maxn];
bool isRusak[maxn];

int getIdxRight(int idx){
	int bil;
	for(int i = idx; i>=1; i--){
		if(!isRusak[i]){bil= i; break;}
	}
	return bil;
}

int main(){
	int n,c,b,i,j;
	scanf("%d %d %d",&n,&c,&b);
	memset(isRusak, false, sizeof isRusak);
	for(i=0;i<b;i++){
		int idx;
		scanf("%d",&idx);
		isRusak[idx] = true;
	}

	for(i=1;i<=n;i++){
		a[i] = 0;
	}

	if(c == 1){
		a[1] = 1;
		for(i=1;i<=n;i++){printf("%d",a[i]);}
		printf("\n");
		return 0;
	}

	for(i=n-1;i>=1;i-=2){
		// printf("i: %d\n",i);
		if(c == 1){
			a[1] = 1;
			for(j=1;j<=n;j++){printf("%d",a[j]);}
			printf("\n");
			return 0;		
		}else if(c == 0){
			for(j=1;j<=n;j++){printf("%d",a[j]);}
			printf("\n");
			return 0;
		}else{
			if(isRusak[i]) {
				int idx = getIdxRight(i);
				
				a[idx] = 1;
				i = idx;
				c-=2;
			}else{
				a[i] = 1;
				c-=2;
			}
		}
		
	}
	if(c > 0){assert(false);}
	for(i=1;i<=n;i++){printf("%d",a[i]);}
	printf("\n");
	return 0;
};