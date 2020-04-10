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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	printf("Q %d ",n);
	for(i=1;i<=n;i++){//try if adding the space at the end, will it still AC?
		if(i > 1){printf(" ");}
		printf("%d",i);
	}
	printf("\n");
	fflush(stdout);

	int tot;
	scanf("%d",&tot);
	printf("Q %d ",n-1);
	for(i=2;i<=n;i++){
		if(i>2){printf(" ");}
		printf("%d",i);
	}
	printf("\n");
	fflush(stdout);

	int almost;
	scanf("%d",&almost);
	int a[1010];
	a[1] = tot - almost;
	int hampir = a[1];
	
	for(i=2;i<n;i++){
		printf("Q 2 %d %d\n",1, i);
		fflush(stdout);
		int berat;
		scanf("%d",&berat);
		a[i] = berat - a[1];
		hampir += a[i];
	}
	a[n] = tot - hampir;
	printf("A ");
	for(i=1;i<=n;i++){
		if(i > 1){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
};