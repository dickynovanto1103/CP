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

int a[55];

int median(int l, int r){
	//printf("l: %d r: %d\n",l,r);
	int selisih = r-l+1;
	if(selisih%2==1){
		return a[l+selisih/2];
	}else{
		return (a[l-1+selisih/2] + a[l+selisih/2])/2;
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	// printf("bil:\n");
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",a[i]);
	// }
	// printf("\n");
	int batastengah = (n-1)/2;
	if(n%2==1) {
		printf("%d\n%d\n%d\n",median(0,batastengah-1), median(0,n-1), median(batastengah+1,n-1));
	}else{
		printf("%d\n%d\n%d\n",median(0,batastengah), median(0,n-1), median(batastengah+1,n-1));
	}
	
	return 0;
};